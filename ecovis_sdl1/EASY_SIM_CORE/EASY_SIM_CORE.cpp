/*
 * EASY_SIM_CORE.cpp
 *
 *  Created on: 02.06.2015
 *      Author: Christian Berth
 */

#include <stdlib.h>

#include "EASY_SIM_CORE.h"
#include <math.h>

#define PI 3.1415926535
#define SIZE_QUEUE 1000
#define DEGREES 0.0174532925

float Engine1RPM = 0.0f;
int iTestTimer = 0;
int iFunctionTimer = 0;
float FunctionVariation = 0;
int v2 = 0;     // v2 in the range 1 to 100

const int GraphLength = 800;
float fStickPitchCmd_Value[4][GraphLength];
float fElevator_Pos[4][GraphLength];
float fTimeScale_Value[4][GraphLength];
float fZ_Elevation[GraphLength];
int iScaleStep = 0;

int DirectionSwitch = 0;

TimeFrame* currentFrame;
bool frameToDelete = false;

float fscale = 0.001f;

double m = 60000.0; //Mass in kg
double g = -9.81; //Earth acceleration in m/s�
double dt = 0.020; //Time Step Width in s -> NOT USED
double wingArea = 600.0; //Area of the wings m^2
double airDensity = 1.200; //f(T,p) normally kg/m^3
double ascentAviationCoefficient = 5.5;
double startAviationCoefficient = 0.3;
double maxAngleOfAttack = 20 * DEGREES;
double totalLossAngle = 25 * DEGREES;
double dragCoefficientFriction = 0.02;
double dragCoefficientFormMin = 0.09;
double dragCoefficientFormMax = 1.8;
double oswaldNumber = 0.7;
double wingSpan = 60;
double rotationRate = 0.01;
double maxThrust = 5000000.0;


//TODO: instead of a constant, create a function
double ground = 0.0;

StaticDequeue<pair<double,double>, SIZE_QUEUE> queue = StaticDequeue<pair<double, double>, SIZE_QUEUE>(true);
Camera camera;

double EASY_SIM_CORE::calculate_drag(double coefficient) {
	return 0.5 * airDensity * currentFrame->get_speed_squared() * coefficient * wingArea;
}

EASY_SIM_CORE::EASY_SIM_CORE(int DisplayWidth, int DisplayHeight, TimeFrame* startValues)
{
	//INIT----------------------------------------------
	font0 = new Font("Font/LiberationSans-Bold.ttf",12);
	font1 = new Font("Font/LiberationSans-Bold.ttf",16);
	font2 = new Font("Font/LiberationSans-Bold.ttf",18);
	font3 = new Font("Font/LiberationSans-Bold.ttf",20);
	font4 = new Font("Font/LiberationSans-Bold.ttf",28);

	RSprite1 = new RectSprite(0.2,0.2,0.8,0.8, 0);

	//given by main.cpp
	timediff = 0;
	extdt = 0;
	TimeSys = 0;
	rotate = 0;

	reset(startValues);

	camera = Camera(1000,1000,currentFrame->x0, currentFrame->z0);
	crashed = false;
	
	for(int GN=0; GN <= 3; GN++)
	{
		for(int Count=0; Count <= GraphLength-1; Count++)
		{
	   		fTimeScale_Value[GN][Count] = 0.0f;
			fStickPitchCmd_Value[GN][Count]= 0.0f;
			fElevator_Pos[GN][Count]= 0.0f;
		}
	}

	Time = 0;
}

void EASY_SIM_CORE::reset(TimeFrame* startValues) {
	if (frameToDelete && currentFrame != nullptr) {
		delete(currentFrame);
	}
	crashed = false;
	if (startValues == nullptr) {
		currentFrame = new TimeFrame();
		//add some value so something happens
		currentFrame->x1 = 100.0;
		currentFrame->z0 = 1000.0;
		frameToDelete = true;
	} else {
		currentFrame = startValues; 
		frameToDelete = false;
	}
}

EASY_SIM_CORE::~EASY_SIM_CORE() 
{
	//DELETE--------------------------------------------
	delete(font0);
	delete(font1);
	delete(font2);
	delete(font3);
	delete(font4);

	delete(RSprite1);
	if (frameToDelete) delete(currentFrame);
}

void EASY_SIM_CORE::CalcEASY_SIM_CORE()
{
	double z0dt;
	double z1dt;
	double x0dt;
	double x1dt;

	dt = extdt;
	//Differential Equation Calculation for x and z axis
	//z2 = g + Fa/m + Fr/m;
	double directionOfSpeed = currentFrame->get_direction_of_speed();
	//swap directions!
	double angleOfAttack = currentFrame->direction - directionOfSpeed;//no wind yet
	double aviationCoefficient = ascentAviationCoefficient * angleOfAttack + startAviationCoefficient;
	if (angleOfAttack >= maxAngleOfAttack) {
		double alpha = (angleOfAttack - maxAngleOfAttack) / totalLossAngle;
		if (alpha > 1) {
			alpha = 1;
		}
		//angleOfAttack -= angleOfAttack * alpha;
		aviationCoefficient -= aviationCoefficient * alpha;
	}
	aviationCoefficient = 0 > aviationCoefficient ? 0 : aviationCoefficient;
	double trueAirSpeedSquared = currentFrame->get_speed_squared();
	double lift = 0.5 * airDensity * trueAirSpeedSquared * aviationCoefficient * wingArea;

	double wingAspectRatio = wingSpan * wingSpan / wingArea;
	double dragCoefficientInduced = aviationCoefficient * aviationCoefficient / (PI * oswaldNumber * wingAspectRatio);
	double dragCoefficientParasitic = dragCoefficientFriction + dragCoefficientFormMin + dragCoefficientFormMax * (sin(angleOfAttack) + 1) * 0.5;

	double resultThrust = maxThrust;// -this->calculate_drag(dragCoefficientInduced);
	double parasiticDrag = this->calculate_drag(dragCoefficientParasitic);

	currentFrame->z2 = g + cos(currentFrame->direction) * lift / m + sin(currentFrame->direction) * resultThrust / m -sin(directionOfSpeed) * parasiticDrag / m;
	currentFrame->z1 = currentFrame->z1 + currentFrame->z2 * dt;
	z0dt = currentFrame->z1*dt;
	currentFrame->z0 = currentFrame->z0 + z0dt;

	currentFrame->x2 = -sin(currentFrame->direction) * lift / m + cos(currentFrame->direction) * resultThrust / m -cos(directionOfSpeed) * parasiticDrag / m;
	currentFrame->x1 = currentFrame->x1 + currentFrame->x2 * dt;
	x0dt = currentFrame->x1*dt;
	currentFrame->x0 = currentFrame->x0 + x0dt;

	queue.push_front(pair<double,double>(currentFrame->x0, currentFrame->z0));
	camera.setFocusPoint(currentFrame->x0, currentFrame->z0);
	if (currentFrame->z0 < ground) crashed = true;
	
	currentFrame->time = currentFrame->time + dt;

	currentFrame->direction += rotate * rotationRate;
	if (currentFrame->direction < -PI) {
		currentFrame->direction += 2 * PI;
	}else if(currentFrame->direction > PI) {
		currentFrame->direction -= 2 * PI;
	}

	//save some data into the frame
	currentFrame->forceLift = lift;
	currentFrame->forceTotalThrust = resultThrust;
	currentFrame->forceDragForm = parasiticDrag;
	currentFrame->AoA = angleOfAttack;
}

void EASY_SIM_CORE::draw()
{
	iTestTimer++;
	iFunctionTimer++;
	
	if(iFunctionTimer < 2500)
	{
		FunctionVariation = FunctionVariation + 0.02f;
	}
	if(iFunctionTimer > 2500 && FunctionVariation > 0.0f)
	{
		FunctionVariation = FunctionVariation - 0.02f;
	}
	if(iFunctionTimer > 5000)
	{
		iFunctionTimer = 0;
		FunctionVariation = 0.0f;
	}
	
	if(Engine1RPM < 500.0f && DirectionSwitch == 0)
	{
		Engine1RPM++;
	}
	if(Engine1RPM == 500.0f) 
	{
		DirectionSwitch = 1; // + FunctionVariation;
	}
	if(Engine1RPM > 0.0f && DirectionSwitch == 1)
	{
		Engine1RPM--;
	}
	if(Engine1RPM == 0.0f) 
	{
		DirectionSwitch = 0; // + FunctionVariation;
	}
	
	
	/*
	glBegin(GL_LINES);
			glVertex2f(0.5,0.5);
			glVertex2f(0.5,0);
	glEnd();
	*/

	//RSprite1->setThicness(2.0);
	//RSprite1->setColor(0.5,0.5,1.0,1);
	//RSprite1->draw();

	glColor3ubv(magenta0);
	
	
	/*glBegin(GL_QUADS);
   		glVertex2f(0.0, 0.0);
   		glVertex2f(0.0, 0.3);
   		glVertex2f(0.4, 0.3);
   		glVertex2f(0.6, 1.0);
	glEnd();*/


	//AC BOX
	glPushMatrix();
 //   //glRotatef(0,0,0,1);
 //   //glTranslatef(0.2+(Engine1RPM*0.0001),0.2,0);
	pair<double, double> position = camera.getRelativePosition(queue.front());
	////+0.1 and +0.5 instead of +0.3 like in the camera
	glTranslatef(position.first,position.second,0);
 //   drawOpenBox(0.01,0.01);      // -10 deg Rollmark
	drawLine(0.05,currentFrame->direction*180 /  PI);
	//Draw Force Vectors (lift, thrust, parasiticDrag)
	//currentFrame->z2 = - sin(directionOfSpeed) * parasiticDrag * 0.01;
	//currentFrame->x2 = - cos(directionOfSpeed) * parasiticDrag * 0.01;
	glColor3ubv(amber_0);
	drawLine(0,0,-sin(currentFrame->direction) * 0.05,cos(currentFrame->direction) * 0.05);
	glColor3ubv(white);
	drawLine(0, 0, cos(currentFrame->direction) * 0.05, sin(currentFrame->direction) * 0.05);
	glColor3ubv(green);
	drawLine(0, 0, -cos(currentFrame->get_direction_of_speed()) * 0.05, -sin(currentFrame->get_direction_of_speed()) * 0.05);
	glPopMatrix();
	//glPushMatrix();
	//glColor3ubv(white);
	//glBegin(GL_POINTS);
	//glVertex2f(position.first, position.second);
	//glEnd();
 //   glPopMatrix();

	{
		pair<double, double> position;
		
			glColor3ubv(white);
			glBegin(GL_POINTS);
			for(int count=0; count < queue.size(); count++)
				{
					position = camera.getRelativePosition(queue[count]);
   					glVertex2f(position.first, position.second);
					
				}
			glEnd();
		
		}
	


	float x, y;

	//Graph##############################################################
 //   glPushMatrix();
	//int GraphNr = 1;
 //   /*glPushAttrib(GL_CURRENT_BIT);*/
	//const float fXScFactor = 2.0f;
	//const float fYScFactor = 0.05f;
	////Scale X Axis & Y Axis
	//	glColor3ubv(green);
	//	glTranslatef(0.1,0.5,0);
	//	glScalef(0.001,0.001,0.001);
	//	glBegin(GL_LINES);

	//		//x-axis
	//		/*glVertex2f(0, 0);
	//		glVertex2f(800, 0);*/

	//		//z-axis
	//		/*glVertex2f(0, 400);
	//		glVertex2f(0, -400);*/

	//		//top and bottom
	//		/*glColor3ubv(white);
	//		glVertex2f(0, 400);
	//		glVertex2f(800, 400);

	//		glVertex2f(0, -400);
	//		glVertex2f(800, -400);*/
	//	glEnd();

	//	fStickPitchCmd_Value[GraphNr][iScaleStep]	= Engine1RPM;
	//	fTimeScale_Value[GraphNr][iScaleStep]		= 0.5f; //*_FrameTime;
	//	fElevator_Pos[GraphNr][iScaleStep]			= 8000.0f;
	//	if (iScaleStep<GraphLength-1) iScaleStep++;
	//	else iScaleStep = 0;
			
	/*	{
			float fXScalePos = 0.0f;
			glColor3ubv(white);
			glBegin(GL_LINE_STRIP);
			for(int Count=0; Count <= GraphLength-1; Count++)
				{
					fXScalePos = fXScalePos + fTimeScale_Value[GraphNr][Count]*fXScFactor;
   					glVertex2f(fXScalePos, fStickPitchCmd_Value[GraphNr][Count]*fYScFactor);
					
				}
			glEnd();
		}
		{
			float fXScalePos = 0.0f;
			glColor3ubv(red);
			glBegin(GL_LINE_STRIP);
			for(int Count=0; Count <= GraphLength-1; Count++)
				{
					fXScalePos = fXScalePos + fTimeScale_Value[GraphNr][Count]*fXScFactor;
   					glVertex2f(fXScalePos, fElevator_Pos[GraphNr][Count]*fYScFactor);
					
				}
			glEnd();
		}*/

		


		//float v1 = (float)sin(2*3.14f*iTestTimer);
		//float IDG_Out_Spd_Random_Factor   = 100.00f + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(50.02f)));
		//fZ_Elevation[0] = -v1*  5000; //(Engine1RPM *  Engine1RPM *IDG_Out_Spd_Random_Factor) * 0.03;
		//{
		//	float fXScalePos = 800.0f;
		//	glColor3ubv(red);
		//	glBegin(GL_POINTS);
		//	
		//	for(int Count=0; Count <= 799; Count++)
		//		{
		//			//fXScalePos = fXScalePos - fTimeScale_Value[GraphNr][Count]*fXScFactor;
  // 					glVertex2f(fXScalePos - Count , fZ_Elevation[Count]*fYScFactor);
		//	}

		//	for (int k = 799; k > 0; k--)
		//		{        
		//			fZ_Elevation[k]=fZ_Elevation[k-1];
		//		}
		//
		//	glEnd();
		//}


		/*glTranslated(750,-30,500);
		glColor3ubv(green);
		font0->print(Font::ALIGN_LEFT, "x-axis");
		glPopMatrix();*/










	//glPopMatrix();
	//Graph##############################################################

	//Draw ground (TODO: only if we can see the ground)
	double relativeGround = camera.getRelativeZ(0.0);
	drawLine(0.0, relativeGround, 1.0, relativeGround);

    glPushMatrix();
	glColor3ubv(amber_0);
	float FontScaleFactor = 0.0009f; 

	glTranslatef(0.8,0.3,0);
	glScalef(FontScaleFactor,FontScaleFactor,0.0009f);
    //font0->print(Font::ALIGN_LEFT, "Queuesize: %d", queue.size());
	//glTranslatef(0.5,-20,0);
    font0->print(Font::ALIGN_LEFT, "Meter: %.3f", currentFrame->z0);
	glTranslatef(0.5,-20,0);
    font0->print(Font::ALIGN_LEFT, "Speed: %.3f", sqrt(currentFrame->get_speed_squared()));
	glTranslatef(0.5,-20,0);
    font0->print(Font::ALIGN_LEFT, "Time: %.3f", (float)Time/1000.0f);
	glTranslatef(0.5,-20,0);
    //font0->print(Font::ALIGN_LEFT, "Meter x: %.3f", currentFrame->x0);
	//glTranslatef(0.5, -20, 0);
	font0->print(Font::ALIGN_LEFT, "Angle in Degree: %.3f", currentFrame->direction*180 / PI);
	glTranslatef(0.5, -20, 0);
	font0->print(Font::ALIGN_LEFT, "Anlge of Attack: %.3f", currentFrame->AoA * 180 / PI);
	glTranslatef(0.5, -30, 0);


	font0->print(Font::ALIGN_LEFT, "Lift: %.3f", (float) (currentFrame->forceLift / 1000));
	glTranslatef(0.5, -20, 0);
	font0->print(Font::ALIGN_LEFT, "Thrust: %.3f", (float) (currentFrame->forceTotalThrust / 1000));
	glTranslatef(0.5, -20, 0);
	font0->print(Font::ALIGN_LEFT, "Drag: %.3f", (float) (currentFrame->forceDragForm / 1000));
	glTranslatef(0.5, -30, 0);

    font0->print(Font::ALIGN_LEFT, "SimTimedt: %.3f", currentFrame->time);
	glTranslatef(0.5,-20,0);
    font0->print(Font::ALIGN_LEFT, "SYSTIME : %.3f", (float)TimeSys/1000.0f);

	glTranslatef(0.5,-30,0);
    font0->print(Font::ALIGN_LEFT, "FrameTime: %.6f", timediff);
	glTranslatef(0.5,-30,0);
    font0->print(Font::ALIGN_LEFT, "Extdt: %.6f", extdt);

	

    /*glPopAttrib();*/
    glPopMatrix();


	////DRAW HDG SCALE
	//HdgScale->draw();

	////DRAW SPD SCALE
	//SpdScale->draw();
	
}

void EASY_SIM_CORE::drawLine(float startX, float startY, float endX, float endY) {
	glPushMatrix();
	glBegin(GL_LINE_STRIP);
	glVertex2f(startX, startY);
	glVertex2f(endX,endY);
	glEnd();
	glPopMatrix();
}

void EASY_SIM_CORE::drawLine(float length, float angle) {
	glPushMatrix();
	glRotatef(angle, 0, 0, 1);
	glBegin(GL_LINE_STRIP);
	glVertex2f(-length/2, 0);
	glVertex2f(length/2, 0);
	glEnd();
	glPopMatrix();
}

void EASY_SIM_CORE::drawTriangle(float height, float angle, float rotation, bool filled)
{
    float x = height * (float)tan(angle/2 * PI/180);
    float y = height;

    glPushMatrix();
    glRotatef(rotation,0,0,1);
    glBegin(GL_LINE_LOOP);
        glVertex2f( 0, 0);
        glVertex2f( x, y);
        glVertex2f(-x, y);
    glEnd();
    if (filled)
    {
        glBegin(GL_TRIANGLES);
            glVertex2f( 0, 0);
            glVertex2f( x, y);
            glVertex2f(-x, y);
        glEnd();
    }
    glPopMatrix();
}

void EASY_SIM_CORE::drawRhombus(float height, float width, float rotation, bool filled)
{
    glPushMatrix();
    glRotatef(rotation,0,0,1);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-width/2.0f,0);
        glVertex2f(0,height/2.0f);
        glVertex2f(width/2.0f,0);
        glVertex2f(0,-height/2.0f);
    glEnd();
    if (filled)
    {
        glBegin(GL_POLYGON);
            glVertex2f(-width/2.0f, 0);
            glVertex2f( 0, height/2.0f);
            glVertex2f( width/2.0f, 0);
            glVertex2f( 0,-height/2.0f);
        glEnd();
    }
    glPopMatrix();
}

void EASY_SIM_CORE::drawTrapezoid(float angle, float height, float baseWidth)
{
    float delta = height * (float)sin(angle * PI/180);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-baseWidth/2.0f,0);
        glVertex2f( baseWidth/2.0f,0);
        glVertex2f( delta + baseWidth/2.0f,-height);
        glVertex2f(-delta - baseWidth/2.0f,-height);
    glEnd();
}

void EASY_SIM_CORE::drawOpenBox(float height, float width)
{
    glBegin(GL_LINE_STRIP);
        glVertex2f(-width/2, 0);
        glVertex2f(-width/2, height);
        glVertex2f( width/2, height);
        glVertex2f( width/2, 0);
		glVertex2f(-width/2, 0);
    glEnd();
}

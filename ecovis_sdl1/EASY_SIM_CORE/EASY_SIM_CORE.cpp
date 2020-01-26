/*
 * EASY_SIM_CORE.cpp
 *
 *  Created on: 02.06.2015
 *      Author: Christian Berth
 */

#include <stdlib.h>

#include "EASY_SIM_CORE.h"
#include <math.h>
#include "../Misc/PerlinNoise.h"

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

const double m = 300000.0; //Mass in kg
const double g = -9.81; //Earth acceleration in m/s²
double dt = 0.020; //Time Step Width in s -> NOT USED
const double wingArea = 600.0; //Area of the wings m^2
const double engineArea = 10.0;
const double airDensity = 1.200; //f(T,p) normally kg/m^3
const double ascentAviationCoefficient = 5.5;
const double startAviationCoefficient = 0.3;
const double maxAngleOfAttack = 20 * DEGREES;
const double totalLossAngle = 25 * DEGREES;
const double dragCoefficientFriction = 0.02;
const double dragCoefficientFormMin = 0.09;
const double dragCoefficientFormMax = 1.8;
const double oswaldNumber = 0.7;
const double wingSpan = 60;
const double rotationRate = 0.0025;
const double maxPower = 1.0;
const double powerRate = maxPower * 0.0025;
const double maxVelocity = 270;
const double maxEngineVelocity = 90;

const double cameraWidth = 1000;
const double cameraHeight = 1000;

const double noiseSamplingRate = 0.001; //scale, such that noise it not too rough or smooth
const double noiseSamplingScatter = cameraWidth * 0.0005; // in meter
const double noiseHeightMax = 400; //in meter
const double noiseHeightMin = 0; //in meter
const double noiseSamplingDistance = cameraWidth * 0.01; //in meter

const double starMinHeight = 600; //in meter
const double starDistanceZ = 500;
const double starDistanceX = 400;
const double starScatter = 200;

PerlinNoise noise = PerlinNoise();

const double powerGaugeHeight = 0.2;
const double powerGaugeWidth = 0.04;
const double powerGaugeLineWidth = 0.05;

StaticDequeue<pair<double,double>, SIZE_QUEUE> trailQueue = StaticDequeue<pair<double, double>, SIZE_QUEUE>(true);
//StaticDequeue<pair<double, double>, 50> starQueue = StaticDequeue<pair<double, double>, 50>(true);
Camera camera;

double EASY_SIM_CORE::calculate_drag(double coefficient) {
	return 0.5 * airDensity * currentFrame->get_speed_squared() * coefficient * wingArea;
}

double EASY_SIM_CORE::calculate_engine_velocity() {
	double speed = currentFrame->get_speed_squared();
	double maxSpeed = maxVelocity * maxVelocity;
	double speedRatio = speed / maxSpeed;
	return maxEngineVelocity * (1 - speedRatio);
}

double EASY_SIM_CORE::get_noise_x(double x) {
	return x + noise.noise(x, 1.3, 1.3) * noiseSamplingScatter;
}

double EASY_SIM_CORE::get_noise_y(double x) {
	return (
			(0.572 * (noise.noise(x * noiseSamplingRate, 0.3, 0.3)))
			+ (0.28 * noise.noise(x * noiseSamplingRate * 4, 2.7,2.7))
			+ (0.1248 * noise.noise(x * noiseSamplingRate * 16, 3.4,3.4))
		+ 1) * (noiseHeightMax - noiseHeightMin) * 0.5;
}

double EASY_SIM_CORE::calculate_height_of_ground(double x) {
	double left = x - fmod(x,noiseSamplingDistance);
	double right = left + noiseSamplingDistance;
	double leftY = get_noise_y(left);
	double rightY = get_noise_y(right);
	double t = (x - left) / noiseSamplingDistance;
	return leftY * (1 - t) + rightY * t;
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
	powerController = 0;

	reset(startValues);

	camera = Camera(cameraWidth,cameraHeight,currentFrame->x0, currentFrame->z0);
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
		currentFrame->z0 = 500.0;
		currentFrame->power = 0.7 * maxPower;
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

	// calculate thrust through power (power is linear exhaust velocity (90m/s for 0m/s airspeed) or so)
	double engineVelocity = calculate_engine_velocity() * currentFrame->power;
	double thrust = engineArea * currentFrame->get_speed_in_direction(currentFrame->direction) * airDensity * engineVelocity * engineVelocity;
	if (thrust < 0.0) {
		thrust = 0.0;
	}

	double inducedDrag = this->calculate_drag(dragCoefficientInduced);
	double resultThrust = thrust - inducedDrag;
	double parasiticDrag = this->calculate_drag(dragCoefficientParasitic);

	currentFrame->z2 = g + cos(currentFrame->direction) * lift / m + sin(currentFrame->direction) * resultThrust / m -sin(directionOfSpeed) * parasiticDrag / m;
	currentFrame->z1 = currentFrame->z1 + currentFrame->z2 * dt;
	z0dt = currentFrame->z1*dt;
	currentFrame->z0 = currentFrame->z0 + z0dt;

	currentFrame->x2 = -sin(currentFrame->direction) * lift / m + cos(currentFrame->direction) * resultThrust / m -cos(directionOfSpeed) * parasiticDrag / m;
	currentFrame->x1 = currentFrame->x1 + currentFrame->x2 * dt;
	x0dt = currentFrame->x1*dt;
	currentFrame->x0 = currentFrame->x0 + x0dt;

	trailQueue.push_front(pair<double,double>(currentFrame->x0, currentFrame->z0));
	camera.setFocusPoint(currentFrame->x0, currentFrame->z0);
	
	currentFrame->time = currentFrame->time + dt;

	currentFrame->direction += rotate * rotationRate;
	if (currentFrame->direction < -PI) {
		currentFrame->direction += 2 * PI;
	}else if(currentFrame->direction > PI) {
		currentFrame->direction -= 2 * PI;
	}

	currentFrame->power += powerController * powerRate;
	if (currentFrame->power < 0) {
		currentFrame->power = 0;
	}else if(currentFrame->power > maxPower){
		currentFrame->power = maxPower;
	}

	//save some data into the frame
	currentFrame->forceLift = lift;
	currentFrame->forceTotalThrust = resultThrust;
	currentFrame->forceDragForm = parasiticDrag;
	currentFrame->forceDragInduced = inducedDrag;
	currentFrame->AoA = angleOfAttack;

	//test crash
	if (currentFrame->z0 < calculate_height_of_ground(currentFrame->x0)) crashed = true;
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
	pair<double, double> position = camera.getRelativePosition(trailQueue.front());
	////+0.1 and +0.5 instead of +0.3 like in the camera
	glTranslatef(position.first,position.second,0);
 //   drawOpenBox(0.01,0.01);      // -10 deg Rollmark
	drawLine(0.05,currentFrame->direction*180 /  PI);
	//---- DEBUG ---- Draw Force Vectors (lift, thrust, parasiticDrag)
	//currentFrame->z2 = - sin(directionOfSpeed) * parasiticDrag * 0.01;
	//currentFrame->x2 = - cos(directionOfSpeed) * parasiticDrag * 0.01;
	//glColor3ubv(amber_0);
	//drawLine(0,0,-sin(currentFrame->direction) * 0.05,cos(currentFrame->direction) * 0.05);
	//glColor3ubv(white);
	//drawLine(0, 0, cos(currentFrame->direction) * 0.05, sin(currentFrame->direction) * 0.05);
	//glColor3ubv(green);
	//drawLine(0, 0, -cos(currentFrame->get_direction_of_speed()) * 0.05, -sin(currentFrame->get_direction_of_speed()) * 0.05);
	// --- END DEBUG ----
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
			for(int count=0; count < trailQueue.size(); count++)
				{
					position = camera.getRelativePosition(trailQueue[count]);
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

	//Draw ground
	double left = camera.getLeft();
	left -= fmod(left, noiseSamplingDistance);
	double right = left + noiseSamplingDistance;
	double relativeHeightLeft = camera.getRelativeZ(get_noise_y(left));
	double relativeHeightRight = camera.getRelativeZ(get_noise_y(right));
	double relativeLeft = camera.getRelativeX(left);
	double relativeRight = camera.getRelativeX(right);
	while (right < camera.getRight() + noiseSamplingDistance) {
		drawLine(relativeLeft, relativeHeightLeft, relativeRight, relativeHeightRight);
		//go to the next pair
		left = right;
		relativeHeightLeft = relativeHeightRight;
		relativeLeft = relativeRight;
		right += noiseSamplingDistance;
		relativeHeightRight = camera.getRelativeZ(get_noise_y(right));
		relativeRight = camera.getRelativeX(right);
	}

	//draw some Stars
	left = camera.getLeft();
	left -= fmod(left,starDistanceX) + starDistanceX;
	right = camera.getRight();
	right -= fmod(right, starDistanceX);
	right += 2 * starDistanceX;
	double bottom = camera.getBottom();
	bottom -= fmod(bottom, starDistanceZ) + starDistanceZ;
	if (bottom < starMinHeight) bottom = starMinHeight;
	double top = camera.getTop();
	top -= fmod(top, starDistanceZ);
	top += 2 * starDistanceZ;
	int xIteration = (int)((right - left) / starDistanceX);
	int zIteration = (int)((top - bottom) / starDistanceZ);
	for (int i = 0; i < xIteration; ++i) {
		for (int j = 0; j < zIteration; ++j) {
			double x = left + starDistanceX * i;
			double z = bottom + starDistanceZ * j;
			x += noise.positiveNoise(x, z, 5.6) * starDistanceX;
			z += noise.positiveNoise(x, z, 6.5) * starDistanceZ;
			//scattering
			x += noise.noise(x, z, 7.1) * starScatter;
			z += noise.noise(x, z, 8.2) * starScatter;
			drawStar(camera.getRelativeX(x), camera.getRelativeZ(z));
		}
	}

	//Draw Power Gauge
	drawPowerGauge();

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
	//font0->print(Font::ALIGN_LEFT, "Iteration x: %.3f", xIteration);
	//glTranslatef(0.5, -20, 0);
	font0->print(Font::ALIGN_LEFT, "Ground Height: %.3f", calculate_height_of_ground(currentFrame->x0));
	glTranslatef(0.5, -20, 0);
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

void EASY_SIM_CORE::drawPowerGauge() {
	const double heightOfPower = (currentFrame->power / maxPower) * powerGaugeHeight;
	glPushMatrix();
	glTranslatef(0.05 + powerGaugeLineWidth / 2,0.05,0);
	//empty box
	glColor3ubv(white);
	glBegin(GL_LINE_STRIP);
	glVertex2f(-powerGaugeWidth / 2, 0);
	glVertex2f(powerGaugeWidth / 2,0);
	glVertex2f(powerGaugeWidth / 2, powerGaugeHeight);
	glVertex2f(-powerGaugeWidth / 2, powerGaugeHeight);
	glVertex2f(-powerGaugeWidth / 2,0);
	glEnd();
	//line to show power
	glColor3ubv(amber_0);
	glBegin(GL_LINE_STRIP);
	glVertex2f(-powerGaugeLineWidth /2, heightOfPower);
	glVertex2f(powerGaugeLineWidth /2, heightOfPower);
	glEnd();
	glPopMatrix();
}

void EASY_SIM_CORE::drawStar(double x, double z, double size) {
	glPushMatrix();
	glTranslatef(x, z, 0);
	for (float i = 0; i < 180; i += 45) {
		glRotatef(i, 0, 0, 1);
		glBegin(GL_LINE_STRIP);
		glVertex2f(-size, 0);
		glVertex2f(size, 0);
		glEnd();
	}
	glPopMatrix();
}

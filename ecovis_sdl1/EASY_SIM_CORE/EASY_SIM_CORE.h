/*
 * A330PFD.h
 *
 *  Created on: 05.05.2010
 *      Author: CBV1-Admin
 */

#ifndef EASY_SIM_CORE_C
#define EASY_SIM_CORE_C

#include "../Graphics/Drawable.h"
#include "../Graphics/Font.h"
#include "../Graphics/RectSprite.h"
#include "../Graphics/colors.h"
#include "../Graphics/Coordinate2D.h"

#include "TimeFrame.h"
#include "../Misc/StaticDequeue.h"
#include "../Misc/Camera.h"

#include <math.h>



class EASY_SIM_CORE:
	public Drawable {
public:
	EASY_SIM_CORE(int DisplayWidth, int DisplayHeight, TimeFrame* startValues = nullptr);
	void CalcEASY_SIM_CORE();
	virtual ~EASY_SIM_CORE();
	virtual void draw();
	void reset(TimeFrame* startValues = nullptr);
	
	int Time, TimeSys;
	double timediff;
	double extdt;
	bool crashed;
	int rotate;
	int powerController;

private:
	void drawRhombus(float height, float width, float rotation, bool filled);
	void drawOpenBox(float height, float width);
	void drawTrapezoid(float angle, float height, float baseWidth);
	void drawTriangle(float height, float angle, float rotation, bool filled);
	void drawLine(float startX, float startY, float endX, float endY);
	void drawLine(float length, float angle);
	void drawPowerGauge();
	void drawStar(double x, double z, double size = 0.02);

	double calculate_drag(double coefficient);
	double calculate_engine_velocity();
	double calculate_height_of_ground(double x);
	double get_noise_x(double x);
	double get_noise_y(double x);

	Font   *font0, *font1, *font2, *font3, *font4;
	RectSprite *RSprite1;

	

};

#endif 

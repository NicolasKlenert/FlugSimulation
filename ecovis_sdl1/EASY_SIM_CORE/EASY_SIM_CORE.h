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

#include <math.h>



class EASY_SIM_CORE:
	public Drawable {
public:
	EASY_SIM_CORE(int DisplayWidth, int DisplayHeight, TimeFrame* startValues = nullptr);
	void CalcEASY_SIM_CORE();
	virtual ~EASY_SIM_CORE();
	virtual void draw();
	
	int Time, TimeSys;
	double timediff;
	double extdt;

private:
	void drawRhombus(float height, float width, float rotation, bool filled);
	void drawOpenBox(float height, float width);
	void drawTrapezoid(float angle, float height, float baseWidth);
	void drawTriangle(float height, float angle, float rotation, bool filled);

	Font   *font0, *font1, *font2, *font3, *font4;
	RectSprite *RSprite1;

	

};

#endif 
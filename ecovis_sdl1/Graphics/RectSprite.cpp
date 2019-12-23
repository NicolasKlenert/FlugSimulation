#include "RectSprite.h"
#include <math.h>

RectSprite::RectSprite():
thickness(1.0f),
filled(filled),
color2(-1,-1,-1,-1)
{
}
RectSprite::RectSprite(float x1, float y1, float x2, float y2, bool filled):
thickness(1.0f),
filled(filled),
color2(-1,-1,-1,-1)
{
	position.setPosition(x1,y1);
	size.setPosition(x2 - x1,y2 - y1);
}


RectSprite::~RectSprite(void)
{
}

void RectSprite::setColor2(float r, float g, float b, float a)
{
	color2.setColor(r, g, b, a);
}

void RectSprite::draw()
{
		glPushMatrix();
		glPushAttrib(GL_ENABLE_BIT | GL_CURRENT_BIT | GL_POLYGON_BIT);
		glTranslated(position.getX(),position.getY(),0);
		glRotated(angle,0, 0,1);
		glTranslated(center.getX(),center.getY(),0);
		glColor4f(color.r, color.g, color.b, color.a);
		glEnable (GL_LINE_SMOOTH);
		glLineWidth(thickness);
		if(filled)
			glBegin(GL_POLYGON);
		else
			glBegin(GL_LINE_LOOP);
			glVertex2f(0  ,0);
			glVertex2f(size.getX(), 0);
			if(color2.r > -0.5f)
				glColor4f(color2.r, color2.g, color2.b, color2.a);
			glVertex2f(size.getX(), size.getY());
			glVertex2f(0, size.getY());
		glEnd();
		glPopAttrib();
		glPopMatrix();
}

void RectSprite::setEndpoints(float x1, float y1, float x2, float y2)
{
	position.setPosition(x1,y1);
	size.setPosition(x2 - x1,y2 - y1);
}

void RectSprite::setThicness(float value)
{
	thickness = value;
}

#include "LineSprite.h"
#include <math.h>

LineSprite::LineSprite():
thickness(1.0f)
{
}
LineSprite::LineSprite(float x1, float y1, float x2, float y2):
thickness(1.0f)
{
	position.setPosition(x1,y1);
	size.setPosition(x2 - x1,y2 - y1);
}


LineSprite::~LineSprite(void)
{
}

void LineSprite::draw()
{
		glPushMatrix();
		glPushAttrib(GL_ENABLE_BIT | GL_CURRENT_BIT | GL_POLYGON_BIT);
		glTranslated(position.getX(),position.getY(),0);
		glRotated(angle,0, 0,1);
		glTranslated(center.getX(),center.getY(),0);
		glColor4f(color.r, color.g, color.b, color.a);
		glEnable (GL_LINE_SMOOTH);
		glLineWidth(thickness);
		glBegin(GL_LINE_STRIP);
			glVertex2f(0  ,0);
			glVertex2f(size.getX(), size.getY());	
		glEnd();
		glPopAttrib();
		glPopMatrix();
}

void LineSprite::setEndpoints(float x1, float y1, float x2, float y2)
{
	position.setPosition(x1,y1);
	size.setPosition(x2 - x1,y2 - y1);
}

void LineSprite::setThicness(float value)
{
	thickness = value;
}

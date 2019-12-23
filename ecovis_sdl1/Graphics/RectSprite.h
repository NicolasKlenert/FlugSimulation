#ifndef RECTSPRITE_H
#define RECTSPRITE_H
#include "Sprite.h"

class RectSprite :
	public Sprite
{
public:
	RectSprite();
	RectSprite(float x1, float y1, float x2, float y2, bool filled);
	virtual ~RectSprite(void);
	virtual void draw();
	void setEndpoints(float x1, float y1, float x2, float y2);
	void setThicness(float value);
	void setColor2(float r, float g, float b, float a);

protected:
	float thickness;
	bool filled;
	Color4f color2;
};
#endif

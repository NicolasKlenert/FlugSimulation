#ifndef LINESPRITE_H
#define LINESPRITE_H
#include "Sprite.h"

class LineSprite :
	public Sprite
{
public:
	LineSprite();
	LineSprite(float x1, float y1, float x2, float y2);
	virtual ~LineSprite(void);
	virtual void draw();
	void setEndpoints(float x1, float y1, float x2, float y2);
	void setThicness(float value);

protected:
	float thickness;
};
#endif

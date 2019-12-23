#ifndef IMAGESPRITE_H
#define IMAGESPRITE_H
#include "Sprite.h"
#include "Texture.h"
#include <string>
#include <stdexcept>
using namespace std;

class ImageSprite :
	public Sprite
{
public:
	ImageSprite(string filename)
		throw(runtime_error);
	ImageSprite(string filename, int r, int g, int b)
		throw(runtime_error);
	virtual ~ImageSprite(void);
	virtual void draw();

protected:
	Texture texture;

};

#endif

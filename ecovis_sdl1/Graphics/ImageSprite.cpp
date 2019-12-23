#include "ImageSprite.h"
using namespace std;

ImageSprite::ImageSprite(string filename)
	throw(runtime_error):
		texture(filename)
{
}

ImageSprite::ImageSprite(string filename, int r, int g, int b)
	throw(runtime_error):
	texture(filename, r, g, b)
{
}

ImageSprite::~ImageSprite(void)
{
}

void ImageSprite::draw()
{
		glPushMatrix();
		glPushAttrib(GL_ENABLE_BIT | GL_CURRENT_BIT);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture.getTexture());
		glColor4f(color.r, color.g, color.b, color.a);
		glTranslated(position.getX(),position.getY(),0);
		glRotated(angle,0, 0,1);
		glTranslated(center.getX(),center.getY(),0);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 1.0f); glVertex2f(0, 0);
		glTexCoord2f(1.0f, 1.0f); glVertex2f( 0 + size.getX(), 0);
		glTexCoord2f(1.0f, 0.0f); glVertex2f( 0 + size.getX(), 0 + size.getY());
		glTexCoord2f(0.0f, 0.0f); glVertex2f(0, 0 + size.getY());
		glEnd();
		glPopAttrib();
		glPopMatrix();
}

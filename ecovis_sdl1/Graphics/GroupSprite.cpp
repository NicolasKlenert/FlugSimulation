#include "GroupSprite.h"
using namespace std;
GroupSprite::GroupSprite(void)
{
	//displayList = glGenLists(1);
}

GroupSprite::~GroupSprite(void)
{
	//glDeleteLists(displayList,1);
}
void GroupSprite::draw()
{
	//glNewList(displayList,GL_COMPILE);
		glPushMatrix();
		glPushAttrib(GL_ALL_ATTRIB_BITS);
		glTranslated(position.getX(),position.getY(),0);
		glRotated(angle,0, 0,1);
		glTranslated(center.getX(),center.getY(),0);
		for(vector<Drawable*>::iterator Iter = content.begin(); Iter != content.end(); Iter++)
		{
			if((*Iter)->isEnabled())(*Iter)->draw();
		}
		glPopAttrib();
		glPopMatrix();
	//glEndList();
	//glCallList(displayList);
}
void GroupSprite::addObj(Drawable *obj)
{
	content.push_back(obj);
}
void GroupSprite::clear()
{
	content.clear();
}

#ifndef GROUPSPRITE_H
#define GROUPSPRITE_H
#include "Sprite.h"
#include "Drawable.h"
#include <vector>
using namespace std;

class GroupSprite :
	public Sprite
{
public:
	GroupSprite(void);
	virtual ~GroupSprite(void);
	virtual void draw();
	void addObj(Drawable *obj);
	void clear();
protected:
	vector<Drawable*> content;
	GLuint displayList;
};

#endif

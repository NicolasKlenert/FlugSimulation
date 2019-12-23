#ifndef VIEWPORT_H
#define VIEWPORT_H
#include "Drawable.h"
#include "Perspective.h"
#include <vector>

using namespace std;

class ViewPort
{
public:
	inline ViewPort(void):enabled(true){};
	ViewPort(int x, int y, int height, int width);
	inline virtual ~ViewPort(void){};

	void resize(int x, int y, int height, int width);
	bool is3d();
	void enable3d();
	void disable3d();
	void render(void);
	void add(Drawable *object);
    Perspective *getView() const;
    void setView(Perspective *view);

	inline bool isEnabled(){
		return enabled;
	}

	inline void enable()
	{
		enabled = true;
	}

	inline void disable()
	{
		enabled = false;
	}
	inline void setEnable(bool value)
	{
		enabled = value;
	}

	//normed
	inline bool isNormed(){
		return normed;
	}

	inline void enableNormed()
	{
		normed = true;
	}

	inline void disableNormed()
	{
		normed = false;
	}
	inline void setNormed(bool value)
	{
		normed = value;
	}

protected:
	int x, y, height, width;
	bool mode3D;
	bool enabled;
	bool normed;
	Perspective *view;
	vector<Drawable*> objectList;
};
#endif

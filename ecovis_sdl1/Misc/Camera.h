#pragma once
#ifndef NICOLAS_KLENERT_CAMERA
#define NICOLAS_KLENERT_CAMERA

#include <utility>

class Camera {
protected:
	double focusPointX;
	double focusPointZ;
	double width;
	double height;
public:
	Camera();
	Camera(double width, double height, double focusPointX, double focusPointZ);
	std::pair<double, double> getRelativePosition(std::pair<double,double> position);
	double getRelativeX(double x);
	double getRelativeZ(double z);
	void setFocusPoint(double x, double z);
	double getWidth() { return width; };
	double getHeight() { return height; };
	double getLeft();
	double getRight();
	double getTop();
	double getBottom();
};

#endif // !NICOLAS_KLENERT_CAMERA


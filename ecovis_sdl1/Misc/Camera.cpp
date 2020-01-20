#include "Camera.h"
#include <Windows.h>
#include <sstream>

double minZ = 0.3;
double maxZ = 0.6;
double minAnchorZ = -0.1;

//position of the focus point
double focusX = 0.3;
double focusZ = 0.5;

Camera::Camera() :
	width(0.0),
	height(0.0),
	focusPointX(0.0),
	focusPointZ(0.0)
{}

Camera::Camera(double width, double height, double focusPointX, double focusPointZ) :
	width(width),
	height(height),
	focusPointX(focusPointX),
	focusPointZ(focusPointZ)
{}

double calculateRelative(double val, double focusPoint, double dimension, double mid) {
	return ((val - focusPoint) / dimension) + mid;
}

double Camera::getRelativeX(double x) {
	return calculateRelative(x, focusPointX, width, focusX);
}

double Camera::getRelativeZ(double z) {
	return calculateRelative(z, focusPointZ, height, focusZ);
}

std::pair<double, double> Camera::getRelativePosition(std::pair<double,double> position) {
	return std::pair<double, double>(getRelativeX(position.first),
		getRelativeZ(position.second));
}

void Camera::setFocusPoint(double xCoord, double zCoord) {
	focusPointX = xCoord;
	double potZ = calculateRelative(zCoord,focusPointZ,height,focusZ);
	//OutputDebugStringA(std::to_string(potZ).c_str());
	if (potZ > maxZ) {
		focusPointZ += (potZ - maxZ) * height;
	} else if (potZ < minZ) {
		focusPointZ -= (minZ - potZ) * height;
	}
	double minHeight = (focusZ + minAnchorZ) * height;
	focusPointZ = (focusPointZ > minHeight) ? focusPointZ : minHeight;

}

double Camera::getLeft() {
	return 0.0;
}

double Camera::getRight() {
	return 0.0;
}

double Camera::getTop() {
	return 0.0;
}

double Camera::getBottom() {
	return 0.0;
}

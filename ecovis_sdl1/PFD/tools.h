#ifndef TOOLS_H
#define TOOLS_H

#include <stdlib.h>     // malloc, rand
#include <math.h>
#include "../Graphics/gl_headers.h"
#include "../Data/constants.h"
#include "../Graphics/colors.h"
#include "definitions.h"
#include "geometryVariables.h"
#include "circleGenerator.h"

float degreesDiff(float currentValue, float compareValue);
float degreesDiff(float currentValue, float compareValue, SIDE compareSide);
bool inDisplayRange(float currentValue, float compareValue, TAPES display);
float getTranslation(float currentValue, float compareValue, TAPES display);
void drawTriangle(float height, float angle, float rotation, bool filled);
void drawRhombus(float height, float width, float rotation, bool filled);
void drawTrapezoid(float angle, float height, float baseWidth);
void drawOpenBox(float height, float width);
void drawRectangle(float height, float width, bool filled);

#endif

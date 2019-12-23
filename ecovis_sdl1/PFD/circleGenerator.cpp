#include "../Graphics/gl_headers.h"
#include <math.h>
#include "../Data/constants.h"
#include "circleGenerator.h"

CircleGenerator::CircleGenerator(void)
{
    m_xOrigin = 0;
    m_yOrigin = 0;
    m_nPoints = 10;
    m_radius = 1;
}

CircleGenerator::~CircleGenerator(void)
{
}

void CircleGenerator::SetOrigin(double x, double y)
{
    m_xOrigin = x;
    m_yOrigin = y;
}

void CircleGenerator::SetPointsNumber(int nPoints)
{
    m_nPoints = nPoints;
}

void CircleGenerator::SetDegreesPerPoint(double degreesPerPoint)
{
    m_degreesPerPoint = degreesPerPoint;
}

void CircleGenerator::Generate()
{
    double angle;
    // Add the vertexes specified
    double x;
    double y;

    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < m_nPoints; i++)
    {
        angle = 2*PI*i/m_nPoints;
        x = m_radius*cos(angle) + m_xOrigin;
        y = m_radius*sin(angle) + m_yOrigin;
        glVertex2d(x,y);
    }
    glEnd();
}

void CircleGenerator::SetRadius(double radius)
{
    if (radius > 0)
        m_radius = radius;
    else
        m_radius = 1;
}

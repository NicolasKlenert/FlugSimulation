#ifndef CIRCLE_GENERATOR_H
#define CIRCLE_GENERATOR_H

class CircleGenerator
{
public:
    CircleGenerator(void);
    ~CircleGenerator(void);

    /** Sets the radius of the circle in physical units */
    void SetRadius(double radius);

    /** Defines the "coarseness" of the circle (degree spacing of GL_POINTS) */
    void SetDegreesPerPoint(double degreesPerPoint);
    void SetPointsNumber(int nPoints);

    /** Defines the center of the circle in physical units */
    void SetOrigin(double x, double y);
    void SetXOrigin(double x);
    void SetYOrigin(double y);

    /** Calls the GL code to evaluate the circle (generates points) */
    void Generate();

protected:

    /** The origin (center) of the circle */
    double m_xOrigin, m_yOrigin;
    /** The radius of the arc/circle */
    double m_radius;
    /** The start and end of the arc in degrees */
    double m_startAngle, m_endAngle;
    /** How many degrees to move before generating a new point */
    double m_degreesPerPoint;
    /** How many points to draw */
    int m_nPoints;

};

#endif

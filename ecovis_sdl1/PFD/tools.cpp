#include "tools.h"

float degreesDiff(float currentValue, float compareValue)
{
    float difference;

    difference = compareValue - currentValue;
    //difference = (compareValue - 180) - (currentValue - 180);
    if (difference > 180)
        difference = compareValue - 360 - currentValue;
    else if (difference < -180)
        difference = compareValue - currentValue + 360;

    return difference;
}

float degreesDiff(float currentValue, float compareValue, SIDE compareSide)
{
    float difference = 0;

    if (compareSide == RIGHT)
    {
        if (compareValue < currentValue)
            difference = compareValue + 180 - currentValue;
        else
            difference = compareValue - currentValue;
    }
    else if (compareSide == LEFT)
    {
        if (compareValue > currentValue)
            difference = compareValue - 180 - currentValue;
        else
            difference = currentValue - compareValue;
    }
    else if (compareSide == CENTER)
    {
        if ((currentValue == compareValue) || ((currentValue == 0) && (compareValue == 360)) || ((currentValue == 360) && (compareValue == 0)))
            difference = 0;
        else
            difference = 180;
    }

    return difference;
}

bool inDisplayRange(float currentValue, float compareValue, TAPES display)
{
    bool inside, outOfRange;

    float distancePerMark, valuePerMark, scale, scaleLength;
    float difference, minValue, maxValue;
    if (display == ALT_TAPE)
    {
        minValue = -5000;
        maxValue = 55000;
        valuePerMark = 100;     // 100ft
        distancePerMark = 35;   // one mark every 35 length units
        scaleLength = 400;      // 400 Length units
    }
    else if (display == HDG_TAPE)
    {
        minValue = 0;
        maxValue = 360;
        valuePerMark = 5;       // 5 deg
        distancePerMark = 35;   // one mark every 35 length units
        scaleLength = 346.4f;   // 346.4 Length units
    }
    else if (display == SPD_TAPE)
    {
        minValue = 30;
        maxValue = 790;
        valuePerMark = 10;      // 10 kts
        distancePerMark = 44;   // one mark every 44 length units
        scaleLength = 400;      // 400 Length units
    }

    if ((currentValue > maxValue) || (currentValue < minValue))
        outOfRange = true;
    else
        outOfRange = false;

    scale = scaleLength/distancePerMark * valuePerMark/2;
    if (display != HDG_TAPE)
        difference = fabs(compareValue - currentValue);
    else
    {
        //SIDE mySide;

        //switch (compareDegrees(currentValue, compareValue))
        //{
        //case 0:
        //    mySide = CENTER;
        //    break;
        //case 1:
        //    mySide = CENTER;
        //    break;
        //case 2:
        //    mySide = RIGHT;
        //    break;
        //case 3:
        //    mySide = LEFT;
        //    break;
        //}

        difference = fabs(degreesDiff(currentValue, compareValue));
    }

    if (difference < scale)
        inside = true;
    else
        inside = false;

    return (inside && !outOfRange);
}

float getTranslation(float currentValue, float compareValue, TAPES display)
{

    float distancePerMark, valuePerMark, scale;
    float value;

    if (display == ALT_TAPE)
    {
        valuePerMark = 100;     // 100ft
        distancePerMark = 35;   // one mark every 35 length units
    }
    else if (display == HDG_TAPE)
    {
        valuePerMark = 5;       // 5 deg
        distancePerMark = 35;   // one mark every 35 length units
    }
    else if (display == SPD_TAPE)
    {
        valuePerMark = 10;      // 10 kts
        distancePerMark = 44;   // one mark every 44 length units
    }

    scale = distancePerMark/valuePerMark;
    if (display != HDG_TAPE)
        value = (compareValue - currentValue) * scale;
    else
    {
        //SIDE mySide;
        float difference;

        difference = degreesDiff(currentValue, compareValue);
        value = difference * scale;
    }

    return value;
}

void drawTriangle(float height, float angle, float rotation, bool filled)
{
    float x = height * (float)tan(angle/2 * PI/180);
    float y = height;

    glPushMatrix();
    glRotatef(rotation,0,0,1);
    glBegin(GL_LINE_LOOP);
        glVertex2f( 0, 0);
        glVertex2f( x, y);
        glVertex2f(-x, y);
    glEnd();
    if (filled)
    {
        glBegin(GL_TRIANGLES);
            glVertex2f( 0, 0);
            glVertex2f( x, y);
            glVertex2f(-x, y);
        glEnd();
    }
    glPopMatrix();
}

void drawRhombus(float height, float width, float rotation, bool filled)
{
    glPushMatrix();
    glRotatef(rotation,0,0,1);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-width/2.0f,0);
        glVertex2f(0,height/2.0f);
        glVertex2f(width/2.0f,0);
        glVertex2f(0,-height/2.0f);
    glEnd();
    if (filled)
    {
        glBegin(GL_POLYGON);
            glVertex2f(-width/2.0f, 0);
            glVertex2f( 0, height/2.0f);
            glVertex2f( width/2.0f, 0);
            glVertex2f( 0,-height/2.0f);
        glEnd();
    }
    glPopMatrix();
}

void drawTrapezoid(float angle, float height, float baseWidth)
{
    float delta = height * (float)sin(angle * PI/180);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-baseWidth/2.0f,0);
        glVertex2f( baseWidth/2.0f,0);
        glVertex2f( delta + baseWidth/2.0f,-height);
        glVertex2f(-delta - baseWidth/2.0f,-height);
    glEnd();
}

void drawOpenBox(float height, float width)
{
    glBegin(GL_LINE_STRIP);
        glVertex2f(-width/2, 0);
        glVertex2f(-width/2, height);
        glVertex2f( width/2, height);
        glVertex2f( width/2, 0);
    glEnd();
}
void drawRectangle(float height, float width, bool filled)
{
    float x0, y0, x1, y1;
    x0 = -width/2.0f;
    x1 =  width/2.0f;
    y0 = -height/2.0f;
    y1 =  height/2.0f;

    if (filled)
    {
        glRectf(x0,y0,x1,y1);
    }
    else
    {
        glBegin(GL_LINE_LOOP);
            glVertex2f(x0,y0);
            glVertex2f(x0,y1);
            glVertex2f(x1,y1);
            glVertex2f(x1,y0);
        glEnd();
    }
}

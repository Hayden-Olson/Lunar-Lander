/***********************************************************************
 * Header File:
 *    STAR
 * Author:
 *    Br. Helfrich
 * Summary:
 *    50 randomly placed stars that twinkle at random intervals
 ************************************************************************/

#pragma once
#include "position.h"   // for POSITION
#include "uiDraw.h"     // for RANDOM and DRAWSTAR
#include <array>

/*****************************************************
 * STAR
 * A star that twinkles
 *****************************************************/
class Star
{
private:
    std::array<Position, 50> starPos;
    unsigned char phase = 0;

public:
    // Constructor: automatically randomizes all star positions
    Star(double width = 800.0, double height = 600.0)
    {
        reset(width, height);
    }

    // Randomize all star coordinates
    void reset(double width, double height)
    {
        for (int i = 0; i < 50; i++)
        {
            double x = random(0.0, width);
            double y = random(height * 0.5, height);
            starPos[i].setX(x);
            starPos[i].setY(y);
        }
    }

    // Draw all stars on the screen
    void draw(ogstream& gout)
    {
        for (int i = 0; i < 50; i++)
        {
            gout.drawStar(starPos[i], phase + i * 3);
        }
        phase += 4;
    }
};

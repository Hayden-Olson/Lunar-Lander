/***********************************************************************
 * Header File:
 *    STAR
 * Author:
 *    Br. Helfrich
 * Summary:
 *    A single star that twinkles
 ************************************************************************/

#pragma once
#include "position.h"   // for POSITION
#include "uiDraw.h"     // for RANDOM and DRAWSTAR
#include "random"

/*****************************************************
 * STAR
 * A star that twinkles
 *****************************************************/
class Star
{
private:
	Position pos;
	unsigned char phase;
public:
	void reset(double width, double height)
	{
		double x = RANDOM(0.0, width);
		double y = RANDOM(0.0, height);
		pos.setX(x);
		pos.setY(y);
		phase = RANDOM(0, 3);
	}
	void draw(ogstream gout) const
	{
		gout.drawStar(pos, phase);
	}
};

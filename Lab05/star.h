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
      double x = random(0.0, width);
      double y = random(0.0, height);
      pos.setX(x);
      pos.setY(y);
   }
   void draw(ogstream & gout)
   {
      for (int i = 0; i < 51; i++)
         gout.drawStar(pos, phase);
         phase += 1;
		 double width = random(0.0, 800.00);
		 double height = random(0.0, 600.00);
		 reset(width, height);
   }
};

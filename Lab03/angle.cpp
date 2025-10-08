/***********************************************************************
 * Source File:
 *    ANGLE
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a direction
 ************************************************************************/

#include "angle.h"
#include <math.h>  // for floor()
#include <cassert>
using namespace std;


/************************************
 * ANGLE : NORMALIZE
 ************************************/
double Angle::normalize(double radians) const
{
	while (radians < 0)
	{
		radians += 2.0 * M_PI;
	}
	while (radians >= 2.0 * M_PI)
	{
		radians -= 2.0 * M_PI;
	}
	return radians;
}



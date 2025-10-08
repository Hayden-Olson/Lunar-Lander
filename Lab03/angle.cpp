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

void Angle::setDegrees(double degrees)
{
	double newRadian = degrees * M_PI / 180.0;
	radians = normalize(newRadian);
};

double Angle :: normalize(double angle) const
{
	while (angle < 0)
	{
		angle += 2.0 * M_PI;
	}
	while (angle >= 2.0 * M_PI)
	{
		angle -= 2.0 * M_PI;
	}
	return angle;
};

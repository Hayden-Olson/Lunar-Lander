/***********************************************************************
 * Header File:
 *    ANGLE
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a direction
 ************************************************************************/

#pragma once

#define _USE_MATH_DEFINES
#include <math.h>   // for M_PI which is 3.14159

class TestPosition;
class TestVelocity;
class TestAcceleration;
class TestAngle;
class TestLander;

/************************************
 * ANGLE
 ************************************/
class Angle
{
public:
   friend TestAcceleration;
   friend TestVelocity;
   friend TestAngle;
   friend TestLander;
   
   // Constructors
   Angle() : radians(0.0)
   {};
   Angle(const Angle& rhs) : radians(rhs.radians)
   {};
   Angle(double degrees)
   {
	   setDegrees(degrees);
   };

   // Getters
   double getDegrees() const 
   { 
	   return radians * 180.0 / M_PI; 
   };
   double getRadians() const 
   { 
	   return radians; 
   };

   // Setters
   void setDegrees(double degrees)
   {
	   double newRadian = degrees * M_PI / 180.0;
	   radians = normalize(newRadian);
   };
   void setRadians(double inRadians)
   {
	   radians = normalize(inRadians);
   };
   void setUp()
   {
	   setDegrees(0);
   };
   void setDown()
   {
	   setDegrees(180);
   };
   void setRight()
   {
	   setDegrees(90);
   };
   void setLeft()
   {
	   setDegrees(270);
   };
   void reverse()
   {
	   radians = normalize(radians + M_PI);
   };
   Angle& add(double delta)
   {
	   radians = normalize(radians + delta);
	   return *this;
   };

private:
	double normalize(double angle) const
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

	double radians;   // 360 degrees equals 2 PI radians
};


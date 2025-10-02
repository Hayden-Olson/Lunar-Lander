/*************************************************************
 * 1. Name:
 *      Mason Allen & Hayden Olson
 * 2. Assignment Name:
 *      Practice 03: Angle Class
 * 3. Assignment Description:
 *      A class to represent an angle
 * 4. What was the hardest part? Be as specific as possible.
 *      -a paragraph or two about how the assignment went for you-
 * 5. How long did it take for you to complete the assignment?
 *      -total time in hours: reading the assignment, submitting, etc.
 **************************************************************/

#pragma once

#define TWO_PI 6.28318530718

#include <math.h>    // for floor()
#include <iostream>  // for cout
#include <cassert>   // for assert()
using namespace std;
class TestAngle;

 /************************************
  * ANGLE
  ************************************/
class Angle
{
   friend TestAngle;
   double radians;
   

	public:

		double getDegrees() 
		{
			double degAngle = convertToDegrees(radians);
			return degAngle;
		};

		double getRadians() 
		{
			return radians;
		};

		void setDegrees(int degrees)
		{
			double newRads = convertToRadians(degrees);
			radians = newRads;
		};

		void setRadians(double rawRadian)
		{
			rawRadian = normalize(rawRadian);
			radians = rawRadian;
			
		};

		void display(ostream& out)
		{
			//not sure why floor() doesnt work here. cout.precision isn't working either.
			out << convertToDegrees(radians) << "degrees";
		};

	private:

		double normalize(double inRadian)
		{
			while ((inRadian > TWO_PI) or (inRadian < 0))
			{
				while (inRadian > TWO_PI)
				{
					inRadian = inRadian - TWO_PI;
				};

				while (inRadian < 0)
				{
					inRadian = inRadian + TWO_PI;
				};
			};
			return inRadian;
		};

		double convertToDegrees(double inRadian)
		{
			inRadian = normalize(inRadian);
			double newDeg = (inRadian * (180 / (TWO_PI / 2)));
			return newDeg;
		};

		double convertToRadians(double degrees)
		{
			double newRad = (degrees * ((TWO_PI / 2) / 180));
			newRad = normalize(newRad);
			return newRad;
		};
};



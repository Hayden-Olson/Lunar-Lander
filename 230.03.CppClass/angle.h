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

	public:

		double getDegrees() 
		{

		};

		double getRadians() 
		{

		};

		int setDegrees(int degrees)
		{

		};

		double getRadians(double radian)
		{

		};

		void display(ostream& out, double degrees)
		{
			cout.precision(1);
			out << degrees;
		};

	private:

		double normalize(double radian)
		{

		};

		double convertToDegrees(double radian)
		{

		};

		double convertToRadians(double degrees)
		{

		};
};



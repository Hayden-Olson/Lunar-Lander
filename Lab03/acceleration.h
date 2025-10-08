/***********************************************************************
 * Header File:
 *    ACCELERATION 
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about acceleration
 ************************************************************************/


#pragma once
#include <math.h>;
#include "angle.h";

class TestAcceleration;
class TestVelocity;
class TestPosition;
class TestLander;
class Angle;


/*********************************************
 * Acceleration
 * Let's get moving
 *********************************************/
class Acceleration
{
   friend TestPosition;
   friend TestVelocity;
   friend TestAcceleration;
   friend TestLander;

public:
   // constructors
   Acceleration() : ddx(0), ddy(0) { };
   Acceleration(double ddx, double ddy) : ddx(ddx), ddy(ddy) { };

   // getters
   double getDDX() const
   {
       return ddx;
   };

   double getDDY() const
   {
       return ddy;
   };
                                     
   // setters                        
   void setDDX(double inDdx)
   {
       ddx = inDdx;
   };

   void setDDY(double inDdy)
   {
       ddy = inDdy;
   };

   void set(const Angle& a, double magnitude);

   void addDDX(double inDdx)
   {
       ddx +=inDdx;
   };

   void addDDY(double inDdy)
   {
       ddy += inDdy;
   };

   void add(const Acceleration& rhs);
   

private:
   double ddx;     // horizontal acceleration
   double ddy;     // vertical acceleration
};



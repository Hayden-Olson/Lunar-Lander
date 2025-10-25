/***********************************************************************
 * Source File:
 *    LANDER
 * Author:
 *    Br. Helfrich
 * Summary:
 *    All the information about the lunar lander
 ************************************************************************/

#include "lander.h"
#include "acceleration.h"

 /***************************************************************
  * RESET
  * Reset the lander and its position to start the game over
  ***************************************************************/
void Lander :: reset(const Position & posUpperRight)
{
   
    //resets to one pixel from the right side, at a variable height
    pos.setX(399);
    pos.setY(random(300, 380));

    //randomizes the velocity within reason
    velocity.setDX(random(-10.0, -4.0));
    velocity.setDY(random( - 2.0, 2.0));

    //resets the angle
    angle.setRadians(M_PI / 2.0);

    //refuels and revives
    status = PLAYING;
    fuel = 5000.0;
}

/***************************************************************
 * DRAW
 * Draw the lander on the screen
 ***************************************************************/
void Lander :: draw(const Thrust & thrust, ogstream & gout) const
{
    gout.drawLander(pos, angle.getRadians());
    gout.drawLanderFlames(pos, angle.getRadians(), thrust.isMain(), thrust.isCounter(), thrust.isClock());

}

/***************************************************************
 * INPUT
 * Accept input from the Neil Armstrong
 ***************************************************************/
Acceleration Lander :: input(const Thrust& thrust, double gravity)
{
    Acceleration accel;

    angle.add(thrust.rotation());

    //gravity
    accel.setDDY(-gravity);

    if (thrust.isMain())
    {
        double mainThrust = thrust.mainEngineThrust(); 
        double radians = angle.getRadians();  

        //thrust X and Y 
        double ddx = mainThrust * -sin(radians);
        double ddy = mainThrust * cos(radians);

        accel.addDDX(ddx);
        accel.addDDY(ddy);
    }

    //fuel -= 10; might need this later

    return accel;
}

/******************************************************************
 * COAST
 * What happens when we coast?
 *******************************************************************/
void Lander :: coast(Acceleration & acceleration, double time)
{
    //  v = v + a * t
    velocity.addDX(acceleration.getDDX() * time);
    velocity.addDY(acceleration.getDDY() * time);

    //  p = p + v * t
    pos.addX(velocity.getDX() * time);
    pos.addY(velocity.getDY() * time);
}

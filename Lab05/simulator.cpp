/**********************************************************************
 * LAB 06
 * Lunar Lander simulation. This is the Game class and main()
 **********************************************************************/

#include "position.h"    // everything should have a point
#include "angle.h"       // angle of the lander
#include "uiInteract.h"  // for INTERFACE
#include "uiDraw.h"      // for RANDOM and DRAW*
#include "ground.h"      // for GROUND
#include "test.h"        // for the unit tests
#include <cmath>         // for SQRT
#include <cassert>       // for ASSERT
#include "star.h" 
#include "lander.h"
#include "thrust.h"
#include "acceleration.h"
using namespace std;


/*************************************************************************
 * SIMULATOR
 * Everything pertaining to the simulator.
 *************************************************************************/
class Simulator
{
public:
    // set up the simulator
    Simulator(const Position& posUpperRight) : ground(posUpperRight), lander(posUpperRight) {}

    // display stuff on the screen
    void display();

    unsigned char phase;
    Angle a;
    Ground ground;
    Star star;
    Lander lander;
    Thrust thrust;
};

/**********************************************************
 * DISPLAY
 * Draw on the screen
 **********************************************************/
void Simulator::display()
{
    ogstream gout;
    
    // draws the stars behind the ground
    //stars will need to be a for loop calling an array, once other stuff starts working.
    star.draw(gout);
    ground.draw(gout);

    //lander
    lander.draw(thrust ,gout);
    

}


/*************************************
 * CALLBACK
 * Handle one frame of the simulator
 **************************************/
void callBack(const Interface* pUI, void* p)
{
    // the first step is to cast the void pointer into a game object. This
    // is the first step of every single callback function in OpenGL. 
    Simulator* pSimulator = (Simulator*)p;

    pSimulator->thrust.set(pUI);
    Thrust thrust = pSimulator->thrust;
    Acceleration accel = pSimulator->lander.input(thrust, 1.0);

    pSimulator->lander.coast(accel, 0.1);

    // draw the game
    pSimulator->display();

    if (pSimulator->ground.hitGround(pSimulator->lander.getPosition(), pSimulator->lander.getWidth()) && !pSimulator->ground.onPlatform(pSimulator->lander.getPosition(), pSimulator->lander.getWidth()))
    {
        pSimulator->lander.crash();
    }
    else if (pSimulator->ground.onPlatform(pSimulator->lander.getPosition(), pSimulator->lander.getWidth()))
    {
        if (pSimulator->lander.getSpeed() < 4)
        {
            pSimulator->lander.land();
        }
        else
        {
            pSimulator->lander.crash();
        }
    }
    

  
    

}

/*********************************
 * Main is pretty sparse.  Just initialize
 * my LM type and call the display engine.
 * That is all!
 *********************************/
#ifdef _WIN32
#include <windows.h>
int WINAPI WinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR pCmdLine,
    _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
    // Run the unit tests
    testRunner();


    // Initialize OpenGL
    Position posUpperRight(400, 400);
    Interface ui("Lunar Lander", posUpperRight);

    // Initialize the game class
    Simulator simulator(posUpperRight);

    // set everything into action
    ui.run(callBack, (void*)&simulator);

    return 0;
}

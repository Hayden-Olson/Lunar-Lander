/***********************************************************************
 * Source:
 *    Template
 * Summary:
 *    Just call the Template unit tests
 * Author:
 *    James Helfrich
 ************************************************************************/

#include "testTemplate.h"

/*********************************
 * MAIN
  ********************************/
int main()
{
   TestFindBiggest().run();
   TestStack().run();

   return 0;
}
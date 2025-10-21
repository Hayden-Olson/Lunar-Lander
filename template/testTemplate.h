/***********************************************************************
 * Header:
 *    TEST  TEMPLATE
 * Summary:
 *    All the unit tests for the Template class and function
 * Author
 *    Br. Helfrich
 ************************************************************************/

#pragma once

#include "template.h"
#include "unitTest.h"
#include <sstream>

 /************************************
  * FIND BIGGEST
  ************************************/
class TestFindBiggest : public UnitTest
{
public:
   void run()
   {
      reset();

      // integer
      test_findBiggest_int1();
      test_findBiggest_int4();

      // character
      test_findBiggest_char8();

      // double
      test_findBiggest_double2();
      test_findBiggest_double6();

      report("Find Biggest");
   }
private:

/***************************************
 * INTEGER
 ***************************************/

   // find biggest integer in array of size 1
   void test_findBiggest_int1()
   {  // setup
      int array[1] = {99};
      int numElements = 1;
      int result = -1;
      // exercise
      result = findBiggest<int>(array, numElements);
      // verify
      assertCondition(result == 99);
      assertCondition(array[0] == 99);
      assertCondition(numElements == 1);
   }  // teardown

   // find biggest integer in array of size 4
   void test_findBiggest_int4()
   {  // setup
      int array[4] = { 00, 11, 999, 33 };
      int numElements = 4;
      int result = -1;
      // exercise
      result = findBiggest<int>(array, numElements);
      // verify
      assertCondition(result == 999);
      assertCondition(array[0] == 00);
      assertCondition(array[1] == 11);
      assertCondition(array[2] == 999);
      assertCondition(array[3] == 33);
      assertCondition(numElements == 4);
   }  // teardown

/***************************************
 * CHARACTER
 ***************************************/

   // find biggest character in a 8-character string
   void test_findBiggest_char8()
   {  // setup
      char array[] = "ABCDEFgH";
      int numElements = 8;
      char result = '\t';
      // exercise
      result = findBiggest<char>(array, numElements);
      // verify
      assertCondition(result == 'g');
      assertCondition(array[0] == 'A');
      assertCondition(array[1] == 'B');
      assertCondition(array[2] == 'C');
      assertCondition(array[3] == 'D');
      assertCondition(array[4] == 'E');
      assertCondition(array[5] == 'F');
      assertCondition(array[6] == 'g');
      assertCondition(array[7] == 'H');
      assertCondition(numElements == 8);
   }  // teardown

/***************************************
 * DOUBLE
 ***************************************/

   // find biggest double in an array of size 2
   void test_findBiggest_double2()
   {  // setup
      double array[] = { 9.9, 8.8 };
      int numElements = 2;
      double result = 99.9;
      // exercise
      result = findBiggest<double>(array, numElements);
      // verify
      assertCondition(result == 9.9);
      assertCondition(array[0] == 9.9);
      assertCondition(array[1] == 8.8);
      assertCondition(numElements == 2);
   }  // teardown

   // find biggest double in an array of size 6
   void test_findBiggest_double6()
   {  // setup
      double array[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
      int numElements = 6;
      double result = 99.9;
      // exercise
      result = findBiggest<double>(array, numElements);
      // verify
      assertCondition(result == 6.6);
      assertCondition(array[0] == 1.1);
      assertCondition(array[1] == 2.2);
      assertCondition(array[2] == 3.3);
      assertCondition(array[3] == 4.4);
      assertCondition(array[4] == 5.5);
      assertCondition(array[5] == 6.6);
      assertCondition(numElements == 6);
   }  // teardown

};


/************************************
 * FIND Stack
 ************************************/
class TestStack : public UnitTest
{
public:
   void run()
   {
      reset();

      // Constructor
      test_construct_integer();
      test_construct_double();

      // Push
      test_push_emptyInteger();
      test_push_nonemptyInteger();
      test_push_fullDouble();

      // Pop
      test_pop_emptyChar();
      test_pop_nonemptyFloat();

      // Top
      test_top_emptyInteger();
      test_top_emptyChar();
      test_top_nonemptyDouble();

      report("Stack");
   }
private:

   /***************************************
    * CONSTRUCT
    ***************************************/

    // default constructor integer
   void test_construct_integer()
   {  // setup
      // exercise
      Stack<int> s;
      // verify
      assertCondition(s.numElements == 0);
   }  // teardown

    // default constructor double
   void test_construct_double()
   {  // setup
      // exercise
      Stack<double> s;
      // verify
      assertCondition(s.numElements == 0);
   }  // teardown

   /***************************************
    * PUSH
    ***************************************/

   // push an integer onto an empty stack
   void test_push_emptyInteger()
   {  // setup
      Stack<int> s;
      s.numElements = 0;
      int value = 99;
      // exercise
      s.push(value);
      // verify
      assertCondition(s.numElements == 1);
      assertCondition(value == 99);
      assertCondition(s.data[0] == 99);
   }  // teardown

   // push an integer onto an non-empty stack
   void test_push_nonemptyInteger()
   {  // setup
      Stack<int> s;
      s.numElements = 3;
      s.data[0] = 11;
      s.data[1] = 22;
      s.data[2] = 33;
      int value = 99;
      // exercise
      s.push(value);
      // verify
      assertCondition(s.numElements == 4);
      assertCondition(value == 99);
      assertCondition(s.data[0] == 11);
      assertCondition(s.data[1] == 22);
      assertCondition(s.data[2] == 33);
      assertCondition(s.data[3] == 99);
   }  // teardown

   // push a double onto a full stack
   void test_push_fullDouble()
   {  // setup
      Stack<double> s;
      s.numElements = 10;
      s.data[0] = 1.1;
      s.data[1] = 2.2;
      s.data[2] = 3.3;
      s.data[3] = 4.4;
      s.data[4] = 5.5;
      s.data[5] = 6.6;
      s.data[6] = 7.7;
      s.data[7] = 8.8;
      s.data[8] = 9.9;
      s.data[9] = 10.0;
      double value = 99.9;
      // exercise
      s.push(value);
      // verify
      assertCondition(s.numElements == 10);
      assertCondition(value == 99.9);
      assertCondition(s.data[0] == 1.1);
      assertCondition(s.data[1] == 2.2);
      assertCondition(s.data[2] == 3.3);
      assertCondition(s.data[3] == 4.4);
      assertCondition(s.data[4] == 5.5);
      assertCondition(s.data[5] == 6.6);
      assertCondition(s.data[6] == 7.7);
      assertCondition(s.data[7] == 8.8);
      assertCondition(s.data[8] == 9.9);
      assertCondition(s.data[9] == 10.0);
   }  // teardown

   /***************************************
    * POP
    ***************************************/

   // pop an char from an empty stack
   void test_pop_emptyChar()
   {  // setup
      Stack<char> s;
      s.numElements = 0;
      // exercise
      s.pop();
      // verify
      assertCondition(s.numElements == 0);
   }  // teardown

   // pop a float from an non-empty stack
   void test_pop_nonemptyFloat()
   {  // setup
      Stack<float> s;
      s.numElements = 5;
      s.data[0] = (float)1.1;
      s.data[1] = (float)2.2;
      s.data[2] = (float)3.3;
      s.data[3] = (float)4.4;
      s.data[4] = (float)5.5;
      // exercise
      s.pop();
      // verify
      assertCondition(s.numElements == 4);
      assertValues(s.data[0], 1.1, 0.001);
      assertValues(s.data[1], 2.2, 0.001);
      assertValues(s.data[2], 3.3, 0.001);
      assertValues(s.data[3], 4.4, 0.001);
   }  // teardown

   /***************************************
    * TOP
    ***************************************/

   // top of an empty integer stack
   void test_top_emptyInteger()
   {  // setup
      Stack<int> s;
      s.numElements = 0;
      int result = 99;
      // exercise
      result = s.top();
      // verify
      assertCondition(s.numElements == 0);
      assertCondition(result == 0);
   }  // teardown

   // top of an empty character stack
   void test_top_emptyChar()
   {  // setup
      Stack<char> s;
      s.numElements = 0;
      char result = 'x';
      // exercise
      result = s.top();
      // verify
      assertCondition(s.numElements == 0);
      assertCondition(result == '\0');
   }  // teardown

   // top of a non-empty double stack
   void test_top_nonemptyDouble()
   {  // setup
      Stack<double> s;
      s.numElements = 8;
      s.data[0] = 1.1;
      s.data[1] = 2.2;
      s.data[2] = 3.3;
      s.data[3] = 4.4;
      s.data[4] = 5.5;
      s.data[5] = 6.6;
      s.data[6] = 7.7;
      s.data[7] = 8.8;
      double result = 99.9;
      // exercise
      result = s.top();
      // verify
      assertCondition(s.numElements == 8);
      assertCondition(s.data[0] == 1.1);
      assertCondition(s.data[1] == 2.2);
      assertCondition(s.data[2] == 3.3);
      assertCondition(s.data[3] == 4.4);
      assertCondition(s.data[4] == 5.5);
      assertCondition(s.data[5] == 6.6);
      assertCondition(s.data[6] == 7.7);
      assertCondition(s.data[7] == 8.8);
      assertCondition(result == 8.8);
   }  // teardown
};
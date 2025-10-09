/***********************************************************************
 * Header:
 *    TEST CONTAINERS
 * Summary:
 *    All the unit tests for the containers functions
 * Author
 *    Br. Helfrich
 ************************************************************************/

#pragma once

#include "unitTest.h"
#include <string>
#include <list>
#include <vector>
using namespace std;

list<string> arrayToList(string a[], int num);
list<string> arrayToListBackwards(string a[], int num);
vector<string> listToVector(const list<string> & l);
vector<string> listToVectorBackwards(const list<string>& l);
bool findElementInVector(const vector<string> & v, const string& element);


 /************************************
  * TEST COLLECTION
  ************************************/
class TestCollection : public UnitTest
{
public:
   void run()
   {
      reset();

      // array to list
      test_arrayToList_empty();
      test_arrayToList_one();
      test_arrayToList_three();

      // array to list backwards
      test_arrayToListBackwards_empty();
      test_arrayToListBackwards_one();
      test_arrayToListBackwards_three();

      // list to vector
      test_listToVector_empty();
      test_listToVector_one();
      test_listToVector_three();

      // list to vector backwards
      test_listToVectorBackwards_empty();
      test_listToVectorBackwards_one();
      test_listToVectorBackwards_three();

      // find if an element is in a vector
      test_findElementInVector_empty();
      test_findElementInVector_oneNope();
      test_findElementInVector_oneFound();
      test_findElementInVector_threeNope();
      test_findElementInVector_threeFound();

      report("Containers");
   }
private:

   /*****************************
    * ARRAY TO LIST
    *****************************/

   // arrayToList() : empty
   void test_arrayToList_empty()
   {  // setup
      string a[1] = { string("zero")};
      int num = 0;
      list<string> result;
      // exercise
      result = arrayToList(a, num);
      // verify
      assertCondition(result.size() == 0);
   }  // teardown

   // arrayToList() : one element
   void test_arrayToList_one()
   {  // setup
      string a[1] = { string("zero") };
      int num = 1;
      list<string> result;
      // exercise
      result = arrayToList(a, num);
      // verify
      assertCondition(result.size() == 1);
      if (!result.empty())
         assertCondition(result.front() == string("zero"));
   }  // teardown

   // arrayToList() : three elements
   void test_arrayToList_three()
   {  // setup
      string a[4] = 
      { 
         string("zero"), string("one"), string("two"), string("three") 
      };
      int num = 3;
      list<string> result;
      // exercise
      result = arrayToList(a, num);
      // verify
      assertCondition(result.size() == 3);
      auto it = result.begin();
      if (!result.empty())
      {
         assertCondition(*(it++) == string("zero"));
         assertCondition(*(it++) == string("one"));
         assertCondition(*(it++) == string("two"));
      }
   }  // teardown

   /*****************************
    * ARRAY TO LIST BACKWARDS
    *****************************/

    // arrayToListBackwards() : empty
   void test_arrayToListBackwards_empty()
   {  // setup
      string a[1] = { string("zero") };
      int num = 0;
      list<string> result;
      // exercise
      result = arrayToListBackwards(a, num);
      // verify
      assertCondition(result.size() == 0);
   }  // teardown

   // arrayToListBackwards() : one element
   void test_arrayToListBackwards_one()
   {  // setup
      string a[1] = { string("zero") };
      int num = 1;
      list<string> result;
      // exercise
      result = arrayToListBackwards(a, num);
      // verify
      assertCondition(result.size() == 1);
      if (!result.empty())
         assertCondition(result.front() == string("zero"));
   }  // teardown

   // arrayToListBackwards() : three elements
   void test_arrayToListBackwards_three()
   {  // setup
      string a[4] =
      {
         string("zero"), string("one"), string("two"), string("three")
      };
      int num = 3;
      list<string> result;
      // exercise
      result = arrayToListBackwards(a, num);
      // verify
      assertCondition(result.size() == 3);
      auto it = result.begin();
      if (!result.empty())
      {
         assertCondition(*(it++) == string("two"));
         assertCondition(*(it++) == string("one"));
         assertCondition(*(it++) == string("zero"));
      }
   }  // teardown

   /*****************************
    * LIST TO VECTOR
    *****************************/

   // listToVector() : empty
   void test_listToVector_empty()
   {  // setup
      list<string> l;
      vector<string> result;
      // exercise
      result = listToVector(l);
      // verify
      assertCondition(result.size() == 0);
   }  // teardown

   // listToVector() : one
   void test_listToVector_one()
   {  // setup
      list<string> l{string("zero")};
      vector<string> result;
      // exercise
      result = listToVector(l);
      // verify
      assertCondition(result.size() == 1);
      if (!result.empty())
         assertCondition(result[0] == string("zero"));
   }  // teardown

   // listToVector() : three
   void test_listToVector_three()
   {  // setup
      list<string> l{ string("zero"), string("one"), string("two") };
      vector<string> result;
      // exercise
      result = listToVector(l);
      // verify
      assertCondition(result.size() == 3);
      if (!result.empty())
      {
         assertCondition(result[0] == string("zero"));
         assertCondition(result[1] == string("one"));
         assertCondition(result[2] == string("two"));
      }
   }  // teardown


   /*****************************
    * LIST TO VECTOR BACKWARDS
    *****************************/

    // listToVectorBackwards() : empty
   void test_listToVectorBackwards_empty()
   {  // setup
      list<string> l;
      vector<string> result;
      // exercise
      result = listToVectorBackwards(l);
      // verify
      assertCondition(result.size() == 0);
   }  // teardown

   // listToVectorBackwards() : one
   void test_listToVectorBackwards_one()
   {  // setup
      list<string> l{ string("zero") };
      vector<string> result;
      // exercise
      result = listToVectorBackwards(l);
      // verify
      assertCondition(result.size() == 1);
      if (!result.empty())
         assertCondition(result[0] == string("zero"));
   }  // teardown

   // listToVectorBackwards() : three
   void test_listToVectorBackwards_three()
   {  // setup
      list<string> l{ string("zero"), string("one"), string("two") };
      vector<string> result;
      // exercise
      result = listToVectorBackwards(l);
      // verify
      assertCondition(result.size() == 3);
      if (!result.empty())
      {
         assertCondition(result[0] == string("two"));
         assertCondition(result[1] == string("one"));
         assertCondition(result[2] == string("zero"));
      }
   }  // teardown

   /*****************************
    * FIND ELEMENT IN VECTOR
    *****************************/

    // findElementInVector() : empty
   void test_findElementInVector_empty()
   {  // setup
      vector<string> v;
      string element("Nope");
      bool result = true;
      // exercise
      result = findElementInVector(v, element);
      // verify
      assertCondition(result == false);
      assertCondition(v.size() == 0);
      assertCondition(element == string("Nope"));
   }  // teardown

    // findElementInVector() : one element not there
   void test_findElementInVector_oneNope()
   {  // setup
      vector<string> v{string("zero")};
      string element("Nope");
      bool result = true;
      // exercise
      result = findElementInVector(v, element);
      // verify
      assertCondition(result == false);
      assertCondition(v.size() == 1);
      assertCondition(v[0] == string("zero"));
      assertCondition(element == string("Nope"));
   }  // teardown

    // findElementInVector() : one element there
   void test_findElementInVector_oneFound()
   {  // setup
      vector<string> v{ string("zero") };
      string element("zero");
      bool result = false;
      // exercise
      result = findElementInVector(v, element);
      // verify
      assertCondition(result == true);
      assertCondition(v.size() == 1);
      assertCondition(v[0] == string("zero"));
      assertCondition(element == string("zero"));
   }  // teardown

    // findElementInVector() : three element Nope
   void test_findElementInVector_threeNope()
   {  // setup
      vector<string> v{ string("zero"), string("one"), string("two") };
      string element("Nope");
      bool result = true;
      // exercise
      result = findElementInVector(v, element);
      // verify
      assertCondition(result == false);
      assertCondition(v.size() == 3);
      assertCondition(v[0] == string("zero"));
      assertCondition(v[1] == string("one"));
      assertCondition(v[2] == string("two"));
      assertCondition(element == string("Nope"));
   }  // teardown

    // findElementInVector() : three element Found
   void test_findElementInVector_threeFound()
   {  // setup
      vector<string> v{ string("zero"), string("one"), string("two") };
      string element("two");
      bool result = false;
      // exercise
      result = findElementInVector(v, element);
      // verify
      assertCondition(result == true);
      assertCondition(v.size() == 3);
      assertCondition(v[0] == string("zero"));
      assertCondition(v[1] == string("one"));
      assertCondition(v[2] == string("two"));
      assertCondition(element == string("two"));
   }  // teardown
};


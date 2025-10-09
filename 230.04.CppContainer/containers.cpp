/*************************************************************
 * 1. Name:
 *      Mason Allen & Hayden Olson
 * 2. Assignment Name:
 *      Practice 04: Contaiers
 * 3. Assignment Description:
 *      Work with a list and a vector
 * 4. What was the hardest part? Be as specific as possible.
 *      -a paragraph or two about how the assignment went for you-
 * 5. How long did it take for you to complete the assignment?
 *      -total time in hours: reading the assignment, submitting, etc.
 **************************************************************/


#include "testContainers.h"
#include <string>
#include <list>
using namespace std;

list<string> arrayToList(string a[], int num)
{
	list<string> outList;

	for (int i = 0; i < num; i++)
	{
		outList.push_back(a[i]);
	}
	return outList;
}

/*****************************
 * ARRAY TO LIST BACKWARDS
 *****************************/
list<string> arrayToListBackwards(string a[], int num)
{
	list<string> outList;

	for (int i = num; i > 0; i--)
	{
		outList.push_back(a[i]);
	}
	return outList;
}

/*****************************
 * LIST TO VECTOR
 *****************************/
vector<string> listToVector(const list<string> & l)
{
   return vector<string>();
}

/*****************************
 * LIST TO VECTOR BACKWARDS
 *****************************/
vector<string> listToVectorBackwards(const list<string>& l)
{
   return vector<string>();
}

/*****************************
 * FIND ELEMENT IN VECTOR
 *****************************/
bool findElementInVector(const vector<string> & v, const string& element)
{
   return false;
}

/*****************************
 * MAIN
 *****************************/
int main()
{
   TestCollection().run();
   return 0;
}

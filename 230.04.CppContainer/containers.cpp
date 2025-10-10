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
	
	//just a simple for loop using push.back()
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

	//just reversing the start and end points, and makign it deincrement. might need to make small adjustments after testing.
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
	//iterates through simply using a built-in vector constructor
	return vector<string>(l.begin(), l.end());
}

/*****************************
 * LIST TO VECTOR BACKWARDS
 *****************************/
vector<string> listToVectorBackwards(const list<string>& l)
{
	vector<string> vector = {};
	for (auto rit = l.rbegin(); rit != l.rend(); rit++)
	{
		vector.push_back(*rit);
	}
   return vector;
}

/*****************************
 * FIND ELEMENT IN VECTOR
 *****************************/
bool findElementInVector(const vector<string>& v, const string& element)
{
	for (auto it = v.begin(); it != v.end(); it++)
	{
		if (*it == element)
			return true;
		else
			return false;
	}
}

/*****************************
 * MAIN
 *****************************/
int main()
{
   TestCollection().run();
   return 0;
}

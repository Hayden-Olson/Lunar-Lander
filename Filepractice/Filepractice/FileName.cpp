#include <fstream>
#include <iostream>

using namespace std;

/********************************
 * Simple program to write a file
 ********************************/

/**************
 * READ BALANCE
 **************/

int readBalance()
{
	ifstream inFile;
	int balance;
	inFile.open("balance.txt");
	if (!inFile)
	{
		cerr << "Error opening file" << endl;
		return -1;
	}
	inFile >> balance;
	inFile.close();
	return balance;
}

/*****************
 * DISPLAY BALANCE 
 *****************/

string displayBalance(int balance)
{
	return "";
}

/****************
 * UPDATE BALANCE
 ****************/

void updateBalance(int newBalance)
{
	ofstream outFile;
	outFile.open("balance.txt");
	if (!outFile)
	{
		cerr << "Error opening file" << endl;
		return;
	}
	outFile << newBalance;
	outFile.close();
}

/******
 * MAIN
 ******/

int main()
{
	return 0;
}
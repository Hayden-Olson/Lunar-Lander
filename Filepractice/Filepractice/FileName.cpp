#include <fstream>
#include <iostream>

using namespace std;

/********************************
 * Simple program to write a file
 ********************************/

/**************
 * READ BALANCE
 **************/

double readBalance()
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
	if (balance == -1)
	{
		return "Error reading balance";
	}
	else
	{
		cout << "Your balance is: $" << balance << endl;
		return "Balance displayed";
	}
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
	double balance = readBalance();
	displayBalance(balance);
	return 0;
}
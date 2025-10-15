#include <fstream>
#include <iostream>

using namespace std;

/************************************************
 * Simple program to display and write to a file.
 ************************************************/

/************************************************
 * READ BALANCE
 ************************************************/

double readBalance()
{
	ifstream inFile;
	double balance;
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

/************************************************
 * DISPLAY BALANCE 
 ************************************************/

string displayBalance(double balance)
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

/************************************************
 * UPDATE BALANCE
 ************************************************/

void updateBalance(double newBalance)
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

/************************************************
 * Prompt User for new Balalnce
 ************************************************/

double userInput()
{
	double newBalance;
	cout << "Please enter new balance to add:";
	cin >> newBalance;
	newBalance += readBalance();
	return newBalance;
}


/************************************************
 * MAIN
 ************************************************/

int main()
{
	double balance = readBalance();
	double newValue;
	displayBalance(balance);
	newValue = userInput();
	updateBalance(newValue);
	displayBalance(readBalance());

	return 0;
}
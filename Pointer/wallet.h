/*************************************************************
 * 1. Name:
 *      Hayden Olson & Mason Allen
 * 2. Module
 *      WALLET
 * 3. Assignment Description:
 *      A class to represent an wallet with multiple credit cards
 **************************************************************/

#pragma once

#include <cassert>

class TestWallet;

 /************************************
  * WALLET
  ************************************/
class Wallet
{
   friend TestWallet;

private:
	double accountSam;
	double accountSue;
	double* pCurrentAccount;

public:
	Wallet()
	{
		accountSam = 0.00;
		accountSue = 0.00;
		pCurrentAccount = &accountSam;
	}

	void updateSam(double amount)
	{
		accountSam += amount;
	}

	void updateSue(double amount)
	{
		accountSue += amount;
	}

	void updateCurrent(double amount)
	{
		*pCurrentAccount += amount;
	}

	int chooseSam()
	{
		return 0;
	}

	int chooseSue()
	{
		return 1;
	}

	int chooseCurrent()
	{
		return 0;
	}

	double getSam()
	{
		return 0.00;
	}

	double getSue()
	{
		return 0.00;
	}

	double getCurrent()
	{
		return 0.00;
	}
};


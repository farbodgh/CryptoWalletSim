#include "Wallet.h"
#include<iostream>

Wallet::Wallet(double balance) : _mbalance(balance) {};

void Wallet::AddValue(double amount, bool showLog)
{
	if (amount < 0)
	{
		std::cerr << "\nThis function only accepts a positive value, please try DecreaseValue() for decreasing the balance\n";
		return;
	}

	if (showLog)
	{
		std::cout << "\nThe wallet's balance was: " << _mbalance << "$ before the increase\n";
	}

	_mbalance += amount;

	if (showLog)
	{
		std::cout << "\nThe wallet's balance is: " << _mbalance << "$ after the increase\n";
	}
	
}

void Wallet::DecreaseValue(double amount, bool showLog)
{
	if (amount == 0 && showLog)
	{
		std::cout << "\n0 So there will be no change\n";
		return;
	}

	if (amount < 0)
	{
		std::cerr << "\nThis function only accepts a negative value, please try AddValue() for adding to the balance\n";
		return;
	}

	if (showLog)
	{
		std::cout << "\nThe wallet's balance was: " << _mbalance << "$ before the increase\n";
	}

	_mbalance += amount;

	if (showLog)
	{
		std::cout << "\nThe wallet's balance is: " << _mbalance << "$ after the increase\n";
	}

}


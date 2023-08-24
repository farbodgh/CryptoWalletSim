#include "Wallet.h"
#include <iostream>
#include "BitCoin.h"

Wallet::Wallet(double balance) : m_balance(balance) {};

void Wallet::AddValue(double amount, bool showLog)
{
	if (amount < 0)
	{
		std::cerr << "\nThis function only accepts a positive value, please try DecreaseValue() for decreasing the balance\n";
		return;
	}

	if (showLog)
	{
		std::cout << "\nThe wallet's balance was: " << m_balance << "$ before the increase\n";
	}

	m_balance += amount;

	if (showLog)
	{
		std::cout << "\nThe wallet's balance is: " << m_balance << "$ after the increase\n";
	}
	
}

void Wallet::DecreaseValue(double amount, bool showLog)
{
	if (amount == 0 && showLog)
	{
		std::cout << "\n0 So there will be no change\n";
		return;
	}

	if (amount > 0)
	{
		amount *= -1;
	}

	if (showLog)
	{
		std::cout << "\nThe wallet's balance was: " << m_balance << "$ before the deduction\n";
	}

	m_balance += amount;

	if (showLog)
	{
		std::cout << "\nThe wallet's balance is: " << m_balance << "$ after the increase\n";
	}

}

double Wallet::ReturnBalanceInBitCoin(const BitCoin& btc)const
{
	return (m_balance / btc.GetPrice());

}

void Wallet::ResetTheValueTo(double amount)
{
	m_balance = amount;
}

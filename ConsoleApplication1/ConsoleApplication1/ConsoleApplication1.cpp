// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <thread>
#include <cpr\cpr.h>
#include "json.hpp"
#include "BitCoin.h"
#include "Wallet.h"
#include "CommandProcessor.h"


//To Do
//Write a command processor class;
int main()
{
	Wallet wallet;
	BitCoin btc;
	CommandProcessor CLI;


	CLI.InitiatingTheProgram(wallet);
	CLI.CommandHandler(wallet, btc);

	/*
	std::string commands;
	BitCoin btc;
	while (1)
	{
		double amount;
		std::cout << "Please Enter the amount of money you have in your wallet(in usd)\n-> ";
		std::cin >> amount;
		Wallet wallet(amount);
		while (std::cin>> commands)
		{

		}
	}
	*/
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

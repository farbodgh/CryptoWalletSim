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

	std::thread cmdreader(&CommandProcessor::CommandReader, &CLI);
	std::thread cli(&CommandProcessor::CommandHandler, &CLI, std::ref(wallet), std::ref(btc));
	cli.join();
	cmdreader.join();

}



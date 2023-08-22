#include "CommandProcessor.h"
#include <iostream>
#include <string>
#include <conio.h>
#include "Wallet.h"
#include "BitCoin.h"


void CommandProcessor::InitiatingTheProgram(Wallet& wallet)
{
	double amount;
	std::cout << "Please Enter the amount of money that is inside your wallet\n->:";
	std::cin >> amount;
	wallet.ResetTheValueTo(amount);
}




void CommandProcessor::CommandHandler(Wallet& wallet, const BitCoin& btc)
{
	char command;
    bool showLog{ false };
	while ((command = _getch()) != 'q')
	{
		std::cout << "\n1)Press Q on the keyboard to exit the program.\n";
		std::cout << "2)Press R on the keyboard to get equivelant of your money in bitcoin.\n";
		std::cout << "3)Press A on the keyboard to add to the money you have.\n";
		std::cout << "4)Press D on the keyboard to decrease from the moeny you have.\n";
		std::cout << "5)Press R on the keyboard to reset the amount of money you have.\n";
		std::cout << "6)Press L on the keyboard to activate the live mode, live mode show usd to btc and your money in btc in each 5 seconds.\n";
        std::cout << "7) Press O on the keybaord to activate/ deactivate the Log Mode(Right now: " << showLog << ")\n";
        switch (command)
        {
        case 'r':
            while ((command = _getch()) != 'q')
            {
                std::cout << "\nPlease press q to go back to the menue\n";
                wallet.ReturnBalanceInBitCoin(btc);
            }
            break;
        case 'a':
                double amount;
                std::cout << "\nPlease Enter the amount you want to add: ";
                std::cin >> amount;
                wallet.AddValue(amount, showLog);
            break;
        case 'd':
            // Handle decreasing money
            // Example: wallet.DecreaseMoney();
            break;
        case 'l':
            // Handle activating live mode
            // Example: wallet.ActivateLiveMode();
            break;
        case 'o':
            showLog = !(showLog);
            break;
        default:
            std::cout << "Invalid command. Please try again.\n";
            break;
        }
	}
}



#include "CommandProcessor.h"
#include <iostream>
#include <string>
#include <conio.h>
#include "Wallet.h"
#include "BitCoin.h"
#include <chrono>

void CommandProcessor::InitiatingTheProgram(Wallet& wallet)
{
	double amount;
	std::cout << "Please Enter the amount of money that is inside your wallet\n->:";
	std::cin >> amount;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
	wallet.ResetTheValueTo(amount);
}




void CommandProcessor::m_PrintMenue(bool& showLog)
{
    std::cout << "\nPress b in any stage to go back to the main menue\n";
    std::cout << "1)Press Q on the keyboard to exit the program.\n";
    std::cout << "2)Press R on the keyboard to get equivelant of your money in bitcoin.\n";
    std::cout << "3)Press A on the keyboard to add to the money you have.\n";
    std::cout << "4)Press D on the keyboard to decrease from the moeny you have.\n";
    std::cout << "5)Press L on the keyboard to activate the live mode, live mode show usd to btc and your money in btc in each 2 seconds.\n";
    std::cout << "6) Press O on the keybaord to activate/ deactivate the Log Mode(Right now: " << showLog << ")\n";
}

void CommandProcessor::LiveBitcoinPrice(double updatePriod, Wallet& wallet,  BitCoin& btc)
{
    while (true)
    {
        if (m_command == 'b') break;
        //std::cout << std::this_thread::get_id() << "; m_command is: " << m_command;
        btc.PriceUpdater();
        std::cout << "\nCurrent price of the bitcoin in usd is: " << btc.GetPrice();
        std::cout << "The equivalent amount of money in your wallet in btc is: "
            << wallet.ReturnBalanceInBitCoin(btc) << std::endl;
        std::this_thread::sleep_for(std::chrono::duration<double>(updatePriod));
    }
   
}

void CommandProcessor::CommandHandler(Wallet& wallet, BitCoin& btc)
{
    //while (true)
    //{
    //    if (m_newInput)
    //    {
    //        std::cout << m_command;
    //        m_newInput = !m_newInput;
    //    }
    //}
    bool showLog{ false };
    double amount{ 0 };
	while (m_command != 'q')
	{
        switch (m_command)
        {
        case DEFAULT_VALUE:
            if (m_newInput)
            {
                m_PrintMenue(showLog);
                m_newInput = !m_newInput;
            }
            break;
        case 'r':
            std::cout << "\n\nyour money in btc is: ";
            std::cout << wallet.ReturnBalanceInBitCoin(btc);
            std::cout << "btc\n";
            m_newInput = !m_newInput;
            m_command = DEFAULT_VALUE;
            break;
        case 'a':
            std::cout << "\nPlease press b to go back to the menue\n";
            std::cout << "press m to add 1000$ to your wallet, press n to add 100$ to your wallet\n";
            while (m_command != 'b')
            {
                if (m_command == 'm' && m_newInput)
                {
                    wallet.AddValue(1000, showLog);
                    m_newInput = !m_newInput;
                }
                if (m_command == 'n' && m_newInput)
                {
                    wallet.AddValue(100, showLog);
                    m_newInput = !m_newInput;
                }
            }
            break;
        case 'd':
            std::cout << "\nPlease press b to go back to the menue\n";
            std::cout << "press m to deduct 1000$ from your wallet, press n to deduct 100$ from your wallet\n";
            while (m_command != 'b')
            {
                if (m_command == 'm' && m_newInput)
                {
                    wallet.DecreaseValue(1000, showLog);
                    m_newInput = !m_newInput;
                }
                if (m_command == 'n' && m_newInput)
                {
                    wallet.DecreaseValue(100, showLog);
                    m_newInput = !m_newInput;
                }
            }
            break;
        case 'l':
            //std::thread(&CommandProcessor::LiveBitcoinPrice, this, 10, std::ref(wallet), std::ref(btc)).join();
            LiveBitcoinPrice(2, wallet, btc);
            m_command = DEFAULT_VALUE;
            m_newInput = !m_newInput;
            break;
        case 'o':
            showLog = !showLog;
            m_newInput = !m_newInput;
            std::cout << "\nShow log mode has been changed to " << showLog << " successfully\n";
            m_command = DEFAULT_VALUE;
            break;
        default:
            std::cout << "Invalid command. Please try again.\n";
            m_PrintMenue(showLog);
            m_newInput = !m_newInput;
            m_command = DEFAULT_VALUE;
            break;
        }
	}
    
}

void CommandProcessor::CommandReader()
{
    while (m_command != 'q')
    {
        if (m_command == 'b' && !m_newInput)
        {
            std::lock_guard<std::mutex> lock(m_mutexGuard);
            m_command = DEFAULT_VALUE;
        }
        if (_kbhit()) 
        {
            std::cout <<"***m is: " << m_command << std::endl;
            std::lock_guard<std::mutex> lock(m_mutexGuard);
            m_command = _getch();
            m_newInput = true;
        }
    }
}



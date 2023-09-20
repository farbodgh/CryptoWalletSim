#pragma once
#include<thread>
#include<atomic>

class Wallet;
class BitCoin;

const char DEFAULT_VALUE = 'p';

class CommandProcessor
{
private:
	std::atomic<bool> m_newInput{ true };
	std::atomic<char> m_command{ DEFAULT_VALUE };
	void m_PrintMenue(bool&);
	void LiveBitcoinPrice(double, Wallet& wallet, BitCoin& btc);


public:
	void CommandHandler(Wallet&, BitCoin&);
	void CommandReader();
	void InitiatingTheProgram(Wallet&);
};


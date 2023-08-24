#pragma once
#include<mutex>
#include<thread>

class Wallet;
class BitCoin;

const char DEFAULT_VALUE = 'p';

class CommandProcessor
{
private:
	bool m_newInput = true;
	char m_command = DEFAULT_VALUE;
	void m_PrintMenue(bool&);
	void LiveBitcoinPrice(double, Wallet& wallet, BitCoin& btc);
	std::mutex m_mutexGuard;

public:
	void CommandHandler(Wallet&, BitCoin&);
	void CommandReader();
	void InitiatingTheProgram(Wallet&);
};


#pragma once

class Wallet;
class BitCoin;

class CommandProcessor
{
private:
	char m_command;


public:
	void CommandHandler(Wallet&, const BitCoin& );
	void InitiatingTheProgram(Wallet&);
};


#pragma once
#include <vector>
#include <string>
class BitCoin;

class Wallet
{
private:
	double m_balance{0};
	std::vector<std::string> m_logs;

public:
	Wallet() = default;
	Wallet(double balance);
	~Wallet() = default;


	void PrintBalanceInUSD(bool&& liveMode = false) const;
	void PrintBalanceInCrypto(bool&& liveMode = false) const;
	void AddValue(double amount, bool showLog = true);
	void DecreaseValue(double amount, bool showLog = true);
	void ResetTheValueTo(double amount);
	double ReturnBalanceInBitCoin(const BitCoin&) const;
};


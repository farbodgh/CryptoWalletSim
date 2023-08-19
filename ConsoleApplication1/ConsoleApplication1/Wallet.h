#pragma once
#include <vector>
#include <string>

class Wallet
{
private:
	double _mbalance{0};
	std::vector<std::string> m_logs;

public:
	Wallet() = default;
	Wallet(double balance);
	~Wallet() = default;


	void PrintBalanceInUSD(bool&& liveMode = false) const;
	void PrintBalanceInCrypto(bool&& liveMode = false) const;
	void AddValue(double amount, bool showLog = true);
	void DecreaseValue(double amount, bool showLog = true);
};


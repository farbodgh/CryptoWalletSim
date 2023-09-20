#pragma once


class BitCoin
{
private:
	double m_price;

public:
	void PriceUpdater();
	double GetPrice()const;
	BitCoin();
	//This class does not need to be copyable or moveable.
	BitCoin(const BitCoin&) = delete;
	BitCoin& operator=(const BitCoin&) = delete;
	BitCoin(BitCoin&&) = delete;
	BitCoin& operator=(BitCoin&&) = delete;

	~BitCoin() = default;

};



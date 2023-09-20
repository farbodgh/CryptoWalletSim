#include "BitCoin.h"
#include <iostream>
#include <cpr\cpr.h>
#include "json.hpp"


void BitCoin::PriceUpdater()
{
    std::string url = "https://www.blockchain.com/ticker";
    cpr::Response response = cpr::Get(cpr::Url{ url });

    if (!response.status_code == 200)
    {
        std::cerr << "Request failed: " << response.status_code << std::endl;
    }
    nlohmann::json bitCoinInfo = nlohmann::json::parse(response.text);
    double price = bitCoinInfo["USD"]["buy"];
    this->m_price = price;
}

BitCoin::BitCoin()
{
    std::string url = "https://www.blockchain.com/ticker";
    cpr::Response response = cpr::Get(cpr::Url{ url });

    if (!response.status_code == 200)
    {
        std::cerr << "Request failed: " << response.status_code << std::endl;
    }
    nlohmann::json bitCoinInfo = nlohmann::json::parse(response.text);
    double price = bitCoinInfo["USD"]["buy"];
    this->m_price = price;
}

double BitCoin::GetPrice() const
{
    return (m_price); 
}

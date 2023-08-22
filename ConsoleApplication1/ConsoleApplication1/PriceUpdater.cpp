#include "PriceUpdater.h"
#include <iostream>
#include <cpr\cpr.h>
#include "json.hpp"


double PriceUpdater::NewPrice()
{
    std::string url = "https://www.blockchain.com/ticker";
    cpr::Response response = cpr::Get(cpr::Url{ url });

    // Check if the request was successful
    if (!response.status_code == 200)
    {
        // Print an error message if the request was not successful
        std::cerr << "Request failed: " << response.status_code << std::endl;
    }
    nlohmann::json bitCoinInfo = nlohmann::json::parse(response.text);
    double price = bitCoinInfo["USD"]["buy"];
    return price;
}

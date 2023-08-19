// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <thread>
#include <cpr\cpr.h>
#include "json.hpp"

int main() {
    // URL of the website you want to retrieve data from
    std::string url = "https://example.com";

    // Make a GET request using CPR
    cpr::Response response = cpr::Get(cpr::Url{ url });

    // Check if the request was successful
    if (response.status_code == 200) {
        // Print the response body
        std::cout << "Response: " << response.text << std::endl;
    }
    else {
        // Print an error message if the request was not successful
        std::cerr << "Request failed: " << response.status_code << std::endl;
    }

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

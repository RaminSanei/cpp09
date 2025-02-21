#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>


class BitcoinExchange
{
    private:
    std::map<std::string, float> btcPrices;


    void loadBitcoinDB(const std::string& dbPath);
    std::string findClosestDate(const std::string& targetDate) const;
    bool isValidValue(float value) const;

public:
    BitcoinExchange();
    BitcoinExchange(const std::string& dbPath);
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);

    void processInputFile(const std::string& inputFilePath) const;
};
#endif
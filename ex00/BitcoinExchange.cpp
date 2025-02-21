#include "BitcoinExchange.hpp"

// Default Constructor
BitcoinExchange::BitcoinExchange() {}

// Parameterized Constructor
BitcoinExchange::BitcoinExchange(const std::string& dbPath) {
    loadBitcoinDB(dbPath);
}

// Destructor
BitcoinExchange::~BitcoinExchange() {}

// Copy Constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    this->btcPrices = other.btcPrices;
}

// Copy Assignment Operator
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        this->btcPrices = other.btcPrices;
    }
    return *this;
}

// Load Bitcoin price database from CSV file
void BitcoinExchange::loadBitcoinDB(const std::string& dbPath) {
    std::ifstream dbFile(dbPath);
    std::string line;

    if (!dbFile.is_open()) {
        throw std::runtime_error("Error: could not open Bitcoin database file.");
    }

    while (std::getline(dbFile, line)) {
        std::istringstream iss(line);
        std::string date;
        float price;

        if (std::getline(iss, date, ',') && iss >> price) {
            btcPrices[date] = price;
        }
    }

    dbFile.close();
}

// Find the closest date in the database
std::string BitcoinExchange::findClosestDate(const std::string& targetDate) const {
    auto it = btcPrices.lower_bound(targetDate);

    if (it == btcPrices.begin()) {
        return it->first;
    }
    if (it == btcPrices.end() || it->first != targetDate) {
        --it;
    }

    return it->first;
}

// Validate the value (must be between 0 and 1000)
bool BitcoinExchange::isValidValue(float value) const {
    return (value >= 0 && value <= 1000);
}

// Process the input file and calculate Bitcoin values
void BitcoinExchange::processInputFile(const std::string& inputFilePath) const {
    std::ifstream inputFile(inputFilePath);

    if (!inputFile.is_open()) {
        throw std::runtime_error("Error: could not open input file.");
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string date, valueStr;
        float value;

        if (std::getline(iss, date, '|') && iss >> valueStr) {
            date.erase(date.find_last_not_of(' ') + 1); // Trim trailing spaces
            valueStr.erase(0, valueStr.find_first_not_of(' ')); // Trim leading spaces

            try {
                value = std::stof(valueStr);
                if (!isValidValue(value)) {
                    std::cerr << "Error: not a positive number or too large a number." << std::endl;
                    continue;
                }

                std::string closestDate = findClosestDate(date);
                float btcPrice = btcPrices.at(closestDate);
                float result = value * btcPrice;

                std::cout << date << " => " << value << " = " << std::fixed << std::setprecision(2) << result << std::endl;
            } catch (const std::invalid_argument&) {
                std::cerr << "Error: bad input => " << date << std::endl;
            } catch (const std::out_of_range&) {
                std::cerr << "Error: date not found in database => " << date << std::endl;
            }
        } else {
            std::cerr << "Error: bad input => " << line << std::endl;
        }
    }

    inputFile.close();
}
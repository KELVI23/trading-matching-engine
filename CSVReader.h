#pragma once

#include "OrderBookEntry.h"
#include <vector>
#include <string>
#include "Candlestick.h"

class CSVReader
{
    public:
        CSVReader();

        static std::vector<OrderBookEntry> readCSV(std::string csvFile);
        static std::vector<std::string> tokenise(std::string csvLine, char separator);
        static std::vector<Candlestick> computeCandlestickData(std::vector<OrderBookEntry>& entries);
        static double computeAveragePrice(std::vector<OrderBookEntry>& entries);

        static OrderBookEntry stringsToOBE(std::string price,
            std::string amount,
            std::string timestamp,
            std::string product,
            OrderBookType OrderBookType);

private:
    static OrderBookEntry stringsToOBE(std::vector<std::string> strings);
     
}; 

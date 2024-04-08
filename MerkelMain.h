#pragma once

#include <vector>
#include "OrderBookEntry.h"
#include "OrderBook.h"
#include "Candlestick.h"
#include "Wallet.h"
#include "TechnicalAnalysis.h"

class MerkelMain
{
    public:
        MerkelMain();
        /** Call this to start the sim */
        void init();
    private: 
        //void loadOrderBook();
        void printMenu();
        void printHelp();
        void printMarketStats();
        void enterOffer();
        void enterBid();
        void printWallet();
        void gotoNextTimeframe(const std::string& currencyPair);
        int getUserOption();
        void processUserOption(int userOption);
        void enterAsk();
        void plotVolumeData(const std::vector<OrderBookEntry>& entries, const std::string& currencyPair);
        void plotPriceData(const std::vector<OrderBookEntry>& entries, const std::string& currencyPair);
        std::string currentTime;

        //OrderBook orderBook{ "20200317.csv" };
        OrderBook orderBook{ "20200601.csv" };
        Wallet wallet;

}; 

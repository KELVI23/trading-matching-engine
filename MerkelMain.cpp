#include "MerkelMain.h"
#include <iostream>
#include <vector>
#include "OrderBookEntry.h"
#include "CSVReader.h"
#include "Candlestick.h"
#include "TechnicalAnalysis.h"

MerkelMain::MerkelMain()
{


}

void MerkelMain::init()
{
    int input;
    currentTime = orderBook.getEarliestTime();

    wallet.insertCurrency("BTC", 10);
    while (true)
    {
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
}


void MerkelMain::printMenu()
{
    // 1 print help
    std::cout << "1: Print help " << std::endl;
    // 2 print exchange stats
    std::cout << "2: Print exchange stats" << std::endl;
    // 3 make an offer
    std::cout << "3: Make an ask " << std::endl;
    // 4 make a bid 
    std::cout << "4: Make a bid " << std::endl;
    // 5 print wallet
    std::cout << "5: Print wallet " << std::endl;
    //6 plotVolumeData
    std::cout << "6: Plot Volume Data " << std::endl;
    //7 plotPriceData
    std::cout << "7: Plot Price Data " << std::endl;
    // 8 continue   
    std::cout << "8: Continue " << std::endl;

    std::cout << "============== " << std::endl;

    std::cout << "Current time is: " << currentTime << std::endl;
}

void MerkelMain::printHelp()
{
    std::cout << "Help - your aim is to make money. Analyse the market and make bids and offers. " << std::endl;
}

void MerkelMain::printMarketStats()
{
    for (std::string const& p : orderBook.getKnownProducts())
    {
        std::cout << "Product: " << p << std::endl;
        std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask,
            p, currentTime);
        std::cout << "Asks seen: " << entries.size() << std::endl;
        std::cout << "Max ask: " << OrderBook::getHighPrice(entries) << std::endl;
        std::cout << "Min ask: " << OrderBook::getLowPrice(entries) << std::endl;
    }

}

void MerkelMain::enterAsk()
{
    std::cout << "Make an ask - enter the amount: product,price, amount, eg  ETH/BTC,200,0.5" << std::endl;
    std::string input;
    std::getline(std::cin, input);

    std::vector<std::string> tokens = CSVReader::tokenise(input, ',');
    if (tokens.size() != 3)
    {
        std::cout << "MerkelMain::enterAsk Bad input! " << input << std::endl;
    }
    else {
        try {
            OrderBookEntry obe = CSVReader::stringsToOBE(
                tokens[1],
                tokens[2],
                currentTime,
                tokens[0],
                OrderBookType::ask
            );
            obe.username = "simuser";

            if (wallet.canFulfillOrder(obe)) {
                std::cout << "Wallet looks good. " << std::endl;
                orderBook.insertOrder(obe);
            }
            else {
                std::cout << "Wallet has insufficient funds" << std::endl;
            }
        }
        catch (const std::exception& e)
        {
            std::cout << " MerkelMain::enterAsk Bad input " << std::endl;
        }
    }

    std::cout << "You typed: " << input << std::endl;
}

void MerkelMain::enterBid()
{
    std::cout << "Make a bid  - enter the amount: product,price, amount, eg  ETH/BTC,200,0.5" << std::endl;
    std::string input;
    std::getline(std::cin, input);

    std::vector<std::string> tokens = CSVReader::tokenise(input, ',');
    if (tokens.size() != 3)
    {
        std::cout << "MerkelMain::enterBid Bad input! " << input << std::endl;
    }
    else {
        try {
            OrderBookEntry obe = CSVReader::stringsToOBE(
                tokens[1],
                tokens[2],
                currentTime,
                tokens[0],
                OrderBookType::bid
            );
            obe.username = "simuser";

            if (wallet.canFulfillOrder(obe)) {
                std::cout << "Wallet looks good. " << std::endl;
                orderBook.insertOrder(obe);
            }
            else {
                std::cout << "Wallet has insufficient funds" << std::endl;
            }
        }
        catch (const std::exception& e)
        {
            std::cout << " MerkelMain::enterBid Bad input " << std::endl;
        }
    }

    std::cout << "You typed: " << input << std::endl;
}

void MerkelMain::printWallet()
{
    std::cout << wallet.toString() << std::endl;
}
/*
void MerkelMain::gotoNextTimeframe()
{
    std::cout << "Going to next time frame. " << std::endl;
    for (std::string& p : orderBook.getKnownProducts())
    {
        std::cout << "matching " << p << std::endl;
        std::vector<OrderBookEntry> sales = orderBook.matchAsksToBids(p, currentTime);
        std::cout << "Sales: " << sales.size() << std::endl;
        for (OrderBookEntry& sale : sales)
        {
            std::cout << "Sale price: " << sale.price << " amount " << sale.amount << std::endl;
            if (sale.username == "simuser") {
                //update wallet
                wallet.processSale(sale);
            }
        }
    }
    currentTime = orderBook.getNextTime(currentTime);
}
*/

//my code
void MerkelMain::gotoNextTimeframe(const std::string& currencyPair)
{
    std::cout << "Going to the next time frame." << std::endl;
    for (std::string& p : orderBook.getKnownProducts())
    {
        std::cout << "Matching " << p << std::endl;
        std::vector<OrderBookEntry> sales = orderBook.matchAsksToBids(p, currentTime);
        std::cout << "Sales: " << sales.size() << std::endl;
        for (OrderBookEntry& sale : sales)
        {
            std::cout << "Sale price: " << sale.price << ", amount: " << sale.amount << std::endl;
            if (sale.username == "simuser")
            {
                // Update wallet
                wallet.processSale(sale);
            }
        }
    }
    currentTime = orderBook.getNextTime(currentTime);
    std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask, currencyPair, currentTime);
    std::vector<Candlestick> candlesticks = CSVReader::computeCandlestickData(entries);
    std::cout << "Candlestick data for 'asks on " << currencyPair << "':" << std::endl;
    for (const Candlestick& candlestick : candlesticks)
    {
        std::cout << "Open: " << candlestick.open << ", High: " << candlestick.high
            << ", Low: " << candlestick.low << ", Close: " << candlestick.close << std::endl;
    }
}


int MerkelMain::getUserOption()
{
    int userOption = 0;
    std::string line;
    std::cout << "Type in 1-6" << std::endl;
    std::getline(std::cin, line);
    try {
        userOption = std::stoi(line);
    }
    catch (const std::exception& e)
    {
        // 
    }
    std::cout << "You chose: " << userOption << std::endl;
    return userOption;
}

//my code
void MerkelMain::plotVolumeData(const std::vector<OrderBookEntry>& entries, const std::string& currencyPair)
{
    std::vector<double> volumeData = TechnicalAnalysis::computeVolumeData(entries);

    std::cout << "Volume Data Plot for " << currencyPair << ":" << std::endl;

    // Calculate the maximum volume for scaling the graph
    double maxVolume = *std::max_element(volumeData.begin(), volumeData.end());

    for (double volume : volumeData)
    {
        // Calculate the number of asterisks to represent the volume
        int numAsterisks = static_cast<int>((volume / maxVolume) * 50);

        // Print the volume bar as the graph with volume value
        std::cout << std::string(numAsterisks, '|') << " " << volume << std::endl;
    }
}

//my code
void MerkelMain::plotPriceData(const std::vector<OrderBookEntry>& entries, const std::string& currencyPair)
{
    std::vector<double> priceData = TechnicalAnalysis::computePriceData(entries);

    std::cout << "Price Data Plot for " << currencyPair << ":" << std::endl;

    // Calculate the minimum and maximum prices for scaling the graph
    double minPrice = *std::min_element(priceData.begin(), priceData.end());
    double maxPrice = *std::max_element(priceData.begin(), priceData.end());

    for (double price : priceData)
    {
        // Calculate the position of the price on a scale of 0 to 50
        int position = static_cast<int>(((price - minPrice) / (maxPrice - minPrice)) * 50);

        // Print the price line as the graph with price value
        std::cout << std::string(position, '-') << " " << price << std::endl;
    }
}



/*

void MerkelMain::plotVolumeData(const std::vector<OrderBookEntry>& entries)
{
    std::vector<double> volumeData = TechnicalAnalysis::computeVolumeData(entries);

    std::cout << "Volume Data Plot:" << std::endl;

    // Calculate the maximum volume for scaling the graph
    double maxVolume = *std::max_element(volumeData.begin(), volumeData.end());

    for (double volume : volumeData)
    {
        // Calculate the number of asterisks to represent the volume
        int numAsterisks = static_cast<int>((volume / maxVolume) * 50);

        // Print the volume bar as the graph with volume value
        std::cout << std::string(numAsterisks, '|') << " " << volume << std::endl;
    }
}

void MerkelMain::plotPriceData(const std::vector<OrderBookEntry>& entries)
{
    std::vector<double> priceData = TechnicalAnalysis::computePriceData(entries);

    std::cout << "Price Data Plot:" << std::endl;

    // Calculate the minimum and maximum prices for scaling the graph
    double minPrice = *std::min_element(priceData.begin(), priceData.end());
    double maxPrice = *std::max_element(priceData.begin(), priceData.end());

    for (double price : priceData)
    {
        // Calculate the position of the price on a scale of 0 to 50
        int position = static_cast<int>(((price - minPrice) / (maxPrice - minPrice)) * 50);

        // Print the price line as the graph with price value
        std::cout << std::string(position, '-') << " " << price << std::endl;
    }
}
*/


/*
void MerkelMain::processUserOption(int userOption)
{
    if (userOption == 0) // bad input
    {
        std::cout << "Invalid choice. Choose 1-8" << std::endl;
    }
    if (userOption == 1)
    {
        printHelp();
    }
    if (userOption == 2)
    {
        printMarketStats();
    }
    if (userOption == 3)
    {
        enterAsk();
    }
    if (userOption == 4)
    {
        enterBid();
    }
    if (userOption == 5)
    {
        printWallet();
    }
    if (userOption == 6)
    {
        for (const std::string& currencyPair : orderBook.getKnownProducts())
        {
            std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask, currencyPair, currentTime);
            plotVolumeData(entries);
        }
    }
    if (userOption == 7)
    {
        for (const std::string& currencyPair : orderBook.getKnownProducts())
        {
            std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask, currencyPair, currentTime);
            plotPriceData(entries);
        }
    }
    if (userOption == 8)
    {
        for (const std::string& currencyPair : orderBook.getKnownProducts())
        {
            gotoNextTimeframe(currencyPair);
        }
    }
}*/

//my code
/*print candlestick data for all currency pairs*/
void MerkelMain::processUserOption(int userOption)
{
    if (userOption == 0) // bad input
    {
        std::cout << "Invalid choice. Choose 1-8" << std::endl;
    }
    if (userOption == 1)
    {
        printHelp();
    }
    if (userOption == 2)
    {
        printMarketStats();
    }
    if (userOption == 3)
    {
        enterAsk();
    }
    if (userOption == 4)
    {
        enterBid();
    }
    if (userOption == 5)
    {
        printWallet();
    }
    if (userOption == 6)
    {
        std::vector<std::string> currencyPairs = orderBook.getKnownProducts();
        for (const std::string& currencyPair : currencyPairs)
        {
            std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask, currencyPair, currentTime);
            plotVolumeData(entries, currencyPair);
        }
    }
    if (userOption == 7)
    {
        std::vector<std::string> currencyPairs = orderBook.getKnownProducts();
        for (const std::string& currencyPair : currencyPairs)
        {
            std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask, currencyPair, currentTime);
            plotPriceData(entries, currencyPair);
        }
    }

    if (userOption == 8)
    {
        for (const std::string& currencyPair : orderBook.getKnownProducts())
        {
            gotoNextTimeframe(currencyPair);
        }
    }
}


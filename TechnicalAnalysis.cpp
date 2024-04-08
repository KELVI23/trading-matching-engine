#include "TechnicalAnalysis.h"

std::vector<double> TechnicalAnalysis::computeVolumeData(const std::vector<OrderBookEntry>& entries)
{
    std::vector<double> volumeData;

    for (const OrderBookEntry& entry : entries)
    {
        volumeData.push_back(entry.amount);
    }

    return volumeData;
}

std::vector<double> TechnicalAnalysis::computePriceData(const std::vector<OrderBookEntry>& entries)
{
    std::vector<double> priceData;

    for (const OrderBookEntry& entry : entries)
    {
        priceData.push_back(entry.price);
    }

    return priceData;
}

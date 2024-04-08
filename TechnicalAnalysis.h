#ifndef TECHNICALANALYSIS_H
#define TECHNICALANALYSIS_H

#include <vector>
#include "OrderBookEntry.h"

class TechnicalAnalysis
{
public:
    static std::vector<double> computeVolumeData(const std::vector<OrderBookEntry>& entries);
    static std::vector<double> computePriceData(const std::vector<OrderBookEntry>& entries);
};

#endif

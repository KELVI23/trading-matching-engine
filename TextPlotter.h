#pragma once

#include "Candlestick.h"
#include <vector>

class TextPlotter
{
public:
    static void plotCandlesticks(const std::vector<Candlestick>& candlesticks);
};

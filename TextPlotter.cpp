#include "TextPlotter.h"
#include <iostream>
#include <iomanip>

void TextPlotter::plotCandlesticks(const std::vector<Candlestick>& candlesticks)
{
    for (const auto& candlestick : candlesticks)
    {
        double open = candlestick.getOpen();
        double close = candlestick.getClose();
        double high = candlestick.getHigh();
        double low = candlestick.getLow();

        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Open: " << open << "  Close: " << close << "  High: " << high << "  Low: " << low << std::endl;
    }
}

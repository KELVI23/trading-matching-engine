#pragma once
#include <string>

class Candlestick
{
public:
    double open;
    double high;
    double low;
    double close;

    Candlestick(double _open, double _high, double _low, double _close);

    double getOpen() const;
    double getClose() const;
    double getHigh() const;
    double getLow() const;
    std::string toString() const;
};

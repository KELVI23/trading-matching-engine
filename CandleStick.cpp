#include "Candlestick.h"
#include <sstream>


Candlestick::Candlestick(double _open, double _high, double _low, double _close)
    : open(_open), high(_high), low(_low), close(_close)
{
}


double Candlestick::getOpen() const
{
    return open;
}

double Candlestick::getClose() const
{
    return close;
}

double Candlestick::getHigh() const
{
    return high;
}

double Candlestick::getLow() const
{
    return low;
}

std::string Candlestick::toString() const
{
    std::ostringstream oss;
    oss << "Open: " << open << ", Close: " << close << ", High: " << high << ", Low: " << low;
    return oss.str();
}

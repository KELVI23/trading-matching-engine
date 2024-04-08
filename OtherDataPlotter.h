#pragma once

#include <string>
#include <vector>

class OtherDataPlotter
{
public:
    OtherDataPlotter();

    void addDataPoint(double value);
    void plotData() const;

private:
    std::vector<double> dataPoints;
};

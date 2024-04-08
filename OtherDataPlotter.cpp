#include "OtherDataPlotter.h"
#include <iostream>

OtherDataPlotter::OtherDataPlotter()
{
}

void OtherDataPlotter::addDataPoint(double value)
{
    dataPoints.push_back(value);
}

void OtherDataPlotter::plotData() const
{
    std::cout << "Plotting other data:" << std::endl;
    for (const auto& dataPoint : dataPoints)
    {
        std::cout << dataPoint << std::endl;
    }
}

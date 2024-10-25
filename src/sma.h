// SMA - simple moving average
// SMA is a fundamental technique used to smooth out price data over a specific time frame,
// providing insights into market trends.

#include <iostream>
#include <deque>
#include <numeric>

class RealTimeSMA {
public:
    RealTimeSMA(int period): period(period) {}

    void AddPrice(double price);
    double CalculateSMA() const;

public:
    uint32_t GetPricesSize() const;

private:
    std::deque<double> prices;
    int period;
};
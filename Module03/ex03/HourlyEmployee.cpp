
#include <iostream>

#include "HourlyEmployee.hpp"
TempWorker::TempWorker(const std::string& name, int hourlyValue ) : Employee(name, hourlyValue), _hourlyMobilize(0)
{
    std::cout << "Temp Worker, name : " << name << ", hourly value : " << hourlyValue << std::endl;

}

TempWorker::~TempWorker()
{
}

int     TempWorker::executeWorday()
{
    int today = 7;
    if (_hourlyMobilize < today)
        today = _hourlyMobilize;
    _hourlyMobilize -= today;
    totalPay += today * hourlyValue;
    std::cout << "TempWorker name : " << name << " work hour today : " << today << " mobilize remain : " << _hourlyMobilize << std::endl;
    std::cout << "Pay for the day : " << totalPay << std::endl;
    return (today);
}



void    TempWorker::addMobilizedHour(int hour)
{
    _hourlyMobilize += hour;
}

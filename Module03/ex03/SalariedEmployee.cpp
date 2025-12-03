#include <iostream>


#include "SalariedEmployee.hpp"


ContractEmployee::ContractEmployee(const std::string& name, int hourlyValue) : Employee(name, hourlyValue), _hourlyMissed(0)
{
    std::cout << "Contract Employee, name : " << name << ", hourly value : " << hourlyValue << std::endl;
}

ContractEmployee::~ContractEmployee()
{
}

int     ContractEmployee::executeWorday()
{
    int today = 7;
    int missToday = _hourlyMissed;
    if (_hourlyMissed > 0)
    {
        today -= _hourlyMissed;
        _hourlyMissed = 0;
    }
    totalPay += today * hourlyValue;
    std::cout << "ContractEmployee name : " << name << " work hour today : " << today << " because hours missed : " << missToday << std::endl;
    std::cout << "Pay for the day : " << totalPay << std::endl;
    return (today);
}


void    ContractEmployee::addWorkOff(int day)
{
    _hourlyMissed += day;
}


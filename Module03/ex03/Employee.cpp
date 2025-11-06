#include <iostream>

#include "Employee.hpp"


Employee::Employee(const std::string& r_name, int value) : totalPay(0), name(r_name), hourlyValue(value)
{
}

Employee::~Employee()
{
}


int     Employee::calculMonthlyPayAndReset()
{
    int pay = totalPay;
    totalPay = 0;
    return (pay);
}
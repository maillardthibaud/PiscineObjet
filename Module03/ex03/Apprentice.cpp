#include <iostream>

#include "Apprentice.hpp"

Apprentice::Apprentice(const std::string& r_name, int value) : Employee(r_name, value), _schoolHourRemain(0), _hourlyMissed(0)
{
    std::cout << "Apprentice, name : " << name << ", hourly value : " << hourlyValue << std::endl;
}

Apprentice::~Apprentice()
{
}
void    Apprentice::addSchoolHour(int hour)
{
    _schoolHourRemain += hour;
}

bool    Apprentice::isSchoolRemain()
{
    int todayHour = 7;
    int schoolTodo;
    if (_schoolHourRemain > todayHour)
        schoolTodo = todayHour;
    else
        schoolTodo = _schoolHourRemain;
    _schoolHourRemain -= schoolTodo;
    totalPay += schoolTodo * hourlyValue * 0.5;
    todayHour -= schoolTodo;
    return (true);
}

int    Apprentice::executeWorday()
{
    int todayHour = 7;
    int schoolTodo;
    if (_schoolHourRemain > todayHour)
        schoolTodo = todayHour;
    else
        schoolTodo = _schoolHourRemain;
    _schoolHourRemain -= schoolTodo;
    totalPay += schoolTodo * hourlyValue * 0.5;
    todayHour -= schoolTodo;
    std::cout << "Apprentice name : " << name << " work on school, hour today : " << schoolTodo << std::endl;
    int missToday = _hourlyMissed;
    if (_hourlyMissed > 0)
    {
        todayHour -= _hourlyMissed;
        _hourlyMissed = 0;
    }
    totalPay += todayHour * hourlyValue;
    std::cout << "Apprentice name : " << name << " work hour today : " << todayHour << " because hours missed : " << missToday << std::endl;
    std::cout << "Pay for the day : " << totalPay << std::endl;
    return (todayHour);

}


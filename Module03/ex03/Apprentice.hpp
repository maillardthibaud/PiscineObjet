
#ifndef __APPRENTICE_HPP__
#define __APPRENTICE_HPP__

#include "Employee.hpp"

class Apprentice : public Employee
{
    private:

            int     _schoolHourRemain;
            int     _hourlyMissed;


    public:

        Apprentice(const std::string& r_name, int value);
        ~Apprentice();

        void    addSchoolHour(int hour);
        bool    isSchoolRemain();

        int     executeWorday();
};

#endif
#ifndef __HOURLYEMPLOYEE_HPP__
#define __HOURLYEMPLOYEE_HPP__

#include <iostream>

#include "Employee.hpp"


class TempWorker : public Employee 
{
    private:

            int                 _hourlyMobilize;

    public:

        TempWorker(const std::string& name, int hourlyDay);
        ~TempWorker();

        void    addMobilizedHour(int hour);


        virtual int executeWorday();

};


#endif
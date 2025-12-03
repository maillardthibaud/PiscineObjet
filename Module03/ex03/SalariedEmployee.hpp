#ifndef __SALARIEDEMPLOYEE_HPP__
#define __SALARIEDEMPLOYEE_HPP__

#include "Employee.hpp"

class ContractEmployee : public Employee
{
    private:

            int     _hourlyMissed;

    public:

        ContractEmployee(const std::string& name, int hourlyValue);
        ~ContractEmployee();

        void    addWorkOff(int day);

        virtual int executeWorday();

};


#endif
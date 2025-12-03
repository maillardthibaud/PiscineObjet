#ifndef __EMPLOYEE_HPP__
#define __EMPLOYEE_HPP__

#include <string>

class Employee
{
        private:


        protected:

                float               totalPay;

        public:

                std::string         name;
                int                 hourlyValue;

                Employee(const std::string& name, int HourlyValue);
                virtual ~Employee();


                virtual int         executeWorday() = 0;
                virtual int         calculMonthlyPayAndReset();
};

#endif



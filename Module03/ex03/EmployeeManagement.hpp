#ifndef __EMPLOYEEMANAGEMENT_HPP__
#define __EMPLOYEEMANAGEMENT_HPP__

#include <vector>
#include "Employee.hpp"

class EmployeeManager
{
    private:

        std::vector<Employee*>  _setEmployee;
        

    public:
    
        EmployeeManager();
        ~EmployeeManager();

        void    addEmployee(Employee* e);
        void    removeEmployee(Employee* e);
        void    executeWorkday(); //This method must execute a single day of work for each of the registered worker. One day equal 7 hours of work
        void    executePayroll(); //This method must output in the console the amount of money to give to each of the subscribed workers, over the last complete month.
};

#endif
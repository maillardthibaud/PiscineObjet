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
        void    executeWorkday(); 
        void    executePayroll(); 
};

#endif
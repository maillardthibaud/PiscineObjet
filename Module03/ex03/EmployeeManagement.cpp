
#include "EmployeeManagement.hpp"
#include <iostream>


EmployeeManager::EmployeeManager()
{
}

EmployeeManager::~EmployeeManager()
{
}
void    EmployeeManager::addEmployee(Employee* e)
{
    _setEmployee.push_back(e);
    std::cout << "add employee, name : " << e->name << std::endl;
}
void    EmployeeManager::removeEmployee(Employee* e)
{
    std::vector<Employee*>::iterator it;
    for (it = _setEmployee.begin(); it != _setEmployee.end(); it++)
    {
        if ((*it) == e)
        {
            std::cout << "remove employee, name : " << e->name << std::endl;
            _setEmployee.erase(it);
            break;
        }
    }

}
void    EmployeeManager::executeWorkday() 
{
    std::cout << "Manager execute work day" << std::endl;

    std::vector<Employee*>::iterator it;
    for (it = _setEmployee.begin(); it != _setEmployee.end(); it++)
    {
        if ((*it)->executeWorday() == 0)
            std::cout << "!!! Employee nname : " << (*it)->name << " has not workin today !!!" << std::endl;
    }
}

void    EmployeeManager::executePayroll()
{
    std::cout << "Manager execute Payroll" << std::endl;

    std::vector<Employee*>::iterator it;
    for (it = _setEmployee.begin(); it != _setEmployee.end(); it++)
        std::cout << "Employee name : " << (*it)->name << " paid : " << (*it)->calculMonthlyPayAndReset() << std::endl; 
}

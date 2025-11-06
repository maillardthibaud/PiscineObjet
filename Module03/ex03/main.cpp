#include <iostream>
#include "EmployeeManagement.hpp"
#include "Employee.hpp"
#include "SalariedEmployee.hpp"
#include "HourlyEmployee.hpp"
#include "Apprentice.hpp"


int main()
{

    TempWorker* tmp = new TempWorker("John", 10);
    tmp->addMobilizedHour(35);
    ContractEmployee* cdi = new ContractEmployee("Jack", 8);
    cdi->addWorkOff(2);
    Apprentice* app = new Apprentice("Joe", 5);
    app->addSchoolHour(40);
    EmployeeManager em;
    em.addEmployee(tmp);
    em.addEmployee(cdi);
    em.addEmployee(app);
    em.executeWorkday();
    em.executeWorkday();
    em.executeWorkday();
    em.executeWorkday();
    em.executeWorkday();
    em.executeWorkday();
    em.executeWorkday();


    em.executePayroll();



    em.executeWorkday();
    em.executeWorkday();
    em.executeWorkday();
    em.executeWorkday();

    em.executePayroll();

    delete(tmp);
    delete(cdi);
    delete(app);
       
    return (0);
}
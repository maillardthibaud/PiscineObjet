
#include "HeadmasterOffice.hpp"
#include <iostream>

HeadmasterOffice::HeadmasterOffice(int id) : Room(id)
{   
    // std::cout << "HeadmasterOffice constructor, id : " << _id << std::endl;
}
HeadmasterOffice::~HeadmasterOffice()
{
    // std::cout << "HeadmasterOffice destructor" << std::endl;

}


bool HeadmasterOffice::canEnter(Person* person)
{
    (void)person;
    return(true);
}
int 						HeadmasterOffice::getId()
{
    return (_id);
}

std::vector<Person*>        HeadmasterOffice::getOccupants()
{
    return (_occupants);
}
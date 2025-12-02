#include "Courtyard.hpp"

Courtyard::Courtyard(int id) : Room(id)
{
    // std::cout << "Courtyard constructor, id : " << _id << std::endl;
}
Courtyard::~Courtyard()
{
    // std::cout << "Courtyard destructor" << std::endl;
}
bool Courtyard::canEnter(Person* person)
{
    (void)person;
    // Staff* staffMember = dynamic_cast<Staff*>(person);
    // if (staffMember)
    // {
    //     auto cStaff = StaffList::getInstance().getList();
    //     std::vector<Staff*>::iterator it;
    //     for (it = cStaff.begin(); it != cStaff.end(); it++) 
    //     {
    //         if ((*it) == staffMember)
    //             return true;
    //     }
    // }
    return true;
}
std::vector<Person*>        Courtyard::getOccupants()
{
    return (_occupants);
}
int                         Courtyard::getId()
{
    return (_id);
}
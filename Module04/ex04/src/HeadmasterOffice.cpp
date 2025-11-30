
#include "HeadmasterOffice.hpp"

HeadmasterOffice::HeadmasterOffice(int id) : Room(id)
{   
    // std::cout << "HeadmasterOffice constructor, id : " << _id << std::endl;
}
HeadmasterOffice::~HeadmasterOffice()
{
    // std::cout << "HeadmasterOffice destructor" << std::endl;

}

void 				HeadmasterOffice::printOccupant()
{
    for(auto person : _occupants)
    {
        std::cout << "Room id : " << _id << std::endl;
        if (_occupants.empty())
            std::cout << " have nobody in here" << std::endl;
        else
            std::cout << "Inside headmaster office : " << person->getName();
    }

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
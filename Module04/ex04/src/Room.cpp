#include "Room.hpp"


Room::Room(int id) : _id(id)
{
    // std::cout << "Room constructor, id : " << _id << std::endl;
}

Room::~Room()
{
    // std::cout << "Destructor Room" << std::endl;
}
int 						Room::getId()
{
    return (_id);
}
std::vector<Person*>		Room::getOccupants()
{
    return (_occupants);
}

bool Room::canEnter(Person* person)
{
    (void) person;
    return (true);
}

void Room::enter(Person* person)
{
    (void) person;
}
void Room::exit(Person* person)
{
    (void) person;
}
	
void Room::printOccupant()
{
    std::cout << "Room id : " << getId() << std::endl;
    if (_occupants.empty())
        std::cout << " have nobody in here" << std::endl;
    else
    {
        for (auto v : _occupants) 
            std::cout << " "<< v->getName() << " is here." <<std::endl;
    }
}



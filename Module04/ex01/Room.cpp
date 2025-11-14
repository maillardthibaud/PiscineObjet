#include "Room.hpp"
#include <iostream>

Room::Room(int id) : _id(id)
{
    std::cout << "Room constructor, id : " << _id << std::endl;
}

Room::~Room()
{
    std::cout << "Destructor Room" << std::endl;
}
// bool Room::canEnter(Person* person)
// {
//     (void) person;
//     return (true);
// }

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

}
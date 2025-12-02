#include "Person.hpp"

Person::Person(std::string p_name) : _name(p_name), _currentRoom(NULL)
{
    // std::cout << "Person constructor, name : " << _name << std::endl;

}

Person::~Person()
{
    // std::cout << "Person destructor" << std::endl;

}
Room* Person::getCurrentRoom()
{
    return (_currentRoom);
}

std::string	Person::getName()
{
    return(_name);
}

void			Person::setCurrentRoom(Room* room)
{
    _currentRoom = room;
}
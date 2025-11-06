#ifndef __PERSON_HPP__
#define __PERSON_HPP__

#include <string>
#include "Room.hpp"

class Person
{
private:
	std::string _name;
	Room* _currentRoom;
public:
	Personne(std::string p_name);
	Room* room() {return (_currentRoom);}
};


#endif
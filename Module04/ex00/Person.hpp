#ifndef __PERSON_HPP__
#define __PERSON_HPP__

#include <string>
// #include "Room.hpp"
class Room;

class Person
{
	protected:

		std::string _name;
		Room* _currentRoom;

	public:

		Person(std::string p_name);
		~Person();

		Room* getCurrentRoom();

};


#endif
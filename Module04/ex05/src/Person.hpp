#ifndef __PERSON_HPP__
#define __PERSON_HPP__

#include <string>
#include <iostream>

class Room;

class Person
{
	protected:

		std::string _name;
		Room* _currentRoom;

	public:

		Person(std::string p_name);
		~Person();

		std::string		getName();
		Room* 			getCurrentRoom();
		void			setCurrentRoom(Room* room);

};


#endif
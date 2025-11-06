#ifndef __ROOM_HPP__
#define __ROOM_HPP__

#include <vector>
#include "Person.hpp"

class Room
{
private:
	long long ID;
	std::vector<Person*> _occupants;

public:
	Room();
	bool canEnter(Person*);
	void enter(Person*);
	void exit(Person*);
	
	void printOccupant();
};
#endif
#ifndef __ROOM_HPP__
#define __ROOM_HPP__

#include <vector>
// #include "Person.hpp"
class Person;

class Room
{
	private:
			std::vector<Person*> _occupants;

	protected:
			int _id;

	public:

			Room(int id);
			virtual ~Room();

			virtual bool canEnter(Person* person) = 0;
			virtual void enter(Person* person);
			virtual void exit(Person* person);
			virtual void printOccupant();
};
#endif
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
			~Room();
			bool canEnter(Person* person);
			void enter(Person* person);
			void exit(Person* person);
			void printOccupant();
};
#endif
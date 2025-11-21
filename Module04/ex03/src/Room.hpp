#ifndef __ROOM_HPP__
#define __ROOM_HPP__

#include <vector>
// #include "Person.hpp"
class Person;

class Room
{
	private:

	protected:

			int _id;
			std::vector<Person*> _occupants;

	public:

			Room(int id);
			virtual ~Room();

			virtual int 						getId();
			virtual std::vector<Person*>		getOccupants();


			virtual bool 				canEnter(Person* person);
			virtual void 				enter(Person* person);
			virtual void 				exit(Person* person);
			virtual void 				printOccupant();

};
#endif
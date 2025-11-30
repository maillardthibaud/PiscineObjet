#ifndef __CLASSROOM_HPP__
#define __CLASSROOM_HPP__

#include <iostream>
#include <string>

#include "Room.hpp"
#include "Course.hpp"
#include "Singleton.hpp"

class Classroom : public Room
{
	private:

		std::string		_courseName;
		Course* 		_currentRoom;

	public:

		Classroom(int idClassroom);
		~Classroom();
		
		std::vector<Person*>	getOccupants();
		int						getId();
		Course*					getCurrentCourse();

		void 					assignCourse(Course* p_course);
		bool 					canEnter(Person* person);



};


#endif
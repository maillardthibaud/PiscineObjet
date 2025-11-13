#ifndef __CLASSROOM_HPP__
#define __CLASSROOM_HPP__

#include "Room.hpp"
// class Room;
// #include "Course.hpp"
// class Course;

class Classroom : public Room
{
	private:

		// Course* _currentRoom;

	public:

		Classroom(int idClassroom);
		~Classroom();
		// void assignCourse(Course* p_course);
};
#endif
#ifndef __PROFESSOR_HPP__
#define __PROFESSOR_HPP__

#include "Staff.hpp"
// #include "Course.hpp"
class Course;

class Professor : public Staff
{
	private:

		Course* _currentCourse;

	public:

		Professor(std::string name);
		~Professor();
		void assignCourse(Course* p_course);
		void doClass();
		void closeCourse();
};
#endif
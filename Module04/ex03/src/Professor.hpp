#ifndef __PROFESSOR_HPP__
#define __PROFESSOR_HPP__

#include "Staff.hpp"

class Course;

class Professor : public Staff
{
	private:

		Course* 		_currentCourse;
		std::string		_subjectTeaching;

	public:

		Professor(std::string name, std::string subject);
		~Professor();

		std::string 	getName();
		std::string		getSubject();
		Course*			getCurrentCourse();

		void assignCourse(Course* p_course);
		void doClass();
		void closeCourse();
};
#endif
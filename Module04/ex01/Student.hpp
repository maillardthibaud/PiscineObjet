#ifndef __STUDENT_HPP__
#define __STUDENT_HPP__

#include <vector>
#include "Person.hpp"

class Course;
class Classroom;

class Student : public Person
{
	private:

		std::vector<Course*> _subscribedCourse;

	public:

		Student(std::string name);
		~Student();

		std::string	getName();
		void attendClass(Classroom* p_classroom);
		void exitClass();
		void graduate(Course* p_course);
};

#endif
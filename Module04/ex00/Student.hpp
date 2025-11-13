#ifndef __STUDENT_HPP__
#define __STUDENT_HPP__

#include <vector>
#include "Person.hpp"
// #include "Course.hpp"
#include "Classroom.hpp"
class Course;

class Student : public Person
{
	private:

		std::vector<Course*> _subscribedCourse;

	public:

		Student(std::string name);
		~Student();
		void attendClass(Classroom* p_classroom);
		void exitClass();
		void graduate(Course* p_course);
};

#endif
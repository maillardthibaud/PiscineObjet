#ifndef __STUDENT_HPP__
#define __STUDENT_HPP__

#include <vector>
#include "Person.hpp"
// #include "Singleton.hpp"

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

// using StudentList = Singleton<Student>;

#endif
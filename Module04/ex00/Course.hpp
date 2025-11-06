#ifndef __COURSE_HPP__
#define __COURSE_HPP__

#include <iostream>
#include <vector>

#include "Professor.hpp"
#include "Student.cpp"

class Course
{
private:
	std::string _name;
	Professor* _responsable;
	std::vector<Student*> _students;
	int _numberOfClassToGraduate;
	int _maximumNumberOfStudent;
public:
	Course(std::string p_name);
	void assign(Professor* p_professor);
	void subscribe(Student* p_student);
};

#endif
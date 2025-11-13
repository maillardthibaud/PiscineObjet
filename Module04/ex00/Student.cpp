#include <iostream>

#include "Student.hpp"
#include "Person.hpp"
// #include "Course.hpp"

Student::Student(std::string name) : Person(name)
{
    std::cout << "Student Constructor, name : " << _name << std::endl;
}

Student::~Student()
{
    std::cout << "Student Destructor" << std::endl;
}

void Student::attendClass(Classroom* p_classroom)
{
    (void) p_classroom;
}

void Student::exitClass()
{}
void Student::graduate(Course* p_course)
{
    (void)p_course;
}

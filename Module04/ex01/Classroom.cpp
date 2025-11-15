#include <iostream>
#include "Classroom.hpp"

Classroom::Classroom(int idClassroom) : Room(idClassroom)
{
    // std::cout << "Classroom constructor id : " << _id << std::endl;
}
Classroom::~Classroom()
{
    // std::cout << "Classroom destructor id : " << _id << std::endl;
}
void Classroom::assignCourse(Course* p_course)
{
    if(!p_course)
        return;
    if (!_currentRoom)
    {
        _courseName = p_course->getName();
        std::cout << "Classroom id : " << _id << " has been assign the " << _courseName << " course" << std::endl;
        _currentRoom = p_course;
    }
    else
        std::cout << "This classroom has already a course assign" << std::endl;

}

bool Classroom::canEnter(Person* person)
{
    (void)person;
    return(true);
}

std::vector<Person*>        Classroom::getOccupants()
{
    return (_occupants);
}
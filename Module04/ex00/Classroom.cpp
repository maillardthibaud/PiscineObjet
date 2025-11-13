#include <iostream>
#include "Classroom.hpp"
#include "Room.hpp"

Classroom::Classroom(int idClassroom) : Room(idClassroom)
{
    std::cout << "Classroom constructor id : " << _id << std::endl;

}
Classroom::~Classroom()
{

    std::cout << "Classroom destructor id : " << _id << std::endl;


}
// void Classroom::assignCourse(Course* p_course)
// {

// }

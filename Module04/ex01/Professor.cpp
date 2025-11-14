#include <iostream>
#include "Professor.hpp"

Professor::Professor(std::string name) : Staff(name)
{
    std::cout << "Professor constructor, name : " << _name << std::endl;
}
Professor::~Professor()
{
    std::cout << "Professor destructor, name : " << _name << std::endl;
}

std::string 	Professor::getName()
{
    return (_name);
}
void Professor::assignCourse(Course* p_course)
{
    _currentCourse = p_course;
}
void Professor::doClass()
{

}
void Professor::closeCourse()
{

}
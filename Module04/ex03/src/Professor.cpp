#include <iostream>
#include "Professor.hpp"

Professor::Professor(std::string name, std::string subject) : Staff(name), _subjectTeaching(subject), _currentCourse(nullptr), _director(nullptr)
{
    // std::cout << "Professor constructor, name : " << _name << std::endl;
}
Professor::~Professor()
{
    // std::cout << "Professor destructor, name : " << _name << std::endl;
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

std::string		Professor::getSubject()
{
    return(_subjectTeaching);
}

Course*         Professor::getCurrentCourse()
{
    return (_currentCourse);
}

void        Professor::needCourseCreationForm()
{
    // _director->receiveForm(FormType::NeedCourseCreation);
}

void	Professor::setHeadmaster(Headmaster* p_headmaster)
{
    _director = p_headmaster;
}



void	Professor::setCourse(Course* p_course)
{
    _currentCourse = p_course;
}
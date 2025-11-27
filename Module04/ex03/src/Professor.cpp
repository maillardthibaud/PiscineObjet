#include <iostream>
#include "Professor.hpp"
#include "Headmaster.hpp"
#include "NeedCourseCreationForm.hpp"
#include "NeedMoreClassRoomForm.hpp"
#include "CourseFinishedForm.hpp"
#include "Student.hpp"

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
    if (DEBUG)
        std::cout << _name << " has been assign to : " << p_course->getName() << std::endl;
    _currentCourse = p_course;
}
void Professor::doClass()
{
    if(_currentCourse == nullptr)
    {
        _director->needCreationForm(*this);
    }
    else if (_currentCourse->getClassroom() == nullptr)
    {
        _director->needClassroomCreation(this);
    }
    else
        _currentCourse->displayInfoCourse();

}

void    Professor::fillCreationClassRoomForm(NeedMoreClassRoomForm& form)
{
    form.setRequester(this);
    form.setCourse(_currentCourse);
    _director->receiveForm(&form);
}

void    Professor::fillCreationForm(NeedCourseCreationForm& nccf)
{
    nccf.setName(_subjectTeaching);
    nccf.setProf(this);
    _director->receiveForm(&nccf);
}

void	Professor::fillGraduationForm(CourseFinishedForm& cff, Student& stud)
{

    cff.setCourseFinished(_currentCourse);
    cff.setStudToGrad(&stud);
    _director->receiveForm(&cff);

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

// void        Professor::needCourseCreationForm()
// {
//     _director->receiveForm(NeedCourseCreation);
// }

void	Professor::setHeadmaster(Headmaster* p_headmaster)
{
    _director = p_headmaster;
}



void	Professor::setCourse(Course* p_course)
{
    _currentCourse = p_course;
}
#include <iostream>
#include "Professor.hpp"
#include "Course.hpp"
#include "Student.hpp"

Course::Course(std::string p_name, int toGrad, int maxStud)
 : _name(p_name), _numberOfClassToGraduate(toGrad), _maximumNumberOfStudent(maxStud), _responsable(nullptr), _classroom(nullptr)
{   
    // std::cout << "Course constructor { name : " << _name << "\n"
    //                                 << "to graduate need assist " << _numberOfClassToGraduate << " class" << "\n"
    //                                 << "maximum students allow : " << _maximumNumberOfStudent << std::endl;
}
Course::~Course()
{

}
std::string 	Course::getName()
{
    return (_name);
}


Professor*      Course::getResponsable()
{
    return (_responsable);
}
int				Course::getNbToGrad()
{
    return (_numberOfClassToGraduate);
}
int				Course::getMaxStud()
{
    return (_maximumNumberOfStudent);
}
void Course::assign(Professor* p_professor)
{
    if(p_professor)
    {
        _responsable = p_professor;
        std::cout << p_professor->getName() << " has been assign to " << _name << " course" << std::endl;
    }

}
void Course::subscribe(Student* p_student)
{
    if (p_student)
    {
        std::cout << "Student : " << p_student->getName() << " has subscribe to " << _name << " course" << std::endl;
        p_student->addCourse(this);
        _students.push_back(p_student);
    }

}


bool                Course::countStudent()
{
    if (static_cast<int>(_students.size()) < _maximumNumberOfStudent)
        return true;
    std::cout << _name << " course have reach the max student value" << std::endl;
    return false;
}


void					Course::displayInfoCourse()
{
    std::cout << _name << " course, ";
    if (_students.empty())
    {
        std::cout << "have no student register" << std::endl;
        return;
    }
    else
    {
        std:: cout << "have " << _students.size() << " student(s) register : " << std::endl;
        std::vector<Student*>::iterator it;
        for (it = _students.begin(); it != _students.end(); it++)
        {
            std::cout << "|-> " << (*it)->getName() << std::endl;
        }
    }

    std::cout << "Classsroom id : " << _classroom->getId() << std::endl;
}


std::vector<Student*>   Course::getStud()
{
    return (_students);
}
Classroom* Course::getClassroom()
{
    return (_classroom);
}


void        Course::setResponsable(Professor* prof)
{
    _responsable = prof;
}
void					Course::addClassroom(Classroom* room)
{
    if (room)
        _classroom = room;


}
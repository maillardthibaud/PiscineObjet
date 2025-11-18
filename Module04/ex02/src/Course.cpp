#include <iostream>
#include "Professor.hpp"
#include "Course.hpp"
#include "Student.hpp"

Course::Course(std::string p_name, int toGrad, int maxStud)
 : _name(p_name), _numberOfClassToGraduate(toGrad), _maximumNumberOfStudent(maxStud)
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



std::vector<Student*>   Course::getStud()
{
    return (_students);
}
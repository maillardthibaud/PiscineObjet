#include <iostream>

#include "Student.hpp"
#include "Classroom.hpp"
// #include "Person.hpp"
#include "Course.hpp"

Student::Student(std::string name) : Person(name)
{
    // std::cout << "Student Constructor, name : " << _name << std::endl;
}

Student::~Student()
{
    // std::cout << "Student Destructor" << std::endl;
}

std::string	Student::getName()
{
    return (_name);
}

void					Student::addCourse(Course* course)
{
    _subscribedCourse.push_back(course);
    CourseProgress cp = {course, course->getNbToGrad()};
    _courseProgress.push_back(&cp);
}

void Student::attendClass(Classroom* p_classroom)
{
    std::cout << _name << " try to attend class : " << p_classroom->getCurrentCourse()->getName() << std::endl;
    if (checkStudentSub(p_classroom))
    {
        std::vector<CourseProgress*>::iterator it;
        for (it = _courseProgress.begin(); it != _courseProgress.end(); it++)
        {
            if (p_classroom->getCurrentCourse() == (*it)->course)
            {
                (*it)->courseRemain--;
                std::cout << "You're attend to class : " << (*it)->course->getName() << std::endl;
                if ((*it)->courseRemain == 0)
                {
                    std::cout << "You attend all the class needed to graduate, ask for a CourseFinishedForm" << std::endl;
                }
            }
        }
    }
}

void        Student::getAllCourseAndRemainClass()
{
    std::vector<CourseProgress*>::iterator it;
    for (it = _courseProgress.begin(); it != _courseProgress.end(); it++)
    {
        std::cout << _name << " is register to " << (*it)->course->getName() << ", remain to grad : " << (*it)->courseRemain << std::endl;

    }
}

bool        Student::checkStudentSub(Classroom* p_classroom)
{
    std::vector<Course*>::iterator it;

    for (it = _subscribedCourse.begin(); it != _subscribedCourse.end(); it++)
    {
       if ((*it) == p_classroom->getCurrentCourse())
           return(true);
    }
    std::cout << "You're not register for this course : " << p_classroom->getCurrentCourse()->getName() << std::endl;
    return (false);
}

void Student::exitClass()
{}
void Student::graduate(Course* p_course)
{
    (void)p_course;
}


std::vector<Course*>&	Student::getCourses()
{
    return (_subscribedCourse);
}

std::vector<CourseProgress*>&		Student::getProgress()
{
    return (_courseProgress);
}
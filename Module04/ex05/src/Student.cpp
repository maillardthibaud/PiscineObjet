
#include "Student.hpp"
#include "Headmaster.hpp"
#include "Classroom.hpp"
#include "Course.hpp"
#include "SubscriptionToCourseForm.hpp"

Student::Student(std::string name, Headmaster* director) : Person(name), _director(director), _isInClass(false)
{
    // std::cout << "Student Constructor, name : " << _name << std::endl;
}

Student::~Student()
{
    // std::cout << "Student Destructor" << std::endl;
    for (std::vector<CourseProgress*>::iterator it = _courseProgress.begin(); it != _courseProgress.end(); ++it)
    {
        delete *it;
    }
    _courseProgress.clear();
}

std::string	Student::getName()
{
    return (_name);
}

void			Student::fillSubscriptionForm(SubscriptionToCourseForm& form)
{
    form.setSubStud(this);
    form.setSubjectSub(_subjectSubscription);
    _director->receiveForm(&form);
}

void					Student::addCourse(Course* course)
{
    _subscribedCourse.push_back(course);
    _currentCourse = course;
    CourseProgress* cp = new CourseProgress();
    cp->course = course;
    cp->courseRemain = course->getNbToGrad();
    _courseProgress.push_back(cp);
}



void Student::attendClass(Classroom* p_classroom)
{
    std::vector<CourseProgress*>::iterator it;
    for (it = _courseProgress.begin(); it != _courseProgress.end(); it++)
    {
        if (p_classroom->getCurrentCourse() == (*it)->course)
        {
            (*it)->courseRemain--;
            std::cout << _name << " attend to class : " << (*it)->course->getName() << std::endl;
            if ((*it)->courseRemain == 0)
            {
                std::cout << _name << " attend all the class needed to graduate, ask for a CourseFinishedForm" << std::endl;
                askForGraduation((*it)->course);
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
    std::cout << "Congratulation  " << _name << ", received his graduation for " << p_course->getName() << " course" << std::endl;
}

void    Student::askForGraduation(Course* p_course)
{
    if (p_course)
        p_course->getResponsable()->receiveStudForGrad(this);
}


std::vector<Course*>&	Student::getCourses()
{
    return (_subscribedCourse);
}

std::vector<CourseProgress*>&		Student::getProgress()
{
    return (_courseProgress);
}

std::vector<Course*>			Student::getGraduateCourse()
{
    return (_graduateCourse);
}

void                        Student::addGraduationCourse(Course* p_course)
{
    _graduateCourse.push_back(p_course);
}

void 		Student::askForSubscriptionForm(std::string subject)
{
    std::cout << _name << " ask for sub to " << subject << " course" << std::endl;
    _subjectSubscription = subject;
    _director->needSubscriptionCourseForm(*this);
}

void	    Student::setHeadmaster(Headmaster* director)
{
    _director = director;
}
void    Student::notify(SchoolState event)
{
    (void) event;
    if (! _isInClass && _currentRoom->canEnter(this))
    {
        _currentRoom->enter(this);
        _isInClass = true;
    }
    else
    {
        _currentRoom->exit(this);
        _isInClass = false;
    }
    
}
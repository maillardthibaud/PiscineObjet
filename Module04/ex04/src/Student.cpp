
#include "Student.hpp"
#include "Headmaster.hpp"
#include "Classroom.hpp"
#include "Course.hpp"
#include "SubscriptionToCourseForm.hpp"

Student::Student(std::string name) : Person(name), _director(nullptr)
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
    CourseProgress* cp = new CourseProgress();
    cp->course = course;
    cp->courseRemain = course->getNbToGrad();
    _courseProgress.push_back(cp);
}



void Student::attendClass(Classroom* p_classroom)
{
    if (checkStudentSub(p_classroom))
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
void    Student::notify(Event event)
{
    (void)event;
    std::cout << "student notify" << std::endl;
}
#include "Professor.hpp"
#include "NeedCourseCreationForm.hpp"
#include "NeedMoreClassRoomForm.hpp"
#include "CourseFinishedForm.hpp"
#include "Student.hpp"
#include "Headmaster.hpp"

Professor::Professor(std::string name, std::string subject) : Staff(name), _subjectTeaching(subject), _currentCourse(nullptr), _director(nullptr), _isInClass(true)
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

void			Professor::receiveStudForGrad(Student* p_stud)
{
    _director->needGraduationForm(*this, *p_stud);
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
        if (DEBUG)
            std::cout << _name << " need Course Creation" << std::endl;
        _director->needCreationForm(*this);
    }
    else if (_currentCourse->getClassroom() == nullptr)
    {
        if (DEBUG)
            std::cout << _name << " need Classroom Creation" << std::endl;
        _director->needClassroomCreation(*this);
    }
    else
    {
        Classroom* room = _currentCourse->getClassroom();
        if (room->canEnter(this))
        {
            room->enter(this);
            _isInClass = true;
            if (DEBUG)
                std::cout << _name << " teaching " << _currentCourse->getName() << " course" << std::endl;
            _currentCourse->attendCourse();
            room->exit(this);
        }
    }
}

void    Professor::fillCreationClassRoomForm(NeedMoreClassRoomForm& form)
{
    form.setRequester(this);
    form.setCourse(_currentCourse);
    _director->receiveForm(&form);
}

void    Professor::fillCreationForm(NeedCourseCreationForm& nccf)
{
    nccf.setSubject(_subjectTeaching);
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

void	Professor::setHeadmaster(Headmaster* p_headmaster)
{
    _director = p_headmaster;
}

void	Professor::setCourse(Course* p_course)
{
    _currentCourse = p_course;
}


void    Professor::notify(Event event)
{
    (void)event;
    std::cout << "professor notify" << std::endl;
}
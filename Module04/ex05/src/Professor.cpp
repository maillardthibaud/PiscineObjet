#include "Professor.hpp"
#include "NeedCourseCreationForm.hpp"
#include "NeedMoreClassRoomForm.hpp"
#include "CourseFinishedForm.hpp"
#include "Student.hpp"
#include "Headmaster.hpp"

Professor::Professor(std::string name, std::string subject, Headmaster* director) : Staff(name), _subjectTeaching(subject), _currentCourse(nullptr), _director(director), _isInClass(false)
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
bool Professor::doesNeedForm()
{
    if(_currentCourse == nullptr)
    {
        if (DEBUG)
            std::cout << _name << " need Course Creation" << std::endl;
        _director->needCreationForm(*this);
        return (true);
    }
    else if (_currentCourse->getClassroom() == nullptr)
    {
        if (DEBUG)
            std::cout << _name << " need Classroom Creation" << std::endl;
        _director->needClassroomCreation(*this);
        return (true);
    }
    return (false);
}

void Professor::doClass()
{
    if (!doesNeedForm()) 
    {
        if (DEBUG)
            std::cout << _name << " teaching " << _currentCourse->getName() << " course" << std::endl;
        _currentCourse->attendCourse();
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

void    Professor::enterClassroom()
{
    _currentRoom = _currentCourse->getClassroom();
    if (_currentRoom->canEnter(this))
    {
        _currentRoom->enter(this);
        _isInClass = true;
    }
}

void    Professor::notify(SchoolState event)
{
    switch  (event)
    {
        case SchoolState::Start :
        {
            enterClassroom();            
            break;
        }
        case SchoolState::Working :
        {
            enterClassroom();
            break;
        }
        case SchoolState::Recreation :
        {
            exitClassroom();
            enterStaffRoom();
            break;
        }
        case SchoolState::Lunch :
        {
            exitClassroom();
            break;
        }
        
        default:
            break;
    }
}
void    Professor::enterStaffRoom()
{
    // St


}
void    Professor::exitClassroom()
{
    if (_isInClass)
    {
        _isInClass = false;
        _currentRoom->exit(this);
    }
}
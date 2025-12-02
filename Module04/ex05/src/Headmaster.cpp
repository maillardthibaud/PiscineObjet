
#include "Headmaster.hpp"

Headmaster::Headmaster(std::string name) : Staff(name), _cpe(nullptr), _nbRoom(0), _state(SchoolState::Start) 
{
    // std::cout << "Headmaster constructor, name : " << _name << std::endl;
}
Headmaster::~Headmaster()
{
    // std::cout << "Headmaster destructor" << std::endl;
}

void	Headmaster::setSecretary(Secretary* cpe)
{   
    _cpe = cpe;
}

void	Headmaster::assignCourseToProf(Course& course, Professor& prof)
{
    if (course.getName() == prof.getSubject())
    {
        if (DEBUG)
            std::cout << "setResponsable to : " << course.getName() << " course and setCourse to prof : " << prof.getName() << std::endl;
        course.setResponsable(&prof);
        prof.setCourse(&course);
        prof.setCurrentRoom(course.getClassroom());
    }
    else
        std::cout << "This professor subject : " << prof.getSubject() <<  " is different from this course subject : " << course.getName() << std::endl;
}

void	Headmaster::needCreationForm(Professor& prof)
{
    NeedCourseCreationForm& nccf = dynamic_cast<NeedCourseCreationForm&>(*_cpe->createForm(FormType::NeedCourseCreation));
    prof.fillCreationForm(nccf);
}

void    Headmaster::needGraduationForm(Professor& prof, Student& stud)
{
    CourseFinishedForm& cff = dynamic_cast<CourseFinishedForm&>(*_cpe->createForm(FormType::CourseFinished));
    prof.fillGraduationForm(cff, stud);
}


void    Headmaster::needSubscriptionCourseForm(Student& stud)
{
    SubscriptionToCourseForm& scf = dynamic_cast<SubscriptionToCourseForm&>(*_cpe->createForm(FormType::SubscriptionToCourse));
    stud.fillSubscriptionForm(scf);
}
void	Headmaster::needClassroomCreation(Professor& prof)
{
    NeedMoreClassRoomForm& nmcf = dynamic_cast<NeedMoreClassRoomForm&>(*_cpe->createForm(FormType::NeedMoreClassRoom));
    prof.fillCreationClassRoomForm(nmcf);
}

void Headmaster::receiveForm(Form* p_form)
{
    switch (p_form->getFormType())
    {
        case FormType::NeedCourseCreation :
        {
            NeedCourseCreationForm& nccf = dynamic_cast<NeedCourseCreationForm&>(*p_form);
            if (nccf.getProf())
                _formToValidate.push_back(&nccf);
            break;
        }
        case FormType::CourseFinished :
        {
               CourseFinishedForm& cff = dynamic_cast<CourseFinishedForm&>(*p_form);
               if (inspectAndVerifyGradForm(cff))
                    _formToValidate.push_back(&cff);
               break;
        }
        case FormType::SubscriptionToCourse : 
        {
            SubscriptionToCourseForm& scf = dynamic_cast<SubscriptionToCourseForm&>(*p_form);
            if (inspectAndVerifySubForm(scf))
                _formToValidate.push_back(&scf);
            break;
        }
        case FormType::NeedMoreClassRoom :
        {
            NeedMoreClassRoomForm& nmcf = dynamic_cast<NeedMoreClassRoomForm&>(*p_form);
            if (inspectAndVerifyClassCreaForm(nmcf))
                _formToValidate.push_back(&nmcf);
            break;
        }
        
        default:
            break;
    }
}


void    Headmaster::addProf(Professor* prof)
{   
    _professors.push_back(prof);
}
void	Headmaster::launchClass()
{
    std::vector<Professor*>::iterator it;
    for (it = _professors.begin(); it != _professors.end(); it++)
        (*it)->doClass();
}

bool    Headmaster::inspectAndVerifyClassCreaForm(NeedMoreClassRoomForm& form)
{
    if (inspectCourse(form.getCourse()))
    {
        if (!form.getCourse()->getClassroom())
        {
            _nbRoom++;
            Classroom* newClassroom = new Classroom(_nbRoom);
            form.setNewRoom(newClassroom);
            return (true);
        }
        
    }
    return (false);
}
bool    Headmaster::inspectCourse(Course* course)
{
    auto& cList = CourseList::getInstance().getList();
    auto findCourse = std::find(cList.begin(), cList.end(), course);
    if (findCourse != cList.end())
        return (true);
    return (false);
}

bool    Headmaster::inspectAndVerifySubForm(SubscriptionToCourseForm& form)
{
    if (inspectStud(form.getStud())) 
    {
        auto& cList = CourseList::getInstance().getList();
        std::vector<Course*>::iterator it;
        for (it = cList.begin(); it != cList.end(); it++)
        {
            if ((*it)->getName() == form.getSubject())
            {
                form.setSubCourse(*it);
                return (true);
            }
        }
    }
    else
        std::cout << "error" << std::endl;
    return (false);
}

bool    Headmaster::inspectAndVerifyGradForm(CourseFinishedForm& form)
{
    if (form.getFinishedCourse() || form.getStudentToGrad())
    {
        if (inspectCourse(form.getFinishedCourse())
                && inspectStud(form.getStudentToGrad())
                && (inspectFormInfo(form.getFinishedCourse(), form.getStudentToGrad())))
                    return true;
        else
            std::cout << "This stud cannnot be graduate for this course " << std::endl;
    }
    return false;
}

bool	Headmaster::inspectFormInfo(Course* course, Student* stud)
{
    std::vector<Course*>::iterator it;
    for (it = stud->getCourses().begin(); it != stud->getCourses().end(); it++)
    {
        if ((*it) == course)
        {
            std::vector<CourseProgress*>::iterator itp;
            for (itp = stud->getProgress().begin(); itp != stud->getProgress().end(); itp++)
            {
                if ((*it) == (*itp)->course && ((*itp)->courseRemain <= 0))
                    return true;
            }
        }
    }
    return(false);
}


bool    Headmaster::inspectStud(Student* stud)
{
    auto& list = StudentList::getInstance().getList();
    auto findStud = std::find(list.begin(), list.end(), stud);
    if (findStud != list.end())
        return (true);
    return (false);

}

void    Headmaster::validateForms()
{
    std::vector<Form*>::iterator it;
    for (it = _formToValidate.begin(); it != _formToValidate.end(); it++)
    {
        if (!(*it)->getIsSigned())
        {
            (*it)->signeForm();
            if (DEBUG)
                std::cout << _name << " has signed form : " << (*it)->getName() << std::endl;
            (*it)->execute();
        }
    }
}


void    Headmaster::setNbRoom(int value)
{
    _nbRoom = value;
}

void	Headmaster::addObserver(iObserver* observer)
{
    _observers.push_back(observer);
}
void	Headmaster::removeObserver(iObserver* observer)
{
    _observers.erase(std::remove(_observers.begin(), _observers.end(), observer), _observers.end());
}

void    Headmaster::durationTime(int time)
{
    if (_state == SchoolState::Recreation)
        std::cout << "Break Time : ";
    else if (_state == SchoolState::Working || _state == SchoolState::Start)
            std::cout << "Working time : ";
    else if (_state == SchoolState::Lunch)
            std::cout << "Lunch time : ";
    std::cout << time << " secondes" << std::endl;
    for (int i = time; i > 0; --i)
    {
        std::cout << i << "...";
        std::this_thread::sleep_for(std::chrono::seconds(1)); 
    }
    std::cout << std::endl;
}

SchoolState     Headmaster::getSchoolState()
{
    return (_state);
}


void    Headmaster::ringTheBell(SchoolState event)
{
    _state = event;
    std::cout << " !! DRING DRING !! " << std::endl;

    switch (_state)
    {
        case SchoolState::Start :
        {
            std::cout << "Start" << std::endl;
            notifyAll(SchoolState::Start);
            launchClass();
            durationTime(3);
            break;
        }
        case SchoolState::Working :
        {
            std::cout << "Working" << std::endl;
            notifyAll(SchoolState::Working);
            launchClass();
            durationTime(3);
            break;
        }
        case SchoolState::Recreation :
        {
            std::cout << "Recreation" << std::endl;
            notifyAll(SchoolState::Recreation);
            durationTime(2);
            break;
        }
        case SchoolState::Lunch :
        {
            std::cout << "Lunch" << std::endl;
            notifyAll(SchoolState::Lunch);
            durationTime(4);
            break;
        }
        default:
            break;
    }
}

void    Headmaster::notifyAll(SchoolState event)
{
    for (auto it = _observers.begin(); it != _observers.end(); it++)
        (*it)->notify(event);
}
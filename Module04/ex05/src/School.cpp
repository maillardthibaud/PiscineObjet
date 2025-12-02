#include "School.hpp"

School::School(Headmaster director, Secretary cpe) : _director(director), _cpe(cpe)
{
}

School::~School()
{
}
Course*                     School::getCourse(std::string p_name)
{
    std::vector<Course*>::iterator it;
    for (it = CourseList::getInstance().getList().begin(); it != CourseList::getInstance().getList().end(); it++)
    {
        if ((*it)->getName() == p_name)
            return (*it);
    }
    std::cout << "Course not find" << std::endl;
    return (nullptr);
}
std::vector<Student*>       School::getStudents()
{
    return _students;
}
std::vector<Professor*>     School::getProfessors()
{
    return _professors;
}
Headmaster                  School::getHeadmaster()
{
    return _director;
}
Secretary                   School::getSecretary()
{
    return _cpe;
}

void                School::recruteProfessor()
{
    std::cout << "-->Recrute Professor" << std::endl;
    Professor* prof = new Professor("Phd Jacquard", "Maths", &_director);
    Professor* prof2 = new Professor("Phd Jacquy", "Geo", &_director);
    Professor* prof3 = new Professor("Phd Joe", "Physics", &_director);
    std::cout << "|-->Add to list" << std::endl;
    auto& iStaff = StaffList::getInstance();
    iStaff.add(prof);
    iStaff.add(prof2);
    iStaff.add(prof3);
    _director.assignCourseToProf(*(getCourse(prof->getSubject())), *prof);
    _director.assignCourseToProf(*(getCourse(prof2->getSubject())), *prof2);
    _director.assignCourseToProf(*(getCourse(prof3->getSubject())), *prof3);
    _director.addProf(prof);
    _director.addProf(prof2);
    _director.addProf(prof3);
    _director.addObserver(prof);
    _director.addObserver(prof2);
    _director.addObserver(prof3);
}

void            School::recruteStudent()
{
    std::cout << "-->Recrute Student" << std::endl;
    Student* boty = new Student("Boty", &_director);
    Student* ludo = new Student("Ludo", &_director);
    Student* david = new Student("David", &_director);
    std::cout << "|-->Add to list" << std::endl;
    auto& iStud = StudentList::getInstance();
    iStud.add(boty);
    iStud.add(ludo);   
    iStud.add(david);
    _director.addObserver(boty);
    _director.addObserver(ludo);
    _director.addObserver(david);
    getCourse("Maths")->subscribe(boty);
    getCourse("Geo")->subscribe(ludo);
    getCourse("Physics")->subscribe(david);
}

void        School::initHeadmaster()
{
    _director.setNbRoom(CourseList::getInstance().getList().size());
    _director.setSecretary(&_cpe);
}
void        School::initCourseAndRoom()
{
    std::cout << "-->Room Creation" << std::endl;
    HeadmasterOffice* directorOffice = new HeadmasterOffice(1);
    SecretarialOffice* cpeOffice = new SecretarialOffice(2);
    StaffRestRoom* staffRoom = new StaffRestRoom(3);
    Classroom* mathRoom = new Classroom(4);
    Classroom* geoRoom = new Classroom(5);
    Classroom* phyRoom = new Classroom(6);
    Courtyard* courtyard = new Courtyard(7);
    std::cout << "|-->Add to list" << std::endl;
    auto& iRoom = RoomList::getInstance();
    iRoom.add(directorOffice);
    iRoom.add(cpeOffice);
    iRoom.add(staffRoom);
    iRoom.add(mathRoom);
    iRoom.add(geoRoom);
    iRoom.add(phyRoom);
    iRoom.add(courtyard);
    std::cout << "-->Course Creation" << std::endl;
    Course* math = new Course("Maths", 3, 1);
    Course* geo = new Course("Geo", 3, 1);
    Course* physic = new Course("Physics", 3, 1);
    std::cout << "|-->Add to list" << std::endl;
    auto& iCourse = CourseList::getInstance();
    iCourse.add(math);
    iCourse.add(geo);
    iCourse.add(physic);
    _courses.push_back(math);
    _courses.push_back(geo);
    _courses.push_back(physic);
    math->addClassroom(mathRoom);
    geo->addClassroom(geoRoom);
    physic->addClassroom(phyRoom);
    mathRoom->assignCourse(math);
    geoRoom->assignCourse(geo);
    phyRoom->assignCourse(physic);
}

void        School::launchClasses()
{
    _director.launchClass();
}

void                        School::runDayRoutine()
{
    _director.ringTheBell(SchoolState::Start);
    _director.ringTheBell(SchoolState::Recreation);
    _director.ringTheBell(SchoolState::Working);
    _director.ringTheBell(SchoolState::Lunch);
    _director.ringTheBell(SchoolState::Working);
    _director.ringTheBell(SchoolState::Recreation);
    _director.ringTheBell(SchoolState::Working);
}

void                        School::requestRingBell()
{
    switch (_director.getSchoolState())
    {
        case SchoolState::Start :
        {
            _director.ringTheBell(SchoolState::Working);
            break;
        }
        case SchoolState::Working :
        {
            _director.ringTheBell(SchoolState::Recreation);
            break;
        }
        case SchoolState::Recreation :
        {
            _director.ringTheBell(SchoolState::Working);
            break;
        }
        case SchoolState::Lunch :
        {
            _director.ringTheBell(SchoolState::Working);
            break;
        }
        default:
            break;
    }
}

void                        School::graduationCeremony()
{
    auto& studList = StudentList::getInstance().getList();
    for (auto it = studList.begin(); it != studList.end(); it++)
    {
        if (!(*it)->getGraduateCourse().empty())
        {
            for (auto itg = (*it)->getGraduateCourse().begin(); itg != (*it)->getGraduateCourse().end(); itg++)
            {
                (*it)->graduate((*itg));
                break;
            }
        }
    }
}
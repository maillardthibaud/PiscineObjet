
#include "Classroom.hpp"

Classroom::Classroom(int idClassroom) : Room(idClassroom), _currentRoom(nullptr)
{
    // std::cout << "Classroom constructor id : " << _id << std::endl;
}
Classroom::~Classroom()
{
    // std::cout << "Classroom destructor id : " << _id << std::endl;
}
void Classroom::assignCourse(Course* p_course)
{
    if(!p_course)
        return;
    if (!_currentRoom)
    {
        _courseName = p_course->getName();
        if (DEBUG)
            std::cout << "Classroom id : " << _id << " has been assign the " << _courseName << " course" << std::endl;
        _currentRoom = p_course;
    }
    else
        std::cout << "This classroom has already a course assign" << std::endl;
}



std::vector<Person*>        Classroom::getOccupants()
{
    return (_occupants);
}

int						Classroom::getId()
{
    return (_id);
}

Course*					Classroom::getCurrentCourse()
{
    return (_currentRoom);
}
bool 					Classroom::canEnter(Person* person)
{
    if (person == _currentRoom->getResponsable())
        return true;
    std::vector<Student*>::iterator it;
    for(it = _currentRoom->getStud().begin(); it != _currentRoom->getStud().end(); it++)
    {
        if ((*it) == person) 
            return true;
    }
    return false;

}
void 					Classroom::enter(Person* person)
{
    std::cout << person->getName() << " enter the room : " << _id << " for the " << _currentRoom->getName() << " course" << std::endl;
    addOccupants(person);
}
void 					Classroom::exit(Person* person)
{
    std::cout << person->getName() << " exit the room : " << _id << std::endl;
    removeOccuppants(person);
}

void                Classroom::addOccupants(Person* person)
{
    _occupants.push_back(person);
}

void                Classroom::removeOccuppants(Person* person)
{
    _occupants.erase(std::remove(_occupants.begin(), _occupants.end(), person), _occupants.end());
}
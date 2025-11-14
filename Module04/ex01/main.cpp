
#include "Room.hpp"
#include "Classroom.hpp"
#include "SecretarialOffice.hpp"
#include "HeadmasterOffice.hpp"
#include "StaffRestRoom.hpp"

#include "Courtyard.hpp"

#include "Person.hpp"
#include "Staff.hpp"
#include "Student.hpp"
#include "Secretary.hpp"
#include "Headmaster.hpp"
#include "Professor.hpp"
#include "Form.hpp"
#include "SubscriptionToCourseForm.hpp"
#include "Singleton.hpp"
#include "StudentList.hpp"


int main()
{

    Student st("Boty");
    Singleton<List<Student>>::getIntance().add(st);

    return (0);
}
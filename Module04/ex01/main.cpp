
#include "Room.hpp"
#include "Classroom.hpp"
#include "SecretarialOffice.hpp"
#include "HeadmasterOffice.hpp"
#include "StaffRestRoom.hpp"

#include "Courtyard.hpp"
#include "Course.hpp"
#include "Person.hpp"
#include "Staff.hpp"
#include "Student.hpp"
#include "Secretary.hpp"
#include "Headmaster.hpp"
#include "Professor.hpp"
#include "Form.hpp"
#include "SubscriptionToCourseForm.hpp"
#include "Singleton.hpp"

int main()
{

    auto& stl = StudentList::getInstance();
    stl.add(Student("Ludo"));
    stl.add(Student("Boty"));

    for (auto s : stl.getList())
        std::cout << "Name : " << s.getName() << std::endl;

    std::cout << "-----------------------" << std::endl;

    auto& sfl = StaffList::getInstance();
    sfl.add(Staff(Headmaster("dirlo")));
    sfl.add(Staff(Secretary("cpe")));

    for (auto s : sfl.getList())
        std::cout << "Name Staff : " << s.getName() << std::endl;

    std::cout << "-----------------------" << std::endl;

    auto& crl = CourseList::getInstance();
    crl.add(Course("Geo", 10, 30));
    crl.add(Course("Latin", 20, 10));
    crl.add(Course("Spanish", 20, 10));

    for (auto s : crl.getList())
    {
        std::cout << "Course of : " << s.getName()
                << ", class to grad : " << s.getNbToGrad()
                << ", max student : " << s.getMaxStud() << std::endl;
    }

    std::cout << "-----------------------" << std::endl;

    auto& rml = RoomList::getInstance();
    rml.add(Room(HeadmasterOffice(1)));
    rml.add(Room(SecretarialOffice(2)));

    for (auto r : rml.getList())
        r.printOccupant();

    return (0);
}
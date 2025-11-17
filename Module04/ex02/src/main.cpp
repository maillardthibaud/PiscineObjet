
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
#include "NeedCourseCreationForm.hpp"

int main()
{
    std::cout << "-->Student Creation" << std::endl;
    Student boty("Boty");
    Student ludo("Ludo");

    auto& iStud = StudentList::getInstance();
    iStud.add(boty);
    iStud.add(ludo);

    std::cout << "-->Staff Creation" << std::endl;
    Secretary cpe("Josephine");
    Headmaster dirlo("Director");

    auto& iStaff = StaffList::getInstance();
    iStaff.add(cpe);
    iStaff.add(dirlo);

    std::cout << "-->Course Creation" << std::endl;
    Course math("Mathematique", 3, 11);
    Course geo("Geographie", 3, 10);

    auto& iCourse = CourseList::getInstance();
    iCourse.add(math);
    iCourse.add(geo);

    std::cout << "-->Classroom Creation" << std::endl;
    Classroom room(12);
    Classroom room2(13);

    std::cout << "-->Classroom assign Course" << std::endl;
    room.assignCourse(&math);
    room2.assignCourse(&geo);

    auto& iRoom = RoomList::getInstance();
    iRoom.add(room);
    iRoom.add(room2);

    

    std::cout << "-->SubToCourseForm Creation" << std::endl;

    Form* formsub = cpe.createForm(FormType::SubscriptionToCourse);
    SubscriptionToCourseForm* sub = dynamic_cast<SubscriptionToCourseForm*>(formsub);

    std::cout << "-->Fill SubToCourseForm" << std::endl;
    sub->fillStudentAndCourse(&boty, &math);

    dirlo.receiveForm(sub);
    dirlo.validateForms();

    std::cout << "-->NeedCourseCreationForm" << std::endl;
    Form* formCourseCrea = cpe.createForm(FormType::NeedCourseCreation);
    NeedCourseCreationForm* courseCrea = dynamic_cast<NeedCourseCreationForm*>(formCourseCrea);
    if (courseCrea->checkCourseCreation(&math))
        dirlo.receiveForm(courseCrea);


    std::cout << "-->Director Validated Form" << std::endl;


    // Form* formsub2 = cpe.createForm(FormType::SubscriptionToCourse);
    // SubscriptionToCourseForm* sub2 = dynamic_cast<SubscriptionToCourseForm*>(formsub2);
    // sub2->fillStudentAndCourse(&boty, &geo);
    // sub2->execute();

    // boty.attendClass(&room);
    // boty.getAllCourseAndRemainClass();








    return (0);
}

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
int main()
{
    HeadmasterOffice ho(1);
    StaffRestRoom srr(2);
    Classroom cr(12);
    SecretarialOffice so(2);
    Courtyard cy(100);

    Headmaster dr("Dirlo");
    Student st("Boty");
    Staff sf("Bocal");
    Secretary sc("42i");
    Professor ps("Wiplier");

    SubscriptionToCourseForm scf;




    return (0);
}
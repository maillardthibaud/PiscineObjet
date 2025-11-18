#include "CourseFinishedForm.hpp"
#include <iostream>


CourseFinishedForm::CourseFinishedForm() : Form(FormType::CourseFinished, "CourseFinishedForm")
{
    // std::cout << "Course finnished constructor" << std::endl;
}
CourseFinishedForm::~CourseFinishedForm()
{
    // std::cout << "Course finnished destructor" << std::endl;
}

void CourseFinishedForm::execute()
{
    std::cout << "Execute Course Finished Form" << std::endl;

}

bool	CourseFinishedForm::inspectFormInfo(Course* course, Student* stud)
{
    std::vector<Course*>::iterator it;
    for (it = stud->getCourses().begin(); it != stud->getCourses().end(); it++)
    {
        if ((*it) == course)
        {
            if (DEBUG)
                std::cout << "Stud register to this course" << std::endl;
            std::vector<CourseProgress*>::iterator itp;
            for (itp = stud->getProgress().begin(); itp != stud->getProgress().end(); it++)
            {
                if ((*it) == (*itp)->course)
                {
                    if(DEBUG)
                        std::cout << "Check progress course remain : " << (*itp)->courseRemain << std::endl;
                    if ((*itp)->courseRemain == 0)
                        return true;
                }
            }
        }
    }
    std::cout << "You re not register to this course" << std::endl;
    return(false);
}
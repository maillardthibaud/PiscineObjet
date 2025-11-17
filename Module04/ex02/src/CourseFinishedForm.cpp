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

void	CourseFinishedForm::checkCourseForStudent(Course* course, Student* stud)
{
    std::vector<Course*>::iterator it;
    for (it = stud->getCourses().begin(); it != stud->getCourses().end(); it++)
    {
        if ((*it) == course)
        {
            
        }

    }

}
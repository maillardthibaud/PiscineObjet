
#include "Headmaster.hpp"
#include <iostream>
#include "Staff.hpp"
#include "Form.hpp"
#include "Singleton.hpp"
#include "NeedCourseCreationForm.hpp"
#include "SubscriptionToCourseForm.hpp"
#include "CourseFinishedForm.hpp"
#include "Professor.hpp"
#include "Course.hpp"

Headmaster::Headmaster(std::string name) : Staff(name), _cpe(nullptr)
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

void Headmaster::receiveForm(Form* p_form)
{

    switch (p_form->getFormType())
    {
        case FormType::NeedCourseCreation :
        {
            NeedCourseCreationForm& nccf = dynamic_cast<NeedCourseCreationForm&>(*p_form);
            if (nccf.getProf())
            {
                nccf.signeForm();
                nccf.execute();
            }
            break;
        }
        case FormType::CourseFinished :
        {
               CourseFinishedForm& cff = dynamic_cast<CourseFinishedForm&>(*p_form);
               if (inspectAndVerifyGradForm(cff))
               {
                    cff.signeForm();
                    cff.execute();
               }
        }
        
        default:
            break;
    }

    // if (p_form && !p_form->getIsSigned())
    // {
    //     if(DEBUG)
    //         std::cout << _name << " has received form : " << p_form->getName()  << std::endl;
    //     _formToValidate.push_back(p_form);
    // }
}
bool    Headmaster::inspectCourse(Course* course)
{
    auto& cList = CourseList::getInstance().getList();
    auto findCourse = std::find(cList.begin(), cList.end(), course);
    if (findCourse != cList.end())
        return (true);
    return (false);
}

bool    Headmaster::inspectAndVerifyGradForm(CourseFinishedForm& form)
{
    if (form.getFinishedCourse() || form.getStudentToGrad())
    {
        if (inspectCourse(form.getFinishedCourse()) && inspectStud(form.getStudentToGrad()) &&
                inspectFormInfo(form.getFinishedCourse(), form.getStudentToGrad()) )
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


// void 	Headmaster::attendClass()
// {

// }
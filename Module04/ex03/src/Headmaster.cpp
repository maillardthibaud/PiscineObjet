
#include "Headmaster.hpp"
#include <iostream>
#include "Staff.hpp"
#include "Form.hpp"
#include "Singleton.hpp"
#include "NeedCourseCreationForm.hpp"
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

// void	Headmaster::addStudent(Student* stud)
// {
//     if (stud)
//     {
//         _students.push_back(stud);
//     }
// }
    
// void	Headmaster::addProfessor(Professor* prof)
// {

// }


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
    // nccf->inspectFormInfo(prof);
    prof.fillCreationForm(nccf);
    if (nccf.getProf())
    {
        nccf.signeForm();
        nccf.execute();
    }


}

void Headmaster::receiveForm(Form* p_form)
{
    
    switch (p_form->getFormType())
    {
        case FormType::NeedCourseCreation :
        {
            // NeedCourseCreationForm* courseCreaForm = dynamic_cast<NeedCourseCreationForm*>(_cpe->createForm(FormType::NeedCourseCreation));
            
            break;

        }
        
        default:
            break;
    }

    if (p_form && !p_form->getIsSigned())
    {
        if(DEBUG)
            std::cout << _name << " has received form : " << p_form->getName()  << std::endl;
        _formToValidate.push_back(p_form);
    }
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
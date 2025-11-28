#ifndef __HEADMASTER_HPP__
#define __HEADMASTER_HPP__

#include <vector>
#include <iostream>
#include <algorithm>

#include "Staff.hpp"
#include "Form.hpp"
#include "Secretary.hpp"
#include "Course.hpp"
#include "Professor.hpp"
#include "Singleton.hpp"
#include "NeedCourseCreationForm.hpp"
#include "SubscriptionToCourseForm.hpp"
#include "CourseFinishedForm.hpp"
#include "NeedMoreClassRoomForm.hpp"

class Headmaster : public Staff
{
	private:

		std::vector<Form*>			_formToValidate;
		Secretary*					_cpe;
		int							_nbRoom;
		
	public:
		
		Headmaster(std::string name);
		~Headmaster();

		void 	receiveForm(Form* p_form);
		void	validateForms();

		void	setSecretary(Secretary* cpe);

		void	assignCourseToProf(Course& course, Professor& prof);

		void	needCreationForm(Professor& prof);
		void    needGraduationForm(Professor& prof, Student& stud);
		void    needSubscriptionCourseForm(Student& stud);
		void	needClassroomCreation(Professor& prof);

		bool    inspectAndVerifyGradForm(CourseFinishedForm& form);
		bool    inspectAndVerifyClassCreaForm(NeedMoreClassRoomForm& form);
		bool    inspectAndVerifySubForm(SubscriptionToCourseForm& form);
		bool 	inspectCourse(Course* course);
		bool    inspectStud(Student* stud);

		bool	inspectFormInfo(Course* course, Student* stud);
};

#endif
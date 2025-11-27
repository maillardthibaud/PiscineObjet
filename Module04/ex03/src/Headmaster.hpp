#ifndef __HEADMASTER_HPP__
#define __HEADMASTER_HPP__

#include <vector>
#include "Staff.hpp"
#include "Form.hpp"
#include "Secretary.hpp"
#include "Course.hpp"
#include "Professor.hpp"
#include <algorithm>

class Headmaster : public Staff
{
	private:

		std::vector<Form*>			_formToValidate;
		// std::vector<Student*>		_students;
		// std::vector<Professor*>		_professors;

		Secretary*					_cpe;
		
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

		bool    inspectAndVerifyGradForm(CourseFinishedForm& form);

		bool    inspectAndVerifySubForm(SubscriptionToCourseForm& form);
		bool 	inspectCourse(Course* course);
		bool    inspectStud(Student* stud);

		bool	inspectFormInfo(Course* course, Student* stud);
		// void	addStudent(Student* stud);
		// void	addProfessor(Professor* prof);



		// void 	attendClass();
};

#endif
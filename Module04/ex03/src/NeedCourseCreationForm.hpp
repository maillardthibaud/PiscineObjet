#ifndef __NEEDCOURSECREATIONFORM_HPP__
#define __NEEDCOURSECREATIONFORM_HPP__

#include <string>
#include "Form.hpp"
#include "Staff.hpp"
#include "Professor.hpp"
#include "Course.hpp"

class Course;

class NeedCourseCreationForm : public Form
{
	private:

			Professor* 		_professor;
			Course*			_course;

	public:

		NeedCourseCreationForm();
		~NeedCourseCreationForm();

		void execute();

		void 	setProf(Professor* p_prof);
		Professor* 	getProf();
		
		// void	setCourse(Course* p_course);

		bool inspectFormInfo(Professor* prof);
};


#endif
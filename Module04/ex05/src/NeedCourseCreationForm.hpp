#ifndef __NEEDCOURSECREATIONFORM_HPP__
#define __NEEDCOURSECREATIONFORM_HPP__

#include <string>
#include <iostream>

#include "Form.hpp"
#include "Staff.hpp"
#include "Professor.hpp"
#include "Course.hpp"
#include "Singleton.hpp"

class Course;

class NeedCourseCreationForm : public Form
{
	private:

			Professor* 		_professor;
			Course*			_course;
			std::string 	_subject;

	public:

		NeedCourseCreationForm();
		~NeedCourseCreationForm();

		void 			execute();

		Professor* 		getProf();

		void 			setProf(Professor* p_prof);
		void			setSubject(std::string subject);

};


#endif
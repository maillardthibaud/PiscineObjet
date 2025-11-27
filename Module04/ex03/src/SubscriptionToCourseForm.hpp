#ifndef __SUBSCRIPTIONTOCOURSEFORM_HPP__
#define __SUBSCRIPTIONTOCOURSEFORM_HPP__


#include "Form.hpp"
#include "Student.hpp"
#include "Course.hpp"
#include <algorithm>

class SubscriptionToCourseForm : public Form
{
	private:

			Student*		_subStudent;
			Course*			_subCourse;
			std::string 	_subSubject;

	public:

		SubscriptionToCourseForm();
		~SubscriptionToCourseForm();

		bool	inspectFormInfo(Student* stud, Course* course);

		void 	execute();
		bool    inspectCourseAndStud(Student* stud, Course* course);

		Student*		getStud();
		std::string		getSubject();

		void	setSubStud(Student* stud);
		void	setSubCourse(Course* course);
		void	setSubjectSub(std::string subject);


		friend class Headmaster;
};


#endif
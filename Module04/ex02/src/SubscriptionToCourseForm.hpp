#ifndef __SUBSCRIPTIONTOCOURSEFORM_HPP__
#define __SUBSCRIPTIONTOCOURSEFORM_HPP__


#include "Form.hpp"
#include "Student.hpp"
#include "Course.hpp"

class SubscriptionToCourseForm : public Form
{
	private:

			Student*		_subStudent;
			Course*			_subCourse;

	public:

		SubscriptionToCourseForm();
		~SubscriptionToCourseForm();

		void	fillStudentAndCourse(Student* stud, Course* course);

		void execute();
};


#endif
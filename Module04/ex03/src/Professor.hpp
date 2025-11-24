#ifndef __PROFESSOR_HPP__
#define __PROFESSOR_HPP__

#include "Staff.hpp"
// #include "Headmaster.hpp"
#include "Form.hpp"
#include "NeedCourseCreationForm.hpp"

class Course;
class Headmaster;

class Professor : public Staff
{
	private:

		std::string		_subjectTeaching;
		Course* 		_currentCourse;

		Headmaster*		_director;

	public:

		Professor(std::string name, std::string subject);
		~Professor();

		std::string 	getName();
		std::string		getSubject();
		Course*			getCurrentCourse();

		void assignCourse(Course* p_course);
		void doClass();
		void closeCourse();


		void	setHeadmaster(Headmaster* p_headmaster);
		void	setCourse(Course* p_course);
		void	needCourseCreationForm();
};
#endif
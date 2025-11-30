#ifndef __PROFESSOR_HPP__
#define __PROFESSOR_HPP__

#include <iostream>

#include "Staff.hpp"

class Course;
class Headmaster;
class NeedCourseCreationForm;
class NeedMoreClassRoomForm;
class CourseFinishedForm;
class Student;

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

		void			setHeadmaster(Headmaster* p_headmaster);
		void			setCourse(Course* p_course);

		void 			assignCourse(Course* p_course);
		void 			doClass();
		void 			closeCourse();

		void			receiveStudForGrad(Student* p_stud);

		void    		fillCreationForm(NeedCourseCreationForm& nccf);
		void    		fillCreationClassRoomForm(NeedMoreClassRoomForm& form);
		void			fillGraduationForm(CourseFinishedForm& cff, Student& stud);
};


#endif
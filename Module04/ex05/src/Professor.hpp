#ifndef __PROFESSOR_HPP__
#define __PROFESSOR_HPP__

#include <iostream>

#include "Staff.hpp"
#include "iObserver.hpp"

class Course;
class Headmaster;
class NeedCourseCreationForm;
class NeedMoreClassRoomForm;
class CourseFinishedForm;
class Student;

class Professor : public Staff, public iObserver
{
	private:

		std::string		_subjectTeaching;
		Course* 		_currentCourse;
		Headmaster*		_director;
		bool			_isInClass;

	public:

		Professor(std::string name, std::string subject, Headmaster* director);
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

		bool 			doesNeedForm();

		void    		fillCreationForm(NeedCourseCreationForm& nccf);
		void    		fillCreationClassRoomForm(NeedMoreClassRoomForm& form);
		void			fillGraduationForm(CourseFinishedForm& cff, Student& stud);


		void			notify(Event event);
};


#endif
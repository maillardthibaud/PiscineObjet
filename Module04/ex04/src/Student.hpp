#ifndef __STUDENT_HPP__
#define __STUDENT_HPP__

#include <iostream>
#include <vector>
#include <map>

#include "Person.hpp"
#include "iObserver.hpp"
#include "Form.hpp"

class Course;
class Classroom;
class SubscriptionToCourseForm;
class Headmaster;

struct CourseProgress
{
	Course* course;
	int		courseRemain;
};


class Student : public Person, public iObserver
{
	private:

		std::vector<Course*> 				_subscribedCourse;
		std::vector<CourseProgress*>		_courseProgress; 
		Headmaster*							_director;		
		std::string 						_subjectSubscription;

		bool								_isInClass;
		

	public:

		Student(std::string name, Headmaster* director);
		~Student();

		std::string						getName();
		std::vector<Course*>&			getCourses();
		std::vector<CourseProgress*>&	getProgress();

		

		void							setHeadmaster(Headmaster* director);

		void							addCourse(Course* course);
		void 							attendClass(Classroom* p_classroom);
		void 							exitClass();
		void 							graduate(Course* p_course);

		void    						askForGraduation(Course* p_course);

		bool        					checkStudentSub(Classroom* p_classroom);
		void							getAllCourseAndRemainClass();

		void 							askForSubscriptionForm(std::string subject);
		void							fillSubscriptionForm(SubscriptionToCourseForm& form);


		void							notify(Event event);
};


#endif
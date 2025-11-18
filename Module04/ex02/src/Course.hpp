#ifndef __COURSE_HPP__
#define __COURSE_HPP__

#include <iostream>
#include <vector>
#include <string>
#include "Classroom.hpp"

class Professor;
class Student;
class Classroom;

class Course
{
	private:

		std::string 			_name;
		Professor* 				_responsable;
		std::vector<Student*> 	_students;
		int 					_numberOfClassToGraduate;
		int						_maximumNumberOfStudent;


		std::vector<Classroom*>	_classroom;

	public:

		Course(std::string p_name, int toGrad, int maxStud);
		~Course();

		std::string 			getName();
		int						getNbToGrad();
		int						getMaxStud();
		std::vector<Student*>	getStud();
		std::vector<Classroom*> getClassroom();
		void					addClassroom(Classroom* room);


		void 					assign(Professor* p_professor);
		void 					subscribe(Student* p_student);

		void					displayInfoCourse();

		bool					countStudent();

};

#endif
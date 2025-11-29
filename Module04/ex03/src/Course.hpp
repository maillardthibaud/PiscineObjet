#ifndef __COURSE_HPP__
#define __COURSE_HPP__

#include <iostream>
#include <vector>
#include <string>

#include "Classroom.hpp"
#include "Professor.hpp"
#include "Course.hpp"
#include "Student.hpp"

class Professor;
class Student;
class Classroom;

class Course
{
	private:

		std::string 			_name;
		std::vector<Student*> 	_students;
		int 					_numberOfClassToGraduate;
		int						_maximumNumberOfStudent;

		Professor* 				_responsable;
		Classroom*				_classroom;

	public:

		Course(std::string p_name, int toGrad, int maxStud);
		~Course();

		std::string 			getName();
		int						getNbToGrad();
		int						getMaxStud();
		std::vector<Student*>	getStud();
		Professor*				getResponsable();
		Classroom*				getClassroom();

		void        			setResponsable(Professor* prof);
		void					setClassRoom(Classroom* classroom);

		void					addClassroom(Classroom* room);
		void 					assign(Professor* p_professor);
		void 					subscribe(Student* p_student);
		void					attendCourse();
		bool					countStudent();

};

#endif
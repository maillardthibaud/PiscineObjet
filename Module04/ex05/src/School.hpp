#ifndef __SCHOOL_HPP__
#define __SCHOOL_HPP__

#include <iostream>
#include <vector>
#include <algorithm>

#include "Headmaster.hpp"
#include "HeadmasterOffice.hpp"
#include "SecretarialOffice.hpp"
#include "StaffRestRoom.hpp"
#include "Classroom.hpp"
#include "Courtyard.hpp"
#include "Secretary.hpp"
#include "Professor.hpp"
#include "Course.hpp"
#include "Student.hpp"


class School
{
    private:

        Headmaster                 _director;
        Secretary                  _cpe;
        std::vector<Professor*>     _professors;
        std::vector<Course*>        _courses;
        std::vector<Student*>       _students;

    public:


        School(Headmaster director, Secretary cpe);
        ~School();

        void                        initHeadmaster();
        void                        initCourseAndRoom();
        void                        initRoom();
        void                        initProf();

        // void                        add

        void                        runDayRoutine();
        void                        launchClasses(); // Make the headmaster ask the students and professors to
        void                        requestRingBell(); // Make the headmaster ring the bell
        void                        recruteProfessor(); // Add a new professor to the school
        void                        recruteStudent(); // Add a new student to the school
        Course*                     getCourse(std::string p_name);// return a course with a given name
        std::vector<Student*>       getStudents(); // return a vector containing every student in school
        std::vector<Professor*>     getProfessors(); // return a vector containing everprofessor in school
        Headmaster                  getHeadmaster(); // return the headmaster of the school
        Secretary                   getSecretary(); // return the secretary of the school
        void                        graduationCeremony(); // launch the graduation of every student that can graduate at a desired momen
};


#endif
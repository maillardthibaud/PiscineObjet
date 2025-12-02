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


        void                        runDayRoutine();
        void                        launchClasses();
        void                        requestRingBell();
        void                        recruteProfessor(); 
        void                        recruteStudent(); 
        Course*                     getCourse(std::string p_name);
        std::vector<Student*>       getStudents();
        std::vector<Professor*>     getProfessors();
        Headmaster                  getHeadmaster();
        Secretary                   getSecretary(); 
        void                        graduationCeremony(); // launch the graduation of every student that can graduate at a desired momen
};


#endif
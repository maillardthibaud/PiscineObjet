#ifndef __NEEDMORECLASSROOMFORM_HPP__
#define __NEEDMORECLASSROOMFORM_HPP__

#include <iostream>

#include "Form.hpp"
#include "Course.hpp"
#include "Room.hpp"
#include "Classroom.hpp"
#include "Professor.hpp"
#include "Singleton.hpp"

class NeedMoreClassRoomForm : public Form
{
	private:

		Professor*			_requester;
		Course* 			_course;
		Classroom*			_newRoom;

	public:

		NeedMoreClassRoomForm();
		~NeedMoreClassRoomForm();



		Course*		getCourse();
		Professor*  getRequester();

		void		setRequester(Professor* prof);
		void		setCourse(Course* course);
		void		setNewRoom(Classroom* classroom);

		void 		execute();

		bool 		inspectFormInfo(Professor* prof);
};
#endif
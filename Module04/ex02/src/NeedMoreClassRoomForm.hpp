#ifndef __NEEDMORECLASSROOMFORM_HPP__
#define __NEEDMORECLASSROOMFORM_HPP__

#include "Form.hpp"
#include "Course.hpp"
#include "Room.hpp"
#include "Classroom.hpp"


class NeedMoreClassRoomForm : public Form
{
	private:


			Course* 		_course;
			Classroom*			_newRoom;


	public:

		NeedMoreClassRoomForm();
		~NeedMoreClassRoomForm();


		bool inspectFormInfo(Course* course);

		void execute();
};
#endif

#include <iostream>
#include "StaffRestRoom.hpp"
        
StaffRestRoom::StaffRestRoom(int id) : Room(id)
{
    std::cout << "StaffRoom construtor, id : " << _id << std::endl;

}
StaffRestRoom::~StaffRestRoom()
{
    std::cout << "StaffRoom destructor" << std::endl;

}
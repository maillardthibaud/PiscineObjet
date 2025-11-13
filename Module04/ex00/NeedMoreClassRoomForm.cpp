#include <iostream>
#include "NeedMoreClassRoomForm.hpp"

NeedMoreClassRoomForm::NeedMoreClassRoomForm() : Form(FormType::NeedMoreClassRoom)
{
    std::cout << "NMCRForm constructor" << std::endl;
}
NeedMoreClassRoomForm::~NeedMoreClassRoomForm()
{

    std::cout << "NMCRForm destructor" << std::endl;
}
void NeedMoreClassRoomForm::execute()
{
    std::cout << "NMCRForm execute" << std::endl;

}
        

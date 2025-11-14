#include <iostream>
#include "SubscriptionToCourseForm.hpp"


SubscriptionToCourseForm::SubscriptionToCourseForm() : Form(FormType::SubscriptionToCourse)
{
    std::cout << "STCForm constructor" << std::endl; 
}
SubscriptionToCourseForm::~SubscriptionToCourseForm()
{
    std::cout << "STCForm destructor" << std::endl; 

}

void SubscriptionToCourseForm::execute()
{
    std::cout << "STCForm execute" << std::endl; 
}
#include <iostream>
#include "Tool.hpp"
#include "Worker.hpp"

class Worker;

Tool::Tool() : _name("default"), _isUse(false), _worker(NULL), numbersOfUses(0)
{
    std::cout << "Tool Constructor " << std::endl;
}

Tool::~Tool()
{
    std::cout << "Tool Destructor " << std::endl;
}
std::string Tool::getName()
{
   return (_name);
}
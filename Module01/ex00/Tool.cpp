#include <iostream>
#include "Tool.hpp"
#include "Worker.hpp"

class Worker;

Tool::Tool() : _name("default"), _isUse(false), _worker(NULL), numbersOfUses(0)
{
}

Tool::~Tool()
{
}
std::string Tool::getName() const
{
   return (_name);
}
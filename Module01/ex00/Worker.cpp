
#include <iostream>
#include <typeinfo>

#include "Worker.hpp"

Worker::Worker(std::string name) :  _coordonnee(0, 0, 0), _stats(1, 0), _name(name), _hasShovel(false)
{
}

Worker::~Worker()
{
}
std::vector<Tool*> Worker::getTool() const
{
    return(_tool);
}
std::string     Worker::getName() const
{
    return (_name);
}

void                Worker::removeTool(Tool* tool)
{
    if(tool)
    {
        std::vector<Tool*>::iterator it;
        for (it = _tool.begin(); it != _tool.end(); it++)
        {
            if (*it == tool)   
            {
                std::cout << "Worker, name : " << _name << " has no longer the tool " << tool->getName() << std::endl;
                _tool.erase(it);
                return;
            }
        }
    }
}

void                Worker::work()
{
    std::cout << "The worker name : " << _name << " is working" << std::endl;
}

void                Worker::addTool(Tool* tool)
{
    if(tool)
    {
        std::cout << _name << " get this tool : " << tool->getName() << std::endl;
        std::vector<Tool*>::iterator it;
        for (it = _tool.begin(); it != _tool.end(); it++)
        {
            if ((*it) == tool)
            {
                std::cout << _name << " already have this tool" << std::endl;
                return;
            }
        }
        _tool.push_back(tool);
    }
}

void                Worker::displayTool() const
{
    std::cout << "Worker name : " << _name;
    if (_tool.empty())
        std::cout << " have no tool" << std::endl;
    else
    {
        std::cout <<" have this tool : " << std::endl; 
        std::vector<Tool*>::const_iterator it;
        for (it = _tool.begin(); it != _tool.end(); it++)
        {
            std::cout << "|->" << (*it)->getName() << std::endl;
        }
    }
}


#include <iostream>
#include <typeinfo>

#include "Worker.hpp"

Worker::Worker(std::string name) :  _coordonnee(0, 0, 0), _stats(1, 0), _name(name), _hasShovel(false)
{
    std::cout << "Worker Constructor" << std::endl;
}

Worker::~Worker()
{
}
std::vector<Tool*> Worker::getTool()
{
    return(_tool);
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


void                Worker::displayTool()
{

    std::cout << "Worker name : " << _name;
    if (_tool.empty())
        std::cout << " have no tool" << std::endl;
    else
    {
        std::cout <<" have this tool : " << std::endl; 
        std::vector<Tool*>::iterator it;
        for (it = _tool.begin(); it != _tool.end(); it++)
        {
            std::cout << "|->" << (*it)->getName() << std::endl;
        }
    }
}
// Tool*               Worker::getTool()
// {
//     return(_tool);

// }

// void    Worker::setShovel(Shovel* sh)
// {
//     if (sh)
//     {
//         std::cout << _name << " has now a shovel" << std::endl;
//         _shovel = sh;
//         _hasShovel = true;
//     }
//     else
//     {
//         std::cout << _name << " dont have any shovel" << std::endl;
//     }
// }

// Shovel*     Worker::getShovel()
// {
//     return (_shovel);
// }

std::string     Worker::getName()
{
    return (_name);
}
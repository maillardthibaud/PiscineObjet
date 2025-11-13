#include "Hammer.hpp"
#include "Worker.hpp"
#include <iostream>


Hammer::Hammer() : Tool()
{
    _name = "Hammer";
    std::cout << "Hammer Constructor" << std::endl;
}   

Hammer::~Hammer()
{
}


void    Hammer::use()
{
    
}
std::string Hammer::getName()
{
    return (_name);
}

void    Hammer::giveTool(Worker* worker)
{
    std::cout << "Give Hammer :";
    if(worker && !_isUse && !_worker)
    {
        std::cout << " To worker :  " << worker->getName() << std::endl;
        _worker = worker;
        // worker->setShovel(this);
        _worker->addTool(this);
        _isUse = true;
    }
    else
    {
        std::cout << " This Hammer is already use by " << _worker->getName() << std::endl; 
        // _worker->setShovel(NULL);
        _worker->removeTool(this);
        std::cout << "This Hammer is now use by : " << worker->getName() << std::endl;
        _worker = worker;
        // _worker->setShovel(this);
        _worker->addTool(this);
    }

}

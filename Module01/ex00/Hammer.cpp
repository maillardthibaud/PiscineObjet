#include "Hammer.hpp"
#include "Worker.hpp"
#include <iostream>

Hammer::Hammer() : Tool()
{
    _name = "Hammer";
}   

Hammer::~Hammer()
{
}
std::string Hammer::getName() const
{
    return (_name);
}

void    Hammer::use()
{
    std::cout << "use : ";
    if (!_worker)
    {
        std::cout << "This hammer is not attribut to any worker." << std::endl;
    }
    else
    {
        numbersOfUses++;
        std::cout << _worker->getName() << " use this hammer, nbUse : " << numbersOfUses << std::endl;
    }
}

void    Hammer::giveTool(Worker* worker)
{
    std::cout << "Give Hammer :";
    if(worker && !_isUse && !_worker)
    {
        std::cout << " To worker :  " << worker->getName() << std::endl;
        _worker = worker;
        _worker->addTool(this);
        _isUse = true;
    }
    else
    {
        std::cout << " This Hammer is already use by " << _worker->getName() << std::endl; 
        _worker->removeTool(this);
        std::cout << "This Hammer is now use by : " << worker->getName() << std::endl;
        _worker = worker;
        _worker->addTool(this);
    }

}

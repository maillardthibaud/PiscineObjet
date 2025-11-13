#include <iostream>
#include "Shovel.hpp"
#include "Worker.hpp"

Shovel::Shovel() : Tool()
{
    _name = "Shovel";
    std::cout << "Shovel Constructor, is use ? " << _isUse << std::endl;
}

Shovel::~Shovel()
{
}

    
    
std::string Shovel::getName()
{
    return (_name);
}

void        Shovel::use()
{
    std::cout << "use : ";
    if (!_worker)
    {
        std::cout << "This shovel is not attribut to any worker." << std::endl;
    }
    else
    {
        numbersOfUses++;
        std::cout << _worker->getName() << " use this shovel nbUse : " << numbersOfUses << std::endl;
    }

}

void    Shovel::giveTool(Worker* worker)
{
    std::cout << "Give Shovel :";
    if(!worker)
        return;
    if (!_worker)
        std::cout << " To worker :  " << worker->getName() << std::endl;
    else if (worker != _worker && _worker)
    {
        std::cout << " This Shovel is already use by " << _worker->getName() << std::endl;    
        _worker->removeTool(this);
        std::cout << "This shovel is now use by : " << worker->getName() << std::endl;
    }
    _worker = worker;
    _worker->addTool(this);
    
}
bool        Shovel::getIsUse()
{
    return (_isUse);
}
void        Shovel::setIsUse(bool value)
{
    _isUse = value;
}
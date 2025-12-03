#include <iostream>
#include <string>
#include "Workshop.hpp"
#include "Worker.hpp"

Workshop::Workshop()
{
}

Workshop::~Workshop()
{
}
void    Workshop::registerWorker(Worker* worker)
{
    if (worker)
    {
        std::cout << "Register worker name : " << worker->getName() << std::endl;
        std::vector<Worker*>::iterator it;
        for(it = _worker.begin(); it != _worker.end(); it++)
        {
            if ((*it) == worker)
            {
                std::cout << "this worker already register" << std::endl;
                return;
            }
        }
        _worker.push_back(worker);
    }
}
void    Workshop::releaseWorker(Worker* worker)
{
    if (worker)
    {
        std::vector<Worker*>::iterator it;
        for (it = _worker.begin(); it != _worker.end(); it++)
        {
            if ((*it) == worker)
            {
                std::cout << "This worker, name : " << (*it)->getName() << " is release from Workshop" << std::endl;
                _worker.erase(it);
                return;
            }
        }
        std::cout << "This worker is not register" << std::endl;
    }
}


void        Workshop::executeWorkDay()
{
    if (_worker.empty())
        std::cout << "No worker register" << std::endl;
    else
    {
        std::vector<Worker*>::iterator it;
        for (it = _worker.begin(); it != _worker.end(); it++)
            (*it)->work();
    }
}
#ifndef __WORKSHOP_HPP__
#define __WORKSHOP_HPP__

#include <vector>

class Worker;

class Workshop
{
    private:

            std::vector<Worker*>    _worker;

    public:

        Workshop();
        ~Workshop();


        void    registerWorker(Worker* worker);
        void    releaseWorker(Worker* worker);
        void    executeWorkDay();
};

#endif



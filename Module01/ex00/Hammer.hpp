
#ifndef __HAMMER_HPP__
#define __HAMMER_HPP__
#include <string>

#include "Tool.hpp"

class Worker;

class Hammer : public Tool
{
    private:

    public:

        Hammer();
        ~Hammer();

        std::string     getName() const;

        void            use();
        void            giveTool(Worker* worker);
};


#endif

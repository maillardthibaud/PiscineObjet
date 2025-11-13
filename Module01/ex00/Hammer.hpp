
#ifndef __HAMMER_HPP__
#define __HAMMER_HPP__
#include <string>

#include "Tool.hpp"
class Worker;

class Hammer : public Tool
{
    private:

        // std::string    _name;
        // bool    _isUse;

    public:

        Hammer();
        ~Hammer();

        std::string     getName();
        void    use();

        void    giveTool(Worker* worker);
};


#endif

#ifndef __SHOVEL_HPP__
#define __SHOVEL_HPP__

#include <string>
#include "Tool.hpp"

class Worker;

class Shovel : public Tool
{
    private:

        // std::string         _name;
        // bool        _isUse;
        // Worker*     _worker;

    public:

        Shovel();
        ~Shovel();




        std::string getName() const;
        bool        getIsUse() const;
        void        setIsUse(bool value);

        void        use();

        void        giveTool(Worker* worker); 



};



#endif
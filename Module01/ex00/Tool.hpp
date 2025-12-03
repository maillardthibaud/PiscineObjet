#ifndef __TOOL_HPP__
#define __TOOL_HPP__

#include <string>
class Worker;

class Tool
{
    private:

    protected:

        std::string         _name;
        bool                _isUse;
        Worker*             _worker;

    public:

        Tool();
        virtual ~Tool();

        
        int                 numbersOfUses;

        std::string         getName() const;

        virtual void        use() = 0;
        virtual void        giveTool(Worker* worker) = 0;

};



#endif
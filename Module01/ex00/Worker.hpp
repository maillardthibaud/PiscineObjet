#ifndef __WORKER_HPP__
#define __WORKER_HPP__

#include <string>
#include <vector>
#include "Shovel.hpp"

struct Position 
{
    int x;
    int y;
    int z;
    Position(int cx, int cy, int cz) : x(cx), y(cy), z(cz){}
};

struct Statistic
{
    int level;
    int exp;
    Statistic(int clevel, int cexp) : level(clevel), exp(cexp) {}
};



class Worker
{
    private:

        Position                    _coordonnee;
        Statistic                   _stats;

        // Shovel*                  _shovel;
        std::vector<Tool*>           _tool;

        std::string                 _name;
        bool                        _hasShovel;


    public:

        Worker(std::string name);
        ~Worker();


        // void            setShovel(Shovel* sh);
        // Shovel*         getShovel();

        std::vector<Tool*>  getTool();
        void                removeTool(Tool* tool);
        void                addTool(Tool* tool);
        void                displayTool();

        void                work();
        // Tool*               getTool();

        std::string     getName();
};

#endif
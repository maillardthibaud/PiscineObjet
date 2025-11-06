#ifndef GRAPH_HPP
#define GRAP_HPP


#include <iostream>
#include <vector>
#include "Vector2.hpp"

class Graph
{
    private:
        
        Vector2                 _size;
        std::vector<Vector2>    _pts;
        bool                    _isPoints;
        
    public:

        Graph(float width, float height);
        ~Graph();

        void    DisplayGraph();
        void    AddPoint(const Vector2& points);
        void    ClearPoint();
};





#endif

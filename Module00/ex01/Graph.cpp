#include "Graph.hpp"

Graph::Graph(float width, float height) : _size(width, height)
{
}

void    Graph::AddPoint(const Vector2& points)
{
    if (points.x > _size.x || points.y > _size.y || points.x < 0 || points.y < 0)
    {
        std::cout << " Vector points are out of the graph : x = " << points.x << ", y = " << points.y << std::endl;
        return;
    }
    _pts.push_back(points);
}

void        Graph::ClearPoint()
{
    std::vector<Vector2>::iterator it;
    for (it = _pts.begin(); it != _pts.end(); it ++)
    {
        _pts.erase(it);
    }
    _pts.clear();
}

void    Graph::DisplayGraph()
{
    int height = _size.x;
    int width = _size.y;
    for (int y = height; y > -1; y--)
    {
        std::cout << " " << y;
        for (int xcount = 0; xcount <= width; xcount++)
        {
            _isPoints = false;
                std::vector<Vector2>::iterator it;
                for (it = _pts.begin(); it != _pts.end(); it++)
                {
                    if (it->x == xcount && it->y == y)
                    {
                        _isPoints = true;
                        break;
                    }
                }
                if (_isPoints)
                    std::cout << " X";
                else
                    std::cout << " .";
        }
        if (y == 0)
        {
            std::cout << std::endl;
            std::cout << "  ";
            for (int x = 0; x <= width; x++)
            {
                std::cout << " " << x;
            }
        }
        else
            std::cout << std::endl;
    }

}

Graph::~Graph()
{
}
#include "Graph.hpp"
#include "Vector2.hpp"

int main()
{
    Graph test(5.0f, 5.0f);
    
    std::cout << "42 exemple -> 0/0 - 2/2 - 4/2 - 2/4" << std::endl;

    test.AddPoint(Vector2(0.0f, 0.0f));
    test.AddPoint(Vector2(2.0f, 2.0f));
    test.AddPoint(Vector2(4.0f, 2.0f));
    test.AddPoint(Vector2(2.0f, 4.0f));

    test.DisplayGraph();

    std::cout << std::endl << std::endl;

    std::cout << " My exemple -> 2/2 - 3/3 - 4/4 - 5/3 - 6/2" << std::endl;

    test.ClearPoint();

    test.AddPoint(Vector2(2.0f, 2.0f));
    test.AddPoint(Vector2(3.0f, 3.0f));
    test.AddPoint(Vector2(4.0f, 4.0f));
    test.AddPoint(Vector2(5.0f, 3.0f));
    test.AddPoint(Vector2(6.0f, 2.0f));
    
    test.DisplayGraph();

    return (0);
}

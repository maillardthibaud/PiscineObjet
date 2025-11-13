
#include "Worker.hpp"
#include "Shovel.hpp"
#include "Workshop.hpp"
#include "Hammer.hpp"
#include <iostream>
// #include "Tool.hpp"

int main()
{

    Worker w("john");
    Worker w2("jack");
    Shovel sh;
    Hammer hm;
    Shovel sh2;
    Hammer hm2;

    sh.giveTool(&w);
    sh.giveTool(&w2);
    // sh.giveTool(&w2);
    // sh.use();
    // sh.giveTool(&w);
    hm.giveTool(&w);
    // hm.giveTool(&w2);
    // hm.giveTool(&w2);
    // sh.use();


    w.displayTool();

    w2.displayTool();


    std::cout << "------------------------" << std::endl;

    Workshop ws;

    ws.registerWorker(&w);
    ws.registerWorker(&w2);

    ws.executeWorkDay();

    std::cout << "------------------------" << std::endl;
    ws.releaseWorker(&w);

    ws.executeWorkDay();
    


    
    return (0);
}
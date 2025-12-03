#include <iostream>

#include "ILogger.hpp"
#include "FileLogger.hpp"
#include "StreamLogger.hpp"
#include "IHeader.hpp"
#include "InfoHeader.hpp"
#include "DateHeader.hpp"


int main()
{
    InfoHeader ih("[INFO]");
    DateHeader dh;

    FileLogger fl("log.txt", &ih);
    StreamLogger sl(std::cout, &dh);

    FileLogger fl2("basic-log.txt");

    StreamLogger sl2(std::cout);

    std::vector<ILogger*>       vectorLogger;

    vectorLogger.push_back(&fl);
    vectorLogger.push_back(&sl);

    vectorLogger.push_back(&fl2);
    vectorLogger.push_back(&sl2);


    std::vector<std::string> listMsg;

    listMsg.push_back("Message 1");
    listMsg.push_back("Message 2");
    listMsg.push_back("Message 3");
    listMsg.push_back("Message 4");
    listMsg.push_back("Message 5");

    std::vector<ILogger*>::const_iterator it;
    std::vector<std::string>::iterator itl;

    for (itl = listMsg.begin(); itl != listMsg.end(); itl++)
    {
        for (it = vectorLogger.begin(); it != vectorLogger.end(); it++)
        {
            (*it)->write((*itl));
        }
    }

    return (0);
}

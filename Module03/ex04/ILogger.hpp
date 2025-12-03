#ifndef ILOGGER_HPP__
#define ILOGGER_HPP__

#include <iostream>
#include <vector>

class ILogger
{
    private:

    public:

        ILogger();
        virtual ~ILogger();

        virtual void write(const std::string& msg) = 0;
};

ILogger::ILogger()
{

}

ILogger::~ILogger()
{
}

#endif
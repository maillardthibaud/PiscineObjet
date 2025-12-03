#ifndef __STREAMLOGGER_HPP__
#define __STREAMLOGGER_HPP__

#include <ostream>
#include <string>
#include "ILogger.hpp"
#include "IHeader.hpp"

class StreamLogger : public ILogger
{
    private:

            std::ostream&    _ostream;
            IHeader*        _header;            

    public:

        StreamLogger(std::ostream& stream, IHeader* h);
        ~StreamLogger();

        virtual void    write(const std::string& msg);
};

StreamLogger::StreamLogger(std::ostream& stream, IHeader* h = 0) : _ostream(stream), _header(h)
{
}

StreamLogger::~StreamLogger()
{
}

void    StreamLogger::write(const std::string& msg)
{
    if (_header)
    {
        _ostream << _header->getTextHeader();
    }
    _ostream << msg << std::endl;
}

#endif
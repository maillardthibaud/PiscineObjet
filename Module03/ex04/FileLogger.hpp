#ifndef __FILELOGGER_HPP__
#define __FILELOGGER_HPP__

#include <fstream>
#include <string>

#include "ILogger.hpp"
#include "IHeader.hpp"


class FileLogger : public ILogger
{
    private:

            std::ofstream    _file;
            IHeader*        _iheader;

    public:

        FileLogger(const std::string& filename, IHeader* h);
        ~FileLogger();

        virtual void write(const std::string& msg);
};

FileLogger::FileLogger(const std::string& filename, IHeader* h = 0) : _iheader(h)
{
    _file.open(filename.c_str(), std::ios::app);
}

FileLogger::~FileLogger()
{
    _file.close();
}

void FileLogger::write(const std::string& msg)
{
    if (_iheader)
    {
        _file << _iheader->getTextHeader();
    }
    _file << msg << std::endl;

}

#endif
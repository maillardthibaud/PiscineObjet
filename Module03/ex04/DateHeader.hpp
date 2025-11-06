#ifndef __DATEHEADER_HPP__
#define __DATEHEADER_HPP__

#include <ctime>
#include <sstream>
#include <iomanip>
#include "IHeader.hpp"


class DateHeader : public IHeader
{
    private:

    public:

        DateHeader();
        ~DateHeader();

        virtual std::string getTextHeader() const;
};

DateHeader::DateHeader()
{
}

DateHeader::~DateHeader()
{
}

std::string DateHeader::getTextHeader() const
{
    std::time_t time = std::time(0);
    std::tm* local = std::localtime(&time);
    std::stringstream ss;
    ss << "[" << (local->tm_year + 1900) << "-"
    << std::setfill('0') << std::setw(2) << (local->tm_mon + 1) << "-"
    << std::setfill('0') << std::setw(2) << local->tm_mday << "]";

    return (ss.str());
}

#endif
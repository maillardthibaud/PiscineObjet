#ifndef __IHEADER_HPP__
#define __IHEADER_HPP__

#include <iostream>

class IHeader
{
    private:

    public:
        virtual ~IHeader();

        virtual std::string getTextHeader() const = 0;
};

IHeader::~IHeader()
{
}


#endif
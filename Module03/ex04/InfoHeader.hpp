#ifndef __INFOHEADER_HPP__
#define __INFOHEADER_HPP__

#include <iostream>
#include "IHeader.hpp"


class InfoHeader : public IHeader
{
    private:

        std::string     _textHeader;

    public:

        InfoHeader(const std::string& textHeader);
        ~InfoHeader();

        virtual std::string     getTextHeader() const;
};

InfoHeader::InfoHeader(const std::string& textHeader): _textHeader(textHeader)
{
}

InfoHeader::~InfoHeader()
{
}

std::string InfoHeader::getTextHeader() const
{
    return (_textHeader);
}


#endif


#ifndef __PACKAGEREDUCTIONDISCOUNT_HPP__
#define __PACKAGEREDUCTIONDISCOUNT_HPP__

#include "Command.hpp"

class PackageReductionDiscountCommand : public Command
{
    private:

    public:
    
        PackageReductionDiscountCommand(int id, const std::string &date, const std::string &client, const std::string& article, int qtt);
        ~PackageReductionDiscountCommand();

        float getTotalPrice();
};

#endif
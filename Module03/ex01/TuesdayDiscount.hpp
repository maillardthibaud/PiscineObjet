#ifndef __TUESDAYDISCOUNT_HPP__
#define __TUESDAYDISCOUNT_HPP__

#include "Command.hpp"

class TuesdayDiscountCommand : public Command
{
    private:

    public:

        TuesdayDiscountCommand(int id, const std::string &date, const std::string &client, const std::string& article, int qtt);
        ~TuesdayDiscountCommand();

        float       getTotalPrice();
};


#endif
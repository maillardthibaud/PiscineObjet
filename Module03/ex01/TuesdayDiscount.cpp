

#include "TuesdayDiscount.hpp"
#include "Command.hpp"


TuesdayDiscountCommand::TuesdayDiscountCommand(int id, const std::string &date, const std::string &client, const std::string& article, int qtt)
 : Command (id, date, client, article, qtt)
{
    std::cout << "Create Tuesday Command ->" << std::endl;
    std::cout << "id : " << id << std::endl;
    std::cout << "date : " << date << std::endl;
    std::cout << "client : " << client << std::endl;
    std::cout << "article : " << article << std::endl;
    std::cout << "quantity : " << qtt << std::endl;
    if (!Command::CheckArticle(article))
    {
        std::cout << "Unknow article" << std::endl;
        return;
    }
    std::cout << "Price of " << article << " is : " << Command::_articlePrice[article] << std::endl;
    std::cout << " ----------------------------------------------------- " << std::endl;
}

TuesdayDiscountCommand::~TuesdayDiscountCommand()
{
}

float       TuesdayDiscountCommand::getTotalPrice()
{
    float result = Command::getBasePrice();
    result *= 0.9;
    std::cout << "Apply tuesday discount, new price : " << result << std::endl;
    return (result);
}



#include "PackageReductionDiscount.hpp"

PackageReductionDiscountCommand::PackageReductionDiscountCommand(int id, const std::string &date, const std::string &client, const std::string& article, int qtt)
 : Command(id, date, client, article, qtt)
{
    std::cout << "Create Package Reduction Command ->" << std::endl;
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

PackageReductionDiscountCommand::~PackageReductionDiscountCommand()
{
}

float PackageReductionDiscountCommand::getTotalPrice()
{
    float result = Command::getBasePrice();
    if (result > 150.0f)
    {
        result -= 10.0f;
        std::cout << "Apply reduction on price ( -10 euros), new price : " << result << std::endl;
    }
    return (result);
}

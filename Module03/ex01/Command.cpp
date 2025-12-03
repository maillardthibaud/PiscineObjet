#include "Command.hpp"
#include <map>
Command::Command()
{
}
Command::~Command()
{
}
void    Command::InitArticlesPrice()
{
    _articlePrice["Apple"] = 1.1f;
    _articlePrice["Water"] = 0.89f;
    _articlePrice["Green Tea"] = 2.3f;
}


Command::Command(int id, const std::string& date, const std::string& client, const std::string& article, int qtt) :
_id(id), _date(date), _clientName(client)
{
    std::cout << "Constructor Command, Init price and insert in map" << std::endl;
    InitArticlesPrice();
    _articles.insert(std::pair<std::string, int>(article, qtt));

}

float   Command::getBasePrice()
{
    float result = 0;
    std::map<std::string, float>::iterator itPrice;
    std::map<std::string, int>::iterator itQtt;
    if (_articlePrice.empty())
        std::cout <<"empty" << std::endl;
    for (itQtt = _articles.begin(); itQtt != _articles.end(); itQtt++)
    {
        for (itPrice = _articlePrice.begin(); itPrice != _articlePrice.end(); itPrice++)
        {
            if (itQtt->first == itPrice->first)
            {
                result = itQtt->second * itPrice->second;
                std::cout << "Base price : " << result << std::endl;
                return (result);
            }
        }

    }
    return (result);
}

bool Command::CheckArticle(std::string article)
{
    std::map<std::string, float>::iterator it;

    for(it = _articlePrice.begin(); it != _articlePrice.end(); it++)
    {
        if (it->first == article)
            return (true);
    }
    return (false);
}



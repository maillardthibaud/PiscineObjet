#ifndef __COMMAND_HPP__
#define __COMMAND_HPP__

#include <iostream>
#include <map>


class Command
{
    private:

        int                                   _id;
        const std::string                     _date;
        const std::string                     _clientName;
        std::map<std::string, int>            _articles;

    protected:

        void    InitArticlesPrice();
        float   getBasePrice();
        bool    CheckArticle(std::string article);


    public:

        std::map<std::string, float>          _articlePrice;

        Command();
        Command(int id, const std::string& date, const std::string& client, const std::string& articles, int qtt) ;

        virtual ~Command();

        virtual float   getTotalPrice() = 0;



};




#endif
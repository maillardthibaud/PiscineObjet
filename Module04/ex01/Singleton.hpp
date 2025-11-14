
#ifndef __SINGLETON_HPP__
#define __SINGLETON_HPP__
#include <vector>
#include <iostream>

template <typename T>
class List
{
    private:
            std::vector<T>     _listItems;

    public:

        void    add(const T& item){
            _listItems.push_back(item);
        }
        void    remove(const T& item){
            _listItems.erase(item);
        }
        std::vector<T>  getList(){
            return (_listItems);
        }

}



template <typename S>
class Singleton
{
    private:


        Singleton() = delete;
        Singleton&(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;

    public:

        static S& getIntance(){
            static S instance;
            return (instance)
        }
        ~Singleton();
};


#endif
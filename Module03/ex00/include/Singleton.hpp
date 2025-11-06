
#ifndef __SINGLETON_HPP__
#define __SINGLETON_HPP__

#include <iostream>
#include <typeinfo>

template<class T>
class Singleton
{
    protected:

            Singleton();
            virtual ~Singleton();

    private:

            Singleton(const Singleton&); 
            Singleton& operator=(const Singleton&);  

    public:

            static T& getInstance();


};


template<class T>
Singleton<T>::Singleton()
{
    std::cout << "Singleton Constructor " << typeid(T).name() << " > at : " << this << std::endl;
}

template<class T>
Singleton<T>::~Singleton()
{
    std::cout << "destro single" << std::endl;
}

template<class T>
T& Singleton<T>::getInstance()
{
    static T instance;
    return instance;
}

#endif
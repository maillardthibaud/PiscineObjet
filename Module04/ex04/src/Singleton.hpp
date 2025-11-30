
#ifndef __SINGLETON_HPP__
#define __SINGLETON_HPP__

#ifndef DEBUG
#define DEBUG 1
#endif

#include <vector>
#include <iostream>
#include <mutex>

#include "Student.hpp"

template <typename S>
class Singleton
{
    private:

        static Singleton<S>* _instance;
        static std::mutex _mutex;

        std::vector<S> _list;

        Singleton() = default;
        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;

    public:

        static Singleton<S>&            getInstance();
        
        void                            add(const S& item);
        void                            remove(const S& item);
        std::vector<S>&                 getList();

        ~Singleton();
};


template <typename S>
Singleton<S>* Singleton<S>::_instance = nullptr;

template <typename S>
std::mutex Singleton<S>::_mutex;

class Student;
using StudentList = Singleton<Student*>;

class Staff;
using StaffList = Singleton<Staff*>;


class Course;
using CourseList = Singleton<Course*>;

class Room;
using RoomList = Singleton<Room*>;


template <typename S>
Singleton<S>& Singleton<S>::getInstance()
{
    std::lock_guard<std::mutex> lock(_mutex);
    if (!_instance)
    {
        _instance = new Singleton<S>();
    }
    return (*_instance);
}

template <typename S>
void Singleton<S>::add(const S& item)
{
    std::lock_guard<std::mutex> lock(_mutex);
    _list.push_back(item);
}

template <typename S>
std::vector<S>& Singleton<S>::getList()
{
    return(_list);
}

#endif

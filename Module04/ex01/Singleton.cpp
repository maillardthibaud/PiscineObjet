
// #include "Singleton.hpp"

// template <typename S>
// Singleton<S>& Singleton<S>::getInstance()
// {
//     std::lock_guard<std::mutex> lock(_mutex);
//     if (!_instance)
//     {
//         _instance = new Singleton<S>();
//     }
//     return (*_instance);
// }

// template <typename S>
// void Singleton<S>::add(const S& item)
// {
//     std::lock_guard<std::mutex> lock(_mutex);
//     _list.push_back(item);
// }

// template <typename S>
// void Singleton<S>::remove(const S& item)
// {
//     std::lock_guard<std::mutex> lock(_mutex);
//     typename std::vector<S>::iterator it = std::find(_list.begin(), _list.end(), item);
//     if (it != _list.end())
//         _list.erase(it);
// }


// template <typename S>
// std::vector<S>& Singleton<S>::getList()
// {
//     return(_list);
// }


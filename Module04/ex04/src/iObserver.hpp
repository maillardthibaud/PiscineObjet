#ifndef __IOBSERVER_HPP__
#define __IOBSERVER_HPP__

enum class Event
{
	RingBell
};


class iObserver
{
    private:

    public:

        virtual ~iObserver() {};
        virtual void notify(Event event) = 0;
};



#endif
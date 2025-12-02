#ifndef __IOBSERVER_HPP__
#define __IOBSERVER_HPP__

enum class Event
{
	RingBell
};

enum class SchoolState
{ 
	Start = 0,

	Working = 1,

	Recreation = 2,

	Lunch = 3,

	End = 4,
};

class iObserver
{
    private:

    public:

        virtual ~iObserver() {};
        virtual void notify(SchoolState event) = 0;
};



#endif
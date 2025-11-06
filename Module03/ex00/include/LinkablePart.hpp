#ifndef __LINKABLEPART_HPP__
#define __LINKABLEPART_HPP__

class LinkablePart
{
    private:

    protected:

        LinkablePart();

    public:

        virtual ~LinkablePart();

        virtual void execute(float p_pression) = 0;
};

#endif
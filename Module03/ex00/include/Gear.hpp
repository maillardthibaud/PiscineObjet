#ifndef __GEAR_HPP__
#define __GEAR_HPP__

class Gear
{
    private:

        int         demultiplier;
        int         idx;
        std::string name;
        float       vMax;

    public:


        Gear();
        ~Gear();

        int             getIdx();
        std::string     getName();
        int             getDemult();
        float           getVmax();
        
        void            setName(std::string);
        void            setVmax(float value);

        friend class GearLever;

};

#endif
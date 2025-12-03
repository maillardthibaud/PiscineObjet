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

        int             getIdx() const;
        std::string     getName() const;
        int             getDemult() const;
        float           getVmax() const;
        
        void            setName(std::string);
        void            setVmax(float value);

        friend class GearLever;

};

#endif
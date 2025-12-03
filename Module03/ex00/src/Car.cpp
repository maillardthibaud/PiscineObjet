
#include <iostream>
#include <vector>
#include <typeinfo>
#include "../include/Car.hpp"
// #include "Pedal.hpp"


Car::Car() : gl(GearLever::getInstance()), currSpeed(0.0f)
{
    std::cout << "Constructor " << typeid(this).name() << std::endl;
    Init();
}
Car::~Car()
{
}

void Car::Init()
{
    std::cout << "-->> Transmission set Wheel from Direction" << std::endl;
    tr.addWheel(&(direction));

    std::cout << "-->> Motor get Crankshaft and set Transmission" << std::endl;
    motor.connectToTransmission(&tr);

    std::cout << "-->> Cocpit get SteerWheel, amd set DAE from Electronics" << std::endl;

    cockpit.getSteer().setDae(elect.getDae());

    std::cout << "-->> Electronics get DAE, and set Direction" << std::endl;

    elect.getDae()->setDirection(&direction);

    std::cout << "-->> Cockpit get DriverInfo, and set their whell from Direction and Motor" << std::endl;

    cockpit.getDriverInfo().setWheelInfo(&direction.wheel[0]);
    cockpit.getDriverInfo().setBrakeController(&bc);
    cockpit.getDriverInfo().setMotor(&motor);

    tr.setCar(this);

    std::cout << "-->> BrakeController get Brakes and set their wheel" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        bc.getBrake(i)->attackWheel(tr.wheelVector[i]);
    }
    std::cout << "-->> Your car is Ready" <<  std::endl;

    cockpit.getDriverInfo().displayDriverInfo();
}

void Car::start()
{
    std::cout << "Try to Start your engine..." << std::endl;
    motor.StartMotor();
}

void    Car::stop()
{
    if (!motor.getIsOn())
        std::cout << "You try to stop the car, but the motor is not start yet..." <<std::endl;
    else
    {
        bc.execute(1.0f);
        motor.stopMotor();
        gl.setLevel(0);
        displayGear();
    }
}

void    Car::checkBrakePressure()
{
    for (int i = 0; i < 4; i++)
    {
        int purCent = bc.getBrake(i)->getForce() * 100;
        std::cout << "Brake n " << i << " have " <<  purCent << " % force on it" << std::endl;
    }
}
void Car::displayGear()
{
    std::cout << "The current gear is : " << gl.activeGear()->getName() << std::endl;;
}


void Car::accelerate(float speed)
{
    if (!motor.getIsOn())
        std::cout << "The motor is off." << std::endl;
    else if (gl.activeGear()->getIdx() == 0)
        std::cout << "You cant move, maybe try to shift gear...." << std::endl;
    else if (bc.getIsPark())
        std::cout << "Maybe try to remove the Parking brake" << std::endl;
    else
    {
        if (!checkSpeed(speed))
            return;
        Injector* ij = motor.getInjector();
        if (!ij)
            return;
        Pedal& pedal = cockpit.getPedal();
        pedal.setTarget(ij);
        currSpeed = speed;
        checkGearSpeed(speed);
        float speedToPressure = currSpeed / 100;
        pedal.use(speedToPressure);
    }
}

bool Car::checkSpeed(float speed)
{
    if (speed <= 0)
    {
        std::cout << "You cant accelerate in negative way... Try to reverse then accelerate !" << std::endl;
        return (false);
    }
    return (true);
}

void Car::checkGearSpeed(float speed)
{
    Gear* g = gl.activeGear();
    int gear = g->getIdx();
    switch (gear)
    {
        case 1:
            {
                if (speed > 61.0f)
                {
                    currSpeed = 61.0f;
                    tr.setVmax(true);
                    std::cout << "You are going the vmax for the gear : " << g->getName() << " speed max : " << currSpeed << std::endl;
                }
                break;
            }
        case 2:
            {
                if (speed > 84.0f)
                {
                    tr.setVmax(true);
                    currSpeed = 84.0f;
                    std::cout << "You are going the vmax for the gear : " << g->getName() << " speed max : " << currSpeed << std::endl;
                }
                break;
            }
        case 3:
            {
                if (speed > 110.0f)
                {
                    currSpeed = 110.0f;
                    tr.setVmax(true);
                    std::cout << "You are going the vmax for the gear : " << g->getName() << " speed max : " << currSpeed << std::endl;
                }
                break;
            }
        case 4:
            {
                if (speed > 140.0f)
                {
                    tr.setVmax(true);
                    currSpeed = 140.0f;
                    std::cout << "You are going the vmax for the gear : " << g->getName() << " speed max : " << currSpeed << std::endl;
                }
                break;
            }
        case 5:
            {
                if (speed > 198.0f)
                {
                    currSpeed = 198.0f;
                    tr.setVmax(true);
                    std::cout << "You are going the vmax for the gear : " << g->getName() << " speed max : " << currSpeed << std::endl;
                }
                break;
            }
        case -1:
            {
                if (speed > 61.0f)
                {
                    currSpeed = 61.0f;
                    tr.setVmax(true);
                    std::cout << "You are going the vmax for the gear : " << g->getName() << " speed max : " << currSpeed << std::endl;
                }
                break;
            }
        default:
            break;
    }
}
void Car::shift_gears_up()
{
    displayGear();
    gl.increaseLevel();
    displayGear();

}

void Car::shift_gear_down()
{
    displayGear();
    gl.decreaseLevel();
    displayGear();
}

void   Car::activeParkingBrake(bool active)
{
    std::cout << "Active parking brake : ";
    if (active)
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;
    if (active == true)
        bc.switchParkingBrake(true);
    else
        bc.switchParkingBrake(false);

}

void Car::reverse()
{
    std::cout << "Activate Reverse" << std::endl;
    if (direction.wheel[0].getSpeed() > 0.5f)
    {
        std::cout << "Are you crazy ? You try to put reverse gear when you are actually at : " << direction.wheel[0].getSpeed() << " km/h !!" << std::endl;
        std::cout << "Brake until you stop the car and put reverse then !! " << std::endl;
        return;
    }
    GearLever& gl = GearLever::getInstance();
    gl.setLevel(-1);
    displayGear(); 
}
void Car::turn_whell(float angle)
{
    cockpit.getSteer().turn(angle);
}
void Car::straighten_wheels()
{
    cockpit.getSteer().turn(0.0f);
}
void Car::appply_force_on_brakes(float force)
{
    cockpit.getPedal().setTarget(&bc);
    cockpit.getPedal().use(force);

}
void Car::apply_emergency_brakes()
{
    appply_force_on_brakes(1.0f);
    bc.switchParkingBrake(true);
}


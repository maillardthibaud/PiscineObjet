

#include <iostream>
#include <vector>
#include <typeinfo>

#include "../include/Car.hpp"

int main()
{

    std::cout << "---------------------- Car Creation --------------------" << std::endl;
    Car test;

    std::cout << "---------------------- Start Car -----------------------" << std::endl;

    test.start();
    std::cout << "----------------------- Accelerate in neutral and parkBrake on -----------------------" << std::endl;

    test.accelerate(10.0f);

    std::cout << "----------------------- shift first then Accelerate -------------------------------------------" << std::endl;

    test.shift_gears_up();
    test.accelerate(10.0f);

    std::cout << "----------------------- Parking brake off then then Accelerate -------------------------------------------" << std::endl;

    test.activeParkingBrake(false);
    test.accelerate(10.0f);

    std::cout << "----------------------- Diver info --------------- " << std::endl;
    test.cockpit.getDriverInfo().displayDriverInfo();
    std::cout << "---------------------" << std::endl;

    test.accelerate(10.0f);

    std::cout << "----------------------- Diver info --------------- " << std::endl;
    test.cockpit.getDriverInfo().displayDriverInfo();
    std::cout << "---------------------" << std::endl;

    test.shift_gears_up();

    std::cout << "----------------------- Diver info --------------- " << std::endl;
    test.cockpit.getDriverInfo().displayDriverInfo();
    std::cout << "---------------------" << std::endl;

    test.appply_force_on_brakes(0.1f);

    std::cout << "----------------------- Diver info --------------- " << std::endl;
    test.cockpit.getDriverInfo().displayDriverInfo();
    std::cout << "---------------------" << std::endl;

    test.accelerate(100.0f);

    std::cout << "----------------------- Diver info --------------- " << std::endl;
    test.cockpit.getDriverInfo().displayDriverInfo();   
    std::cout << "---------------------" << std::endl;

    test.appply_force_on_brakes(0.0f);

    std::cout << "----------------------- Diver info --------------- " << std::endl;
    test.cockpit.getDriverInfo().displayDriverInfo();
    std::cout << "---------------------" << std::endl;

    // test.apply_emergency_brakes();
    // test.appply_force_on_brakes(1.0f);
    std::cout << "----------------------- Diver info --------------- " << std::endl;
    test.cockpit.getDriverInfo().displayDriverInfo();
    std::cout << "---------------------" << std::endl;

    test.accelerate(50.0f);

    std::cout << "----------------------- Diver info --------------- " << std::endl;
    test.cockpit.getDriverInfo().displayDriverInfo();
    std::cout << "---------------------" << std::endl;

    test.turn_whell(10.0f);
    std::cout << "----------------------- Diver info --------------- " << std::endl;
    test.cockpit.getDriverInfo().displayDriverInfo();
    std::cout << "---------------------" << std::endl;

    test.straighten_wheels();

    std::cout << "----------------------- Diver info --------------- " << std::endl;
    test.cockpit.getDriverInfo().displayDriverInfo();
    std::cout << "---------------------" << std::endl;


    return (0);
}
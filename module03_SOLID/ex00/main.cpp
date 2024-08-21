#include "Car.hpp"

int	main() {
	std::cout << "Let's take the car from the garage !" << std::endl;
	
	Car	car;

	std::cout << car << std::endl;

	std::cout << "Let's start the car to go to the market" << std::endl;
	car.start();
	car.shift_gears_up();
	std::cout << car << std::endl;

	car.shift_gears_up();
	car.accelerate(15);
	std::cout << car << std::endl;

	car.shift_gears_up();
	car.accelerate(15);
	car.turn_wheel(15.0);
	std::cout << car << std::endl;

	car.shift_gears_up();
	car.accelerate(20);
	car.straighten_wheels();
	std::cout << car << std::endl;

	car.shift_gears_up();
	car.accelerate(30);
	car.turn_wheel(-20.0);
	std::cout << car << std::endl;

	std::cout << "Shit ! We are in town, let's slow down" << std::endl;
	car.apply_force_on_brakes(40.0);
	car.shift_gears_down();
	car.slowDown(31);
	car.straighten_wheels();
	std::cout << car << std::endl;

	car.apply_force_on_brakes(0.0);
	std::cout << "It's here ! We missed the gate" << std::endl;
	car.apply_emergency_brakes();
	car.shift_gears_down();
	car.shift_gears_down();
	car.shift_gears_down();
	car.shift_gears_down();
	car.slowDown(car.getSpeed());
	std::cout << car << std::endl;

	std::cout << "Let's park here" << std::endl;
	car.apply_force_on_brakes(0.0);
	car.reverse();
	car.accelerate(10);
	car.turn_wheel(38.0);
	std::cout << car << std::endl;

	car.apply_force_on_brakes(20.0);
	car.slowDown(4);
	car.straighten_wheels();
	std::cout << car << std::endl;

	car.stop();
	std::cout << car << std::endl;
}

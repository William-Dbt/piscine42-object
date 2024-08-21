#ifndef __CAR_HPP__
# define __CAR_HPP__

# include <iostream>
# include "Motor.hpp"
# include "Brakes.hpp"
# include "GearLever.hpp"
# include "Wheels.hpp"

class	Car {
	public:
		Car() {
			this->_speed = 0;
		}

		void	start() {
			this->_motor.start();
		}

		void	stop() {
			this->_motor.stop();
			this->_brakes.applyPression(100.0);
			this->_speed = 0.0;
			this->straighten_wheels();

			int	actualGearLevel = this->_gearLever.getActiveLevelGear();

			if (actualGearLevel == -1)
				this->shift_gears_up();
			else if (actualGearLevel > 0) {
				while (this->_gearLever.getActiveLevelGear() != 0)
					this->shift_gears_down();
			}
		}

		void	accelerate(int speed) {
			if (this->_motor.getEngineStatus() == STOPPED) {
				std::cerr << "[WARNING] Car: you can't accelerate til' the car is stopped." << std::endl;
				return ;
			}
			if (speed <= 0) {
				std::cerr << "[ERROR] Car: the speed value to accelerate is not valid." << std::endl;
				return ;
			}
			this->_speed += speed;
		}

		void	slowDown(int speed) {
			if (this->_motor.getEngineStatus() == STOPPED)
				return ;

			if (speed < 0) {
				std::cerr << "[ERROR] Car: the speed value to slow down is not valid." << std::endl;
				return ;
			}
			if (this->_speed - speed < 0) {
				std::cerr << "[ERROR] Car: the reduced speed cannot be lower than 0 km/h." << std::endl;
				return ;
			}
			this->_speed -= speed;
		}

		void	shift_gears_up() {
			this->_gearLever.shiftGearUp();
		}

		void	shift_gears_down() {
			this->_gearLever.shiftGearDown();
		}

		void	reverse() {
			this->_gearLever.shiftGearDown(true);
		}

		void	turn_wheel(float angle) {
			this->_wheels.setTurnAngle(angle);
		}

		void	straighten_wheels() {
			this->_wheels.setTurnAngle(0.0);
		}

		void	apply_force_on_brakes(float force) {
			this->_brakes.applyPression(force);
		}

		void	apply_emergency_brakes() {
			this->_brakes.applyPression(100.0);
		}

		int	getMotorStatus() {
			return this->_motor.getEngineStatus();
		}

		int	getSpeed() {
			return this->_speed;
		}

		float	getBrakePressure() {
			return this->_brakes.getPression();
		}

		int	getGearLevel() {
			return this->_gearLever.getActiveLevelGear();
		}

		std::string	getGearLevelName() {
			return this->_gearLever.getActiveLevelGearName();
		}

		float	getWheelsAngle() {
			return this->_wheels.getTurnAngle();
		}

	private:
		int	_speed;

		Motor		_motor;
		Brakes		_brakes;
		GearLever	_gearLever;
		Wheels		_wheels;
};

std::ostream&	operator<<(std::ostream &stream, Car &car) {
	stream << "----- CAR INFORMATIONS -----" << std::endl;
	stream << "- Motor status : " << (car.getMotorStatus() == STARTED ? "Started" : "Stopped") << '\n';
	stream << "- Actual speed : " << car.getSpeed() << '\n';
	stream << "- Actual brake pressure : " << car.getBrakePressure() << "%\n";
	stream << "- Actual gear lever : " << car.getGearLevelName() << " (" << car.getGearLevel() << ")\n";
	stream << "- Actual wheel angle : " << car.getWheelsAngle() << '\n';
	stream << "---------------" << std::endl;

	return stream;
}

# endif
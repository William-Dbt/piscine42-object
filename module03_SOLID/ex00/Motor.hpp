#ifndef __MOTOR_HPP__
# define __MOTOR_HPP__

# define STOPPED	0
# define STARTED	1

class	Car;

class	Motor {
	public:
		Motor() {
			this->_engineStatus = STOPPED;
		}

		void	start() {
			if (this->_engineStatus == STARTED) {
				std::cerr << "[WARNING] Motor: engine is already started." << std::endl;
				return ;
			}
			this->_engineStatus = STARTED;
			std::cout << "[MOTOR] Engine is started." << std::endl;
		}

		void	stop() {
			if (this->_engineStatus == STOPPED) {
				std::cerr << "[WARNING] Motor: engine is already stopped." << std::endl;
				return ;
			}
			this->_engineStatus = STOPPED;
			std::cout << "[MOTOR] Engine is stopped." << std::endl;
		}

		int	getEngineStatus() const {
			return this->_engineStatus;
		}

	private:
		int	_engineStatus;
};

# include "Car.hpp"

#endif

#ifndef __WHEELS_HPP__
# define __WHEELS_HPP__

class	Car;

class	Wheels {
	public:
		Wheels() {
			this->_turnAngle = 0.0;
		}

		void	setTurnAngle(float turnAngle) {
			if (turnAngle < -40.0 || turnAngle > 40.0) {
				std::cerr << "[ERROR] Wheels: the angle of the wheels must be between -40 and 40 degrees." << std::endl;
				return ;
			}
			this->_turnAngle = turnAngle;
		}

		const float&	getTurnAngle() const {
			return this->_turnAngle;
		}

	private:
		float	_turnAngle;
};

# include "Car.hpp"

#endif

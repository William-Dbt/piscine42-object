#ifndef __BRAKES_HPP__
# define __BRAKES_HPP__

class Car;

class	Brakes {
	public:
		Brakes() {
			this->_pressionForce = 0.0;
		}

		void	applyPression(float pression) {
			if (pression < 0.0 || pression > 100.0) {
				std::cerr << "[ERROR] Brakes: the applied pression is not valid (must be between 0.0 and 100.0)." << std::endl;
				return ;
			}
			this->_pressionForce = pression;
		}

		const float&	getPression() const {
			return this->_pressionForce;
		}

	private:
		float	_pressionForce;
};

# include "Car.hpp"

#endif

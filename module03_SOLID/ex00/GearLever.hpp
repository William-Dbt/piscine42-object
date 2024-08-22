#ifndef __GEARLEVER_HPP__
# define __GEARLEVER_HPP__

# include <map>

enum e_gears {
	REVERSE = -1,
	NEUTRAL,
	FIRST,
	SECOND,
	THIRD,
	FOURTH,
	FIFTH
};

class	Car;

class	GearLever {
	public:
		GearLever() {
			this->_level = NEUTRAL;
			this->_gearsName[REVERSE] = "Reverse";
			this->_gearsName[NEUTRAL] = "Neutral";
			this->_gearsName[FIRST] = "First";
			this->_gearsName[SECOND] = "Second";
			this->_gearsName[THIRD] = "Third";
			this->_gearsName[FOURTH] = "Fourth";
			this->_gearsName[FIFTH] = "Fifth";
		}

		const int&	getActiveLevelGear() const {
			return this->_level;
		}

		const std::string&	getActiveLevelGearName() {
			return this->_gearsName[this->_level];
		}

		void	shiftGearUp() {
			if (this->_level == FIFTH) {
				std::cerr << "[ERROR] GearLever: can't shift gear up, you're already on the last gear." << std::endl;
				return ;
			}
			this->_level++;
		}

		void	shiftGearDown(int reverse = false) {
			if (this->_level <= NEUTRAL && !reverse) {
				std::cerr << "[ERROR] GearLever: can't shift gear down, you're already at the minimum." << std::endl;
				return ;
			}
			if (reverse && this->_level == REVERSE) {
				std::cerr << "[ERROR] GearLever: can't shift to reverse, you're already on it" << std::endl;
				return ;
			}
			this->_level--;
		}

	private:
		std::map<int, std::string>	_gearsName;
		int							_level;
};

# include "Car.hpp"

#endif

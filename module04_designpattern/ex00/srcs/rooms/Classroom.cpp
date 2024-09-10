#include <iostream>
#include "../../includes/rooms/Classroom.hpp"

bool	Classroom::canEnter(Person* person) {
	(void)person;
	if (this->_occupants.size() < MAX_NB_STUDENTS_PER_CLASS)
		return true;

	return false;
}

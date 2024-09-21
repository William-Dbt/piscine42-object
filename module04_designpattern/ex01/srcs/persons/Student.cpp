#include "../../includes/persons/Student.hpp"

void	Student::graduate(Course* p_course) {
	std::vector<Course*>::iterator	it;

	for (it = this->_subscribedCourse.begin(); it != this->_subscribedCourse.end(); it++) {
		if ((*it) == p_course) {
			this->_subscribedCourse.erase(it);
			return ;
		}
	}
}

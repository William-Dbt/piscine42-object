#include "../../includes/persons/Professor.hpp"

Professor::Professor(const std::string& name): Staff(name) {
	this->_currentCourse = NULL;
}

void	Professor::assignCourse(Course* course) {
	if (!course) {
		this->_currentCourse = NULL;
		return ;
	}
	if (this->_currentCourse && this->_currentCourse != course)
		this->_currentCourse->assign(NULL);

	this->_currentCourse->assign(this);
}

void	Professor::doClass() {

}

void	Professor::closeCourse() {

}

Course*	Professor::getCurrentCourse() const {
	return this->_currentCourse;
}

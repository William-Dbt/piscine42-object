#ifndef __PROFESSOR_HPP__
# define __PROFESSOR_HPP__

# include "../Staff.hpp"
# include "../../Course.hpp"

class	Professor: public Staff {
	public:
		void	assignCourse(Course* p_course) {
			this->_currentCourse = p_course;
			p_course->assign(this);
		}

		void	doClass() {
			std::cout << this->_name << " is doing his class (" << this->_currentCourse->getName() << ") !" << std::endl;
		}

		void	closeCourse() {
			std::cout << "The course " << this->_currentCourse->getName() << " is closed !" << std::endl;
		}

	private:
		Course*	_currentCourse;
};

#endif

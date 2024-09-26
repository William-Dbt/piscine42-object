#ifndef __CLASSROOM_HPP__
# define __CLASSROOM_HPP__

# include <iostream>
# include "../Course.hpp"
# include "../Room.hpp"

class	Classroom: public Room {
	public:
		Classroom() {
			this->_currentCourse = NULL;
		}

		void	assignCourse(Course* course) {
			if (course)
				this->_currentCourse = course;
		}

	private:
		Course*	_currentCourse;
};


#endif

#ifndef __CLASSROOM_HPP__
# define __CLASSROOM_HPP__

# include "../Room.hpp"

class Course;

class	Classroom: public Room {
	public:
		Classroom() {
			this->_currentRoom = NULL;
		}

		void	assignCourse(Course* p_course) {
			this->_currentRoom = p_course;
		}

		virtual bool	canEnter(Person* person);

	private:
		Course*	_currentRoom;
};

# include "../Course.hpp"

#endif

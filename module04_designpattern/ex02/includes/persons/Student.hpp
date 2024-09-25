#ifndef __STUDENT_HPP__
# define __STUDENT_HPP__

# include <vector>
# include "../Person.hpp"
# include "../rooms/Classroom.hpp"

class	Course;

class	Student: public Person {
	public:
		Student(const std::string& name) {
			this->_name = name;
		}

		void	attendClass(Classroom* p_classroom) {
			if (p_classroom->canEnter(this))
				p_classroom->enter(this);
		}

		void	exitClass() {
			this->_currentRoom->exit(this);
		}

		void	graduate(Course* p_course);

	private:
		std::vector<Course*>	_subscribedCourse;
};

# include "../Course.hpp"

#endif

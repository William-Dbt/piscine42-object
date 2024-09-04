#ifndef __COURSE_HPP__
# define __COURSE_HPP__

# include <string>
# include <vector>
# include "persons/staffs/Professor.hpp"
# include "persons/Student.hpp"

class	Course {
	public:
		Course(const std::string& p_name);

		void	assign(Professor* p_professor);
		void	subscribe(Student* p_student);

	private:
		std::string				_name;
		Professor*				_responsable;
		std::vector<Student*>	_students;

		int	_numberOfClassToGraduate;
		int	_maximumNumberOfStudents;
};

#endif

#ifndef __COURSE_HPP__
# define __COURSE_HPP__

# include <string>
# include <vector>
# include "persons/Student.hpp"
# include "persons/Professor.hpp"

class	Course {
	public:
		Course(const std::string& name);

		void	assign(Professor* professor);
		void	subscribe(Student* student);

		const std::string&	getName() const;
		Professor*	getResponsable() const;

	private:
		std::string	_name;

		Professor*				_responsable;
		std::vector<Student*>	_students;

		int	_numberOfClassToGraduate;
		int	_maximumNumberOfStudents;
};

#endif

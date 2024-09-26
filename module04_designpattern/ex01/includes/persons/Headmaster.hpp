#ifndef __HEADMASTER_HPP__
# define __HEADMASTER_HPP__

# include <vector>
# include "Staff.hpp"
# include "../Form.hpp"

class	Headmaster: public Staff {
	public:
		void	receiveForm(Form* form) {
			this->_formToValidate.push_back(form);
		}

	private:
		std::vector<Form*>	_formToValidate;
};

#endif

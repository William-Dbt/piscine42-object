#ifndef __HEADMASTER_HPP__
# define __HEADMASTER_HPP__

# include "../Staff.hpp"
# include "../../Form.hpp"

class	Headmaster: public Staff {
	public:
		void	receiveForm(Form* p_form) {
			this->_formToValidate.push_back(p_form);
		}

	private:
		std::vector<Form*>	_formToValidate;
};

#endif

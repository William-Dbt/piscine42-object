#ifndef __HEADMASTER_HPP__
# define __HEADMASTER_HPP__

# include "../Staff.hpp"
# include "../../Form.hpp"

class	Headmaster: public Staff {
	public:
		Headmaster(const std::string& name) {
			this->_name = name;
		}

		void	receiveForm(Form* p_form) {
			this->_formToValidate.push_back(p_form);
		}

		void	signForm(Form* p_form) {
			if (!p_form->isSigned()) {
				p_form->_isSigned = true;
				this->sign(p_form);
			}
		}

	private:
		std::vector<Form*>	_formToValidate;
};

#endif

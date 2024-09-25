#ifndef __NEEDMORECLASSROOMFORM_HPP__
# define __NEEDMORECLASSROOMFORM_HPP__

# include <iostream>
# include "../Form.hpp"

class	NeedMoreClassRoomForm: public Form {
	public:
		NeedMoreClassRoomForm(FormType p_formType) {
			this->_formType = p_formType;
		}

		virtual void	execute() {
			std::cout << "[NeedMoreClassRoomForm] form executed." << std::endl;
		}
};

#endif

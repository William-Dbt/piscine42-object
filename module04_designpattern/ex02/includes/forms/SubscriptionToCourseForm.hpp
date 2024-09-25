#ifndef __SUBSCRIPTIONTOCOURSEFORM_HPP__
# define __SUBSCRIPTIONTOCOURSEFORM_HPP__

# include <iostream>
# include "../Form.hpp"

class	SubscriptionToCourseForm: public Form {
	public:
		SubscriptionToCourseForm(FormType p_formType) {
			this->_formType = p_formType;
		}

		virtual void	execute() {
			std::cout << "[SubscriptionToCourseForm] form executed." << std::endl;
		}
};

#endif

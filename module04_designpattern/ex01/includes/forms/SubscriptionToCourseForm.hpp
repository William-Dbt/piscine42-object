#ifndef __SUBSCRIPTIONTOCOURSEFORM_HPP__
# define __SUBSCRIPTIONTOCOURSEFORM_HPP__

# include "../Form.hpp"

class	SubscriptionToCourseForm: public Form {
	public:
		SubscriptionToCourseForm(FormType type): Form(type) {}

		void	execute() {}
};

#endif

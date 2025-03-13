# pragma once

#ifndef ROBOTONOMY_REQUEST_FORM_HPP
#define ROBOTONOMY_REQUEST_FORM_HPP

# include <iostream>
# include <ctime>
#include "AForm.hpp"
class RobotomyRequestForm: public AForm {
	private:
		std::string _target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &original);
		const RobotomyRequestForm &operator=(const RobotomyRequestForm &original);
		~RobotomyRequestForm();

		std::string getTarget() const;
		void setTarget(const std::string target);
		void _execute(void) const;
};

#endif
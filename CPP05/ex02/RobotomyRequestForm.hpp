# pragma once

#ifndef ROBOTONOMY_REQUEST_FORM_HPP
#define ROBOTONOMY_REQUEST_FORM_HPP

# include <iostream>

class RobotomyRequestForm {
	private:
		std::string target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &original);
		const RobotomyRequestForm &operator=(const RobotomyRequestForm &original);
		RobotomyRequestForm();

		std::string getTarget();
};

#endif
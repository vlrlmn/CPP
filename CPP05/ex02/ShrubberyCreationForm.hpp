# pragma once

#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

# include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm {
	private:
		std::string _target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &original);
		const ShrubberyCreationForm &operator=(const ShrubberyCreationForm &original);
		ShrubberyCreationForm();

		void setTarget(std::string target);
		std::string getTarget();
		void _execute(void) const;
};

#endif
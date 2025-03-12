# pragma once

#ifndef PRESIDENTIAL_PARDON_FORM_HPP 
#define PRESIDENTIAL_PARDON_FORM_HPP 

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm {
	private:
		std::string _target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &original);
		const PresidentialPardonForm &operator=(const PresidentialPardonForm &original);
		PresidentialPardonForm();

		std::string getTarget();
};

#endif

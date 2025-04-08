#include "RPN.hpp"

int main(int argc, char **argv) 
{
	if (argc !=2) {
		std::cout << "Error: should take a single string_argument" << std::endl;
		return 1;
	}
	RPN rpn;
	rpn.readString(argv[1]);
	try {
		std::cout << rpn.rpnEval() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
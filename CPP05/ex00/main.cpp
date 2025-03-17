#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 10);
        Bureaucrat alice("Alice", 1);
        // Bureaucrat trent("Trent", -1);
        // Bureaucrat mallory("Mallory", 151);

        try {
            std::cout << "----------------BOB----------------" << std::endl;
            bob.decrementGrade();
            bob.decrementGrade();
            std::cout << bob << std::endl;
            bob.incrementGrade();
            std::cout << bob << std::endl;
        } catch (std::exception &e) {
            std::cout << "EXCEPTION (Bob): " << e.what() << std::endl;
        }

        try {
            std::cout << std::endl << "----------------ALICE----------------" << std::endl;
            alice.decrementGrade();
            std::cout << alice << std::endl;
            alice.incrementGrade();
            std::cout << alice << std::endl;
            alice.incrementGrade();
            std::cout << alice << std::endl;
        } catch (std::exception &e) {
            std::cout << "EXCEPTION (Alice): " << e.what() << std::endl;
        }
        std::cout << std::endl << "----------------CLEANUP----------------" << std::endl;
    } catch (std::exception &e) {
        std::cout << "EXCEPTION! " << e.what() << std::endl;
    }

    return 0;
}

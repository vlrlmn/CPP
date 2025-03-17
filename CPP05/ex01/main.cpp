#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    Bureaucrat bob("Bob", 10);
    std::cout << "---------------FORM CREATION---------------" << std::endl;
    std::cout << bob << std::endl;

    try {
        Form form1("form1", 3, 5);
        std::cout << form1 << std::endl;
        Form form2("form2", 11, 15);
        bob.signForm(form2);
    } catch (const std::exception& e) {
        std::cout << "EXCEPTION: " << e.what() << std::endl;
    }

    // Negative tests
    try {
        Form form3("form3", 30, 500);
    } catch (const std::exception& e) {
        std::cout << "EXCEPTION (Invalid Execution Grade): " << e.what() << std::endl;
    }

    try {
        Form form4("form4", 30, -50);
    } catch (const std::exception& e) {
        std::cout << "EXCEPTION (Invalid Signing Grade): " << e.what() << std::endl;
    }

    try {
        Form form5("form5", -30, 5);
    } catch (const std::exception& e) {
        std::cout << "EXCEPTION (Invalid Signing Grade): " << e.what() << std::endl;
    }

    try {
        Form form6("", 5, 5);
    } catch (const std::exception& e) {
        std::cout << "EXCEPTION (Empty Form Name): " << e.what() << std::endl;
    }

    // Form signment tests
    try {
        Bureaucrat alice("Alice", 1);
        Form form1("form1", 3, 5);
        std::cout << std::endl << "---------------ALICE SIGNING FORM (enough grade)---------------" << std::endl;
        std::cout << alice << std::endl;
        std::cout << "---BEFORE SIGNMENT" << std::endl;
        std::cout << form1 << std::endl;
        alice.signForm(form1);
        std::cout << "---AFTER SIGNMENT" << std::endl;
        std::cout << form1 << std::endl;
        alice.signForm(form1);
    } catch (const std::exception& e) {
        std::cout << "EXCEPTION (Alice Signing): " << e.what() << std::endl;
    }

    return 0;
}

#include "Bureaucrat.hpp"
#include "Form.hpp"
int main()
{
    try
    {
        std::cout << "FORM CREATION" << std::endl;
        Bureaucrat bob("Bob", 10);
        std::cout << bob << std::endl;
        Form form1("form1", 3, 5);
        std::cout << form1 << std::endl;

        //Negative tests
        // Form form2("form2", 300, 5);
        // Form form3("form3", 30, 500);
        // Form form4("form4", 30, -50);
        // Form form5("form5", -30, 5);
        // Form form6("", 5, 5);
        
        //Form signment tests
        std::cout << "\nALICE SIGNING FORM (enough grade)" << std::endl;
        Bureaucrat alice("Alice", 1);
        std::cout << alice << std::endl;
        std::cout << "\n---BEFORE SIGNMENT" << std::endl;
        std::cout << form1 << std::endl;
        form1.beSigned(alice);
        std::cout << "\n---AFTER SIGNMENT" << std::endl;
        std::cout << form1 << std::endl;
        form1.beSigned(alice);
        std::cout << "\nBOB SIGNING FORM (not enough grade)" << std::endl;
        form1.beSigned(bob);

    }
    catch (std::exception & e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}
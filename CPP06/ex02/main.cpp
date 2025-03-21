#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate() {

    int r = rand() % 3;

    switch(r) {
        case 0:
            return new A();
            break;
        case 1:
            return new B();
            break;
        case 2:
            return new C();
            break;
        default:
            break;
    }
    return NULL;
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown" << std::endl;
}

void identify(Base& p) {
    if (dynamic_cast<A*>(&p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(&p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(&p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown" << std::endl;
}

int main() {
    srand(time(NULL));
    Base* obj = generate(); 

    std::cout << "Identify by pointer: ";
    identify(obj);

    std::cout << "Identify by reference: ";
    identify(*obj);

    delete obj; 
    return 0;
}

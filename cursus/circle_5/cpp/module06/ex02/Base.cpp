#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
    std::cout << "Default Base destructor called" << std::endl;
}

Base *Base::generate(void)
{
    if (std::time(NULL) % 3 == 0) {
        std::cout << "Generating Class A" << std::endl;
        return dynamic_cast<Base*>(new A());
    }
    else if (std::time(NULL) % 3 == 1) {
        std::cout << "Generating Class B" << std::endl;
        return dynamic_cast<Base*>(new B());
    }
    else {
        std::cout << "Generating Class C" << std::endl;
        return dynamic_cast<Base*>(new C());
    }
}

void Base::identify(Base* p)
{
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "Actual type of this object pointed to by p is A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "Actual type of this object pointed to by p is B" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "Actual type of this object pointed to by p is C" << std::endl;
}

void Base::identify(Base& p)
{
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "Actual type of this object pointed to by p is A" << std::endl;
    }
    catch (std::exception &e) {
    }
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "Actual type of this object pointed to by p is B" << std::endl;
    }
    catch (std::exception &e) {
    }
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "Actual type of this object pointed to by p is C" << std::endl;
    }
    catch (std::exception &e) {
    }
}
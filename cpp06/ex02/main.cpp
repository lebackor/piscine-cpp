#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{

    int i = rand() % 3 + 1;
    if (i == 1)
        return (new A);
    else if (i == 2)
        return (new B);
    else
        return (new C);
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Pointer identify = A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Pointer identify = B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Pointer identify = C" << std::endl;
    else
        std::cerr << "Can't identify at all" << std::endl;
}



void identify(Base& p)
{
    if (dynamic_cast<A*>(&p))
        std::cout << "Reference identify = A" << std::endl;
    else if (dynamic_cast<B*>(&p))
        std::cout << "Reference identify = B" << std::endl;
    else if (dynamic_cast<C*>(&p))
        std::cout << "Reference identify = C" << std::endl;
    else
        std::cerr << "Can't identify at all" << std::endl;
}

int main()
{
    srand(time(NULL));
    Base* a = generate();
    Base* b = generate();
    Base& ref = *b;

    identify(a);
    identify(ref);
    delete (a);
    delete (&ref);
}
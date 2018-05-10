//
// Created by Joanna on 08.05.2018.
//
#include <iostream>
#include <vector>

class Base {
public:
    virtual  std::string foo()  = 0;
};

class Derived : public Base {
public:
    std::string foo() override { return "derived"; }
};

int main() {
    std::vector<std::reference_wrapper<const Base>> bases;
    Derived d1;
    Derived d2;
    bases.emplace_back(d1);
    bases.emplace_back(d2);

    for (const Base &base : bases) {
        std::cout << base.foo() << std::endl;
    }

    return 0;
}

class BaseReferenceWrapper {
public:
    BaseReferenceWrapper(Base &base)
            : base_{&base} {}
    //zdefiniowany operator rzutujący na referencję
    //przez co typu można używać jak referencji
    operator Base&() {
        return *base_;
    }
private:
    Base *base_;
};


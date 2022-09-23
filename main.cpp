#include <iostream>


class Base {

public:

    virtual void hello() { std::cout << 1 << std::endl; }

};


class Derive: public Base {

public:

    void hello() { std::cout << 2 << std::endl; }

};


void call(Base b) {

    b.hello();

}


int main() {

    Derive b;

    call(b);

}

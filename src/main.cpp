
#include "Vector.h"
#include <iostream>

int main()
{
    Vector v1(10, 42); // create a vector of size 10 with value 42
    Vector v2 = v1;    // copy constructor
    Vector v3(std::move(v1)); // move constructor

    return 0;
}
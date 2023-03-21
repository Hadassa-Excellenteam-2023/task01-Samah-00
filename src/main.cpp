#include <iostream>
#include "Vector.h"

int main() {
    // Create a vector with 5 elements, all initialized to 0
    Vector vec1(5);

    // Print the contents of the vector
    std::cout << "vec1: ";
    for (size_t i = 0; i < vec1.size(); ++i) {
        std::cout << vec1[i] << " ";
    }
    std::cout << std::endl;

    // Copy the vector to a new vector
    Vector vec2 = vec1;

    // Change the second element of the new vector to 1
    vec2[1] = 1;

    // Print the contents of both vectors
    std::cout << "vec1: ";
    for (size_t i = 0; i < vec1.size(); ++i) {
        std::cout << vec1[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "vec2: ";
    for (size_t i = 0; i < vec2.size(); ++i) {
        std::cout << vec2[i] << " ";
    }
    std::cout << std::endl;

    // Append an element to the end of the first vector
    vec1.push_back(2);

    // Print the contents of the first vector
    std::cout << "vec1: ";
    for (size_t i = 0; i < vec1.size(); ++i) {
        std::cout << vec1[i] << " ";
    }
    std::cout << std::endl;

    // Remove the last element from the first vector
    vec1.pop_back();

    // Print the contents of the first vector
    std::cout << "vec1: ";
    for (size_t i = 0; i < vec1.size(); ++i) {
        std::cout << vec1[i] << " ";
    }
    std::cout << std::endl;

    // Resize the second vector to have 10 elements, all initialized to 2
    vec2.resize(10, 2);

    // Print the contents of the second vector
    std::cout << "vec2: ";
    for (size_t i = 0; i < vec2.size(); ++i) {
        std::cout << vec2[i] << " ";
    }
    std::cout << std::endl;

    // swap vec1 and vec2
    vec1.swap(vec2);

    // Print the contents of both vectors
    std::cout << "vec1: ";
    for (size_t i = 0; i < vec1.size(); ++i) {
        std::cout << vec1[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "vec2: ";
    for (size_t i = 0; i < vec2.size(); ++i) {
        std::cout << vec2[i] << " ";
    }
    std::cout << std::endl;

    // insert the value 4 to the 5th element of vec1
    vec1.insert(4, 4);

    // erase the 5th element of vec2
    vec2.erase(4);

    // Print the contents of both vectors
    std::cout << "vec1: ";
    for (size_t i = 0; i < vec1.size(); ++i) {
        std::cout << vec1[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "vec2: ";
    for (size_t i = 0; i < vec2.size(); ++i) {
        std::cout << vec2[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

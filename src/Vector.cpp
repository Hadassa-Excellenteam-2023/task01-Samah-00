#include "Vector.h"


// Constructor
Vector::Vector(size_t size, int value)
    : m_size(size)
    , m_capacity(get_capacity(size))
    , m_data(new int[m_capacity])
{
    // Initialize all elements to the given value
    for (size_t i = 0; i < m_size; ++i) {
        m_data[i] = value;
    }
}

// Copy constructor
Vector::Vector(const Vector& other)
    : m_size(other.m_size)
    , m_capacity(other.m_capacity)
    , m_data(new int[m_capacity])
{
    // Copy all elements from the other vector
    for (size_t i = 0; i < m_size; ++i) {
        m_data[i] = other.m_data[i];
    }
}

// Move constructor
Vector::Vector(Vector&& other) noexcept
    : m_size(other.m_size)
    , m_capacity(other.m_capacity)
    , m_data(other.m_data)
{
    // Take ownership of the other vector's data
    other.m_size = 0;
    other.m_capacity = 0;
    other.m_data = nullptr;
}

// Copy assignment operator
Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        // Copy and swap idiom for exception safety
        Vector temp(other);
        std::swap(m_size, temp.m_size);
        std::swap(m_capacity, temp.m_capacity);
        std::swap(m_data, temp.m_data);
    }
    return *this;
}

// Move assignment operator
Vector& Vector::operator=(Vector&& other) noexcept {
    if (this != &other) {
        // Free the old data and take ownership of the new data
        delete[] m_data;
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_data = other.m_data;
        other.m_size = 0;
        other.m_capacity = 0;
        other.m_data = nullptr;
    }
    return *this;
}

// append an element to the end of the vector
void Vector::push_back(int value) {
    if (m_size == m_capacity) {
        if (m_capacity < 128) {
            reserve(m_capacity * 2);
        }
        else {
            reserve(m_capacity * 3 / 2);
        }
    }
    m_data[m_size++] = value;
}

// remove the last element from the vector
void Vector::pop_back() {
    if (!empty()) {
        // Remove the last element from the vector and update the size
        --m_size;
    }
}

void Vector::reserve(size_t capacity) {
    if (capacity > m_capacity) {
        // If the new capacity is greater than the current capacity, allocate more memory
        size_t new_capacity = get_capacity(capacity);
        int* new_data = new int[new_capacity];
        // Copy all existing elements to the new memory location
        for (size_t i = 0; i < m_size; ++i) {
            new_data[i] = m_data[i];
        }
        // Free the old memory and update the member variables
        delete[] m_data;
        m_data = new_data;
        m_capacity = new_capacity;
    }
}

void Vector::resize(size_t size, int value) {
    if (size > m_capacity) {
        // If the new size is greater than the current capacity, reserve more memory
        reserve(size);
    }
    // Initialize any new elements to the given value
    for (size_t i = m_size; i < size; ++i) {
        m_data[i] = value;
    }
    // Set the new size of the vector
    m_size = size;
}

// brackets operator for reading/modifying elements
int& Vector::operator[](size_t index) {
    if (index >= m_size) {
        throw std::out_of_range("index out of range");
    }
    return m_data[index];
}
const int& Vector::operator[](size_t index) const {
    if (index >= m_size) {
        throw std::out_of_range("index out of range");
    }
    return m_data[index];
}

// get the number of elements in the vector
size_t Vector::size() const {
    // Return the number of elements in the vector
    return m_size;
}

// get the current capacity of the vector
size_t Vector::capacity() const {
    // Return the current capacity of the vector
    return m_capacity;
}

bool Vector::empty() const {
    // Check if the vector is empty
    return m_size == 0;
}

void Vector::clear() {
    //**check?????
    //delete[] m_data;
    m_size = 0;
}

// get a pointer to the underlying data array
int* Vector::data() {
    return m_data;
}

const int* Vector::data() const {
    return m_data;
}

// swap the contents of two vectors
void Vector::swap(Vector& other) {
    std::swap(m_size, other.m_size);
    std::swap(m_capacity, other.m_capacity);
    std::swap(m_data, other.m_data);
}

// Insert a value at the specified index
void Vector::insert(size_t index, int value) {
    // If index is out of range, throw an exception
    if (index > m_size) {
        throw std::out_of_range("Index out of range");
    }

    // If there isn't enough capacity, double the capacity
    if (m_size == m_capacity) {
        reserve(m_capacity * 2);
    }

    // Move elements from index onwards one position to the right
    for (size_t i = m_size; i > index; --i) {
        m_data[i] = m_data[i - 1];
    }

    // Insert the new value at the specified index
    m_data[index] = value;

    // Increment the size
    ++m_size;
}

// Remove the value at the specified index
void Vector::erase(size_t index) {
    // If index is out of range, throw an exception
    if (index >= m_size) {
        throw std::out_of_range("Index out of range");
    }

    // Move elements from index onwards one position to the left
    for (size_t i = index; i < m_size - 1; ++i) {
        m_data[i] = m_data[i + 1];
    }

    // Decrement the size
    --m_size;
}

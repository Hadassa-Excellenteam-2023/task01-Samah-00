#include "Vector.h"

#include <iostream>

// Constructor
 Vector::Vector(size_t size, int value)
    : m_size(size), m_capacity(size), m_data(new int[size])
{
    for (size_t i = 0; i < m_size; i++) {
        m_data[i] = value;
    }
}

// Copy constructor
Vector::Vector(const Vector& other)
    : m_size(other.m_size), m_capacity(other.m_capacity), m_data(new int[other.m_capacity])
{
    for (size_t i = 0; i < m_size; i++) {
        m_data[i] = other.m_data[i];
    }
}

// Move constructor
Vector::Vector(Vector&& other) noexcept
    : m_size(other.m_size), m_capacity(other.m_capacity), m_data(other.m_data)
{
    other.m_size = 0;
    other.m_capacity = 0;
    other.m_data = nullptr;
}

// Copy assignment operator
Vector& Vector::operator=(const Vector& other)
{
    if (this != &other) {
        Vector tmp(other);
        std::swap(m_size, tmp.m_size);
        std::swap(m_capacity, tmp.m_capacity);
        std::swap(m_data, tmp.m_data);
    }
    return *this;
}

// Move assignment operator
Vector& Vector::operator=(Vector&& other) noexcept
{
    if (this != &other) {
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

// Square brackets operator (non-const versions)
int& Vector::operator[](size_t index)
{
    return m_data[index];
}

// Square brackets operator (const versions)
const int& Vector::operator[](size_t index) const
{
    return m_data[index];
}

// Pop back function
void Vector::pop_back()
{
    if (m_size > 0) {
        m_size--;
    }
}

// Push back function
void Vector::push_back(int value)
{
    if (m_size >= m_capacity) {
        reserve(std::max(static_cast<size_t>(m_capacity * growth_factor_), m_size + 1));
    }
    m_data[m_size] = value;
    m_size++;
}

// Swap function
void Vector::swap(Vector& other) noexcept
{
    std::swap(m_size, other.m_size);
    std::swap(m_capacity, other.m_capacity);
    std::swap(m_data, other.m_data);
}



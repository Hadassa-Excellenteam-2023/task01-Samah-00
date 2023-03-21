#include <utility> // for std::swap
#include <stdexcept> // for std::out_of_range


class Vector {
public:
    // Constructor
    explicit Vector(size_t size = 0, int value = 0);

    // Copy constructor
    Vector(const Vector& other);

    // Move constructor
    Vector(Vector&& other) noexcept;

    // Destructor
    ~Vector() {
        // Free the dynamically allocated memory
        delete[] m_data;
    }

    // Copy assignment operator
    Vector& operator=(const Vector& other);

    // Move assignment operator
    Vector& operator=(Vector&& other) noexcept;

    // Member functions
    size_t size() const;

    size_t capacity() const;

    bool empty() const;

    void clear();

    void resize(size_t size, int value = 0);

    void push_back(int value);

    void pop_back();

    int& operator[](size_t index);

    const int& operator[](size_t index) const;

    int* data();

    const int* data() const;

    void swap(Vector& other);

    void insert(size_t index, int value);

    void erase(size_t index);

private:
    // Helper function to calculate the new capacity based on the current size
    static size_t get_capacity(size_t size) {
        size_t capacity = 1;
        while (capacity < size) {
            if (capacity < 128) {
                capacity *= 2;
            }
            else {
                capacity = capacity * 3 / 2;
            }
        }
        return capacity;
    }

    void reserve(size_t capacity);

    size_t m_size; // Current number of elements in the vector
    size_t m_capacity; // Current capacity of the vector
    int* m_data; // Dynamically allocated array to store the elements
};
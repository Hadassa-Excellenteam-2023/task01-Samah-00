


class Vector {
public:
    // Constructor
    explicit Vector(size_t size = 0, int value = 0);

    // Copy constructor
    Vector(const Vector& other);

    // Move constructor
    Vector(Vector&& other) noexcept;

    //??
    // Copy assignment operator
    Vector& operator=(const Vector& other);
    //??
    // Move assignment operator
    Vector& operator=(Vector&& other) noexcept;

    // Square brackets operator (const and non-const versions)
    int& operator[](size_t index);
    const int& operator[](size_t index) const;

    // Pop back function
    void pop_back();

    // Push back function
    void push_back(int value);

    // Swap function
    void swap(Vector& other) noexcept;

    // Destructor
    ~Vector()
    {
        delete[] m_data;
    }

private:
    size_t m_size;
    size_t m_capacity;
    int* m_data;
};
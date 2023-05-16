#pragma once

template <typename T>
class UniquePtr
{
private:
    static_assert(std::is_pointer_v<T>, "T must be a pointer type");
    T *m_data;

public:
    // Constructors
    UniquePtr() = delete;
    UniquePtr(T *data) : m_data(data) {}

    // Copy constructor
    UniquePtr(const UniquePtr<T> &other) = delete;

    // Move constructor
    UniquePtr(UniquePtr<T> &&other) noexcept
    {
        m_data = other.m_data;
        other.m_data = nullptr;
    }

    // Copy assignment
    UniquePtr<T> &operator=(const UniquePtr<T> &other) = delete;

    // Move assignment
    UniquePtr<T> &operator=(UniquePtr<T> &&other) noexcept
    {
        if (this != &other)
        {
            delete m_data;
            m_data = other.m_data;
            other.m_data = nullptr;
        }
        return *this;
    }

    // Destructor
    ~UniquePtr()
    {
        delete m_data;
    }

    // Operators
    T &operator*() const
    {
        return *m_data;
    }

    T *operator->() const
    {
        return m_data;
    }

    // Methods
    T *get() const
    {
        return m_data;
    }

    bool operator==(const UniquePtr<T> &other) const
    {
        return m_data == other.m_data;
    }

    bool operator!=(const UniquePtr<T> &other) const
    {
        return m_data != other.m_data;
    }

    void reset(T *data = nullptr)
    {
        delete m_data;
        m_data = data;
    }

    void swap(UniquePtr<T> &other)
    {
        T *temp = m_data;
        m_data = other.m_data;
        other.m_data = temp;
    }
};
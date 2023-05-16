#pragma once

template <typename T>
class InitializerList
{
private:
    T *m_data;
    size_t m_size;

public:
    // Constructors with variadic template
    template <typename... Args>
    InitializerList(Args... args) : m_size(sizeof...(args))
    {
        m_data = new T[m_size]{args...};
    }

    // Default constructor
    InitializerList() = delete;

    // Copy constructor
    InitializerList(const InitializerList<T> &other) : m_size(other.m_size)
    {
        m_data = new T[m_size];
        for (size_t i = 0; i < m_size; i++)
            m_data[i] = other.m_data[i];
    }

    // Move constructor
    InitializerList(InitializerList<T> &&other) noexcept : m_size(other.m_size)
    {
        m_data = other.m_data;
        other.m_data = nullptr;
    }

    // Destructor
    ~InitializerList() noexcept
    {
        delete[] m_data;
    }

    // Copy assignment
    InitializerList<T> &operator=(const InitializerList<T> &other)
    {
        if (this != &other)
        {
            delete[] m_data;
            m_size = other.m_size;
            m_data = new T[m_size];
            for (size_t i = 0; i < m_size; i++)
                m_data[i] = other.m_data[i];
        }
        return *this;
    }

    // Move assignment
    InitializerList<T> &operator=(InitializerList<T> &&other) noexcept
    {
        if (this != &other)
        {
            delete[] m_data;
            m_size = other.m_size;
            m_data = other.m_data;
            other.m_data = nullptr;
        }
        return *this;
    }

    // Getters
    const T *data() const { return m_data; }
    size_t size() const { return m_size; }

    // iterator
    const T *begin() const { return m_data; }
    const T *end() const { return m_data + m_size; }
};
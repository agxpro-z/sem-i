#pragma once

/*
 * Custom array with limited functionality
 */
template<typename T, int size>
class array {
    T m_data[size]{};

  public:
    T& operator[](int n) {
        return m_data[n];
    }

    T* begin() {
        return &m_data[0];
    }

    T* end() {
        return &m_data[size];
    }
};
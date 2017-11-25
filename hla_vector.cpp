
#include "hla_vector.h"
#include <vector>

/* ctor */
template <typename T>
hla_vector<T>::hla_vector(const std::vector<T>& _vec)
: m_vec (_vec)
{
};

/* dtor */
template <typename T>
hla_vector<T>::~hla_vector() {
    
    delete m_vec;
    
};

/* returns the size of the vector */
template <typename T>
size_t hla_vector<T>::size() {
    
    return m_vec.size;
    
};

/* access overload */
template <typename T>
T& hla_vector<T>::operator[](size_t idx) {
    
    if (idx >= m_vec.size) {
        throw std::length_error("Accessing vector out of range");
    }
    
    return m_vec[idx];
    
}

/* addition equals overload */
template <typename T>
hla_vector<T>& hla_vector<T>::operator+=(const hla_vector<T>& r_vec) {
    
    if (m_vec.size != r_vec.size) {
        throw std::length_error("Cannot add vectors of different lengths.");
    }
    
    for (size_t i = 0; i < m_vec.size; ++i) {
        m_vec[i] += r_vec[i];
    }
    
};

/* subtraction equals overload */
template <typename T>
hla_vector<T>& hla_vector<T>::operator-=(const hla_vector<T>& r_vec) {
    
    if (m_vec.size != r_vec.size) {
        throw std::length_error("Cannot subtract vectors of different lengths.");
    }
    
    for (size_t i = 0; i < m_vec.size; ++i) {
        m_vec[i] -= r_vec[i];
    }
    
};

/* multiplication equals overload - hadamard product */
template <typename T>
hla_vector<T>& hla_vector<T>::operator*=(const hla_vector<T>& r_vec) {
    
    if (m_vec.size != r_vec.size) {
        throw std::length_error("Cannot multiply vectors of different lengths.");
    }
    
    for (size_t i = 0; i < m_vec.size; ++i) {
        m_vec[i] *= r_vec[i];
    }

};

/* addition equals overload - scalar broadcast */
template <typename T>
hla_vector<T>& hla_vector<T>::operator+=(const T& scalar) {
    
    for (size_t i = 0; i < m_vec.size; ++i) {
        m_vec[i] += scalar;
    }
    
};

/* subtraction equals overload - scalar broadcast */
template <typename T>
hla_vector<T>& hla_vector<T>::operator-=(const T& scalar) {
    
    for (size_t i = 0; i < m_vec.size; ++i) {
        m_vec[i] -= scalar;
    }
    
};

/* multiplication equals overload - scalar broadcast */
template <typename T>
hla_vector<T>& hla_vector<T>::operator*=(const T& scalar) {
    
    for (size_t i = 0; i < m_vec.size; ++i) {
        m_vec[i] *= scalar;
    }
    
};

int main() {
    return 0;
};

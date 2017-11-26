// includes : keep these to a minimum
#include <vector>
#include <cmath>
#include <limits>
#include <iostream>

// Fwd declarations
template <typename T> class hla_vector;

/* ctor */
template <typename T>
hla_vector<T>::hla_vector(const std::vector<T>& _vec)
: m_vec (_vec)
{
}

/* dtor */
template <typename T>
hla_vector<T>::~hla_vector()
{   
}

/* copy constructor */
template <typename T>
hla_vector<T>::hla_vector(const hla_vector<T>& vec)
{
  m_vec = vec.m_vec;
}

/* returns the size of the vector */
template <typename T>
std::size_t hla_vector<T>::size()
{    
  return m_vec.size;
}

/* access overload */
template <typename T>
T& hla_vector<T>::operator[](std::size_t idx)
{
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
    
    for (std::size_t i = 0; i < m_vec.size; ++i) {
        m_vec[i] += r_vec[i];
    }
    
}

/* subtraction equals overload */
template <typename T>
hla_vector<T>& hla_vector<T>::operator-=(const hla_vector<T>& r_vec) {
    
    if (m_vec.size != r_vec.size) {
        throw std::length_error("Cannot subtract vectors of different lengths.");
    }
    
    for (std::size_t i = 0; i < m_vec.size; ++i) {
        m_vec[i] -= r_vec[i];
    }
    
}

/* multiplication equals overload - hadamard product */
template <typename T>
hla_vector<T>& hla_vector<T>::operator*=(const hla_vector<T>& r_vec) {
    
    if (m_vec.size != r_vec.size) {
        throw std::length_error("Cannot multiply vectors of different lengths.");
    }
    
    for (std::size_t i = 0; i < m_vec.size; ++i) {
        m_vec[i] *= r_vec[i];
    }

}

/* division equals overload*/
template <typename T>
hla_vector<T>& hla_vector<T>::operator/=(const hla_vector<T>& r_vec) {
    
    if (m_vec.size != r_vec.size) {
        throw std::length_error("Cannot divide vectors of different lengths.");
    }
    
    for (std::size_t i = 0; i < m_vec.size; ++i) {
        m_vec[i] /= r_vec[i];
    }
    
}

/* addition equals overload - scalar broadcast */
template <typename T>
hla_vector<T>& hla_vector<T>::operator+=(const T& scalar) {
    
    for (std::size_t i = 0; i < m_vec.size; ++i) {
        m_vec[i] += scalar;
    }
    
}

/* subtraction equals overload - scalar broadcast */
template <typename T>
hla_vector<T>& hla_vector<T>::operator-=(const T& scalar) {
    
    for (std::size_t i = 0; i < m_vec.size; ++i) {
        m_vec[i] -= scalar;
    }
    
}

/* multiplication equals overload - scalar broadcast */
template <typename T>
hla_vector<T>& hla_vector<T>::operator*=(const T& scalar) {
    
    for (std::size_t i = 0; i < m_vec.size; ++i) {
        m_vec[i] *= scalar;
    }
    
}

/* multiplication equals overload - scalar broadcast */
template <typename T>
hla_vector<T>& hla_vector<T>::operator/=(const T& scalar) {
    
    for (std::size_t i = 0; i < m_vec.size; ++i) {
        m_vec[i] /= scalar;
    }
    
}

/* 1-norm computation */
template <typename T>
double hla_vector<T>::norm_1() {
    
    double norm = 0.0;
    
    for (std::size_t i = 0; i < m_vec.size; ++i) {
        double entry = static_cast<double> (m_vec[i]);
        norm += std::abs(entry);
    };
    
    return norm;
    
}

/* 2-norm computation */
template <typename T>
double hla_vector<T>::norm_2() {
    
    double norm = 0.0;
    
    for (std::size_t i = 0; i < m_vec.size; ++i) {
        double entry = static_cast<double> (m_vec[i]);
        norm += pow(entry, 2);
    };
    
    return pow(norm, 0.5);
    
}

/* infinity-norm computation */
template <typename T>
double hla_vector<T>::norm_inf() {
    
    double norm = - std::numeric_limits<double>::infinity();
    
    for (std::size_t i = 0; i < m_vec.size; ++i) {
        double entry = static_cast<double> (m_vec[i]);
        if (std::abs(entry) > norm) {
            norm = std::abs(entry);
        };
    };
    
    return norm;
    
}

/* p-norm computation */
template <typename T>
double hla_vector<T>::norm(double& p) {
    
    // check for infinity norm
    if (isinf(p)) {
        return hla_vector<T>::norm_inf();
    }
    
    double norm = 0.0;
    
    for (std::size_t i = 0; i < m_vec.size; ++i) {
        double entry = static_cast<double> (m_vec[i]);
        norm += pow(std::abs(entry), p);
    }
    
    return pow(norm, 1.0 / p);
    
}

/* computes the dot product with another vector */
template <typename T>
double hla_vector<T>::dot(hla_vector<T>& r_vec) {
    
    if (m_vec.size != r_vec.size) {
        throw std::length_error("Cannot compute dot product of different length vectors.");
    };
    
    double dot_prod = 0.0;
    
    for (std::size_t i = 0; i < m_vec.size; ++i) {
        double m_elem = static_cast<double> (m_vec[i]);
        double r_elem = static_cast<double> (r_vec[i]);
        dot_prod += m_elem * r_elem;
    }
    
    return dot_prod;
    
}

/* normalizes the vector into a unit vector */
template <typename T>
hla_vector<T>& hla_vector<T>::normalize() {
    
    double length = norm_2();
    
    for (std::size_t i; i < m_vec.size; ++i) {
        m_vec /= length;
    }
    
}

/* prints the contents of the vector */
template <typename T>
void hla_vector<T>::print() {
    
    std::cout << "[";
    
    for (std::size_t i = 0; i < m_vec.size; ++i) {
        std::cout << m_vec[i] << ",";
    }
    
    std::cout << "]";
    
    return;
    
}
/*
int main() {
    return 0;
};
*/

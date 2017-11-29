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
std::size_t hla_vector<T>::size() const
{    
  return m_vec.size();
}

/* access overload - const */
template <typename T>
const T& hla_vector<T>::operator[](std::size_t idx) const
{
  if (idx >= m_vec.size()) {
    throw std::length_error("Accessing vector out of range");
  }

  return m_vec[idx];
}

/* access overload */
template <typename T>
T& hla_vector<T>::operator[](std::size_t idx)
{
    if (idx >= m_vec.size()) {
        throw std::length_error("Accessing vector out of range");
    }
    
    return m_vec[idx];
}

/* addition equals overload */
template <typename T>
hla_vector<T>& hla_vector<T>::operator+=(const hla_vector<T>& r_vec) {
    
    if (m_vec.size() != r_vec.size()) {
        throw std::length_error("Cannot add vectors of different lengths.");
    }
    
    for (std::size_t i = 0; i < m_vec.size(); ++i) {
        m_vec[i] += r_vec[i];
    }
    
    return *this;
    
}

/* subtraction equals overload */
template <typename T>
hla_vector<T>& hla_vector<T>::operator-=(const hla_vector<T>& r_vec) {
    
    if (m_vec.size() != r_vec.size()) {
        throw std::length_error("Cannot subtract vectors of different lengths.");
    }
    
    for (std::size_t i = 0; i < m_vec.size(); ++i) {
        m_vec[i] -= r_vec[i];
    }
    
    return *this;
    
}

/* multiplication equals overload - hadamard product */
template <typename T>
hla_vector<T>& hla_vector<T>::operator*=(const hla_vector<T>& r_vec) {
    
    if (m_vec.size() != r_vec.size()) {
        throw std::length_error("Cannot multiply vectors of different lengths.");
    }
    
    for (std::size_t i = 0; i < m_vec.size(); ++i) {
        m_vec[i] *= r_vec[i];
    }
    
    return *this;

}

/* division equals overload*/
template <typename T>
hla_vector<T>& hla_vector<T>::operator/=(const hla_vector<T>& r_vec) {
    
    if (m_vec.size() != r_vec.size()) {
        throw std::length_error("Cannot divide vectors of different lengths.");
    }
    
    for (std::size_t i = 0; i < m_vec.size(); ++i) {
        m_vec[i] /= r_vec[i];
    }
    
    return *this;
    
}

/* addition equals overload - scalar broadcast */
template <typename T>
hla_vector<T>& hla_vector<T>::operator+=(const T& scalar) {
    
    for (std::size_t i = 0; i < m_vec.size(); ++i) {
        m_vec[i] += scalar;
    }
    
    return *this;
    
}

/* subtraction equals overload - scalar broadcast */
template <typename T>
hla_vector<T>& hla_vector<T>::operator-=(const T& scalar) {
    
    for (std::size_t i = 0; i < m_vec.size(); ++i) {
        m_vec[i] -= scalar;
    }
    
    return *this;
    
}

/* multiplication equals overload - scalar broadcast */
template <typename T>
hla_vector<T>& hla_vector<T>::operator*=(const T& scalar) {
    
    for (std::size_t i = 0; i < m_vec.size(); ++i) {
        m_vec[i] *= scalar;
    }
    
    return *this;
    
}

/* multiplication equals overload - scalar broadcast */
template <typename T>
hla_vector<T>& hla_vector<T>::operator/=(const T& scalar) {
    
    for (std::size_t i = 0; i < m_vec.size(); ++i) {
        m_vec[i] /= scalar;
    }
    
    return *this;
    
}

/* 1-norm computation */
template <typename T>
double hla_vector<T>::norm_1() const {
    
    double norm = 0.0;
    
    for (std::size_t i = 0; i < m_vec.size(); ++i) {
        double entry = static_cast<double> (m_vec[i]);
        norm += std::abs(entry);
    };
    
    return norm;
    
}

/* 2-norm computation */
template <typename T>
double hla_vector<T>::norm_2() const {
    
    double norm = 0.0;
    
    for (std::size_t i = 0; i < m_vec.size(); ++i) {
        double entry = static_cast<double> (m_vec[i]);
        norm += pow(entry, 2);
    };
    
    return pow(norm, 0.5);
    
}

/* infinity-norm computation */
template <typename T>
double hla_vector<T>::norm_inf() const {
    
    double norm = - std::numeric_limits<double>::infinity();
    
    for (std::size_t i = 0; i < m_vec.size(); ++i) {
        double entry = static_cast<double> (m_vec[i]);
        if (std::abs(entry) > norm) {
            norm = std::abs(entry);
        };
    };
    
    return norm;
    
}

/* p-norm computation */
template <typename T>
double hla_vector<T>::norm(double& p) const {
    
    // check for infinity norm
    if (isinf(p)) {
        return hla_vector<T>::norm_inf();
    }
    
    // check p >= 1
    if (p < 1) {
        throw std::invalid_argument("p must be >= 1.");
    }

    double norm = 0.0;
    
    for (std::size_t i = 0; i < m_vec.size(); ++i) {
        double entry = static_cast<double> (m_vec[i]);
        norm += pow(std::abs(entry), p);
    }
    
    return pow(norm, 1.0 / p);
    
}

/* computes the dot product with another vector */
template <typename T>
double hla_vector<T>::dot(hla_vector<T>& r_vec) {
    
    if (m_vec.size() != r_vec.size()) {
        throw std::length_error("Cannot compute dot product of different length vectors.");
    };
    
    double dot_prod = 0.0;
    
    for (std::size_t i = 0; i < m_vec.size(); ++i) {
        double m_elem = static_cast<double> (m_vec[i]);
        double r_elem = static_cast<double> (r_vec[i]);
        dot_prod += m_elem * r_elem;
    }
    
    return dot_prod;
    
}
 
/* prints the contents of the vector */
template <typename T>
void hla_vector<T>::print() {
    
    std::cout << "[";
    
    for (std::size_t i = 0; i < m_vec.size(); ++i) {
        std::cout << m_vec[i] << " ,";
    }
    
    std::cout << "]";
    
    return;
}
    
/******************
 * UTIL FUNCTIONS *
 ******************/

/* addition overload */
template <typename T>
hla_vector<T> operator+ (const hla_vector<T>& l_vec, const hla_vector<T>& r_vec) {
    
    if (l_vec.size() != r_vec.size()) {
        throw std::length_error("Cannot add vectors of different lengths.");
    }
    
    // initialize a new vector to contain operation
    std::vector<T> std_vec(l_vec.size());
    hla_vector<T> new_vec(std_vec);
    
    for (std::size_t i = 0; i < l_vec.size(); ++i) {
        new_vec[i] = l_vec[i] + r_vec[i];
    }
    
    return new_vec;
    
}

/* subtraction overload */
template <typename T>
hla_vector<T> operator- (const hla_vector<T>& l_vec, const hla_vector<T>& r_vec) {
    
    if (l_vec.size() != r_vec.size()) {
        throw std::length_error("Cannot subtract vectors of different lengths.");
    }
    
    // initialize a new vector to contain operation
    std::vector<T> std_vec(l_vec.size());
    hla_vector<T> new_vec(std_vec);
    
    for (std::size_t i = 0; i < l_vec.size(); ++i) {
        new_vec[i] = l_vec[i] - r_vec[i];
    }
    
    return new_vec;
    
}

/* multiplication overload - hadamard product */
template <typename T>
hla_vector<T> operator* (const hla_vector<T>& l_vec, const hla_vector<T>& r_vec) {
    
    if (l_vec.size() != r_vec.size()) {
        throw std::length_error("Cannot multiply vectors of different lengths.");
    }
    
    // initialize a new vector to contain operation
    std::vector<T> std_vec(l_vec.size());
    hla_vector<T> new_vec(std_vec);
    
    for (std::size_t i = 0; i < l_vec.size(); ++i) {
        new_vec[i] = l_vec[i] * r_vec[i];
    }
    
    return new_vec;
    
}

/* division overload - elementwise division */
template <typename T>
hla_vector<T> operator/ (const hla_vector<T>& l_vec, const hla_vector<T>& r_vec) {
    
    if (l_vec.size() != r_vec.size()) {
        throw std::length_error("Cannot divide vectors of different lengths.");
    }
    
    // initialize a new vector to contain operation
    std::vector<T> std_vec(l_vec.size());
    hla_vector<T> new_vec(std_vec);
    
    for (std::size_t i = 0; i < l_vec.size(); ++i) {
        new_vec[i] = l_vec[i] / r_vec[i];
    }
    
    return new_vec;
    
}

/* addition overload - vec + scalar */
template <typename T>
hla_vector<T> operator+ (const hla_vector<T>& l_vec, const T& r_scalar) {
    
    // initialize a new vector to contain operation
    std::vector<T> std_vec(l_vec.size());
    hla_vector<T> new_vec(std_vec);
    
    for (std::size_t i = 0; i < l_vec.size(); ++i) {
        new_vec[i] = l_vec[i] + r_scalar;
    }
    
    return new_vec;
    
}

/* addition overload - scalar + vec */
template <typename T>
hla_vector<T> operator+ (const T& l_scalar, const hla_vector<T>& r_vec) {
    
    hla_vector<T> new_vec = r_vec + l_scalar;
    
    return new_vec;
    
}

/* subtraction overload - vec - scalar */
template <typename T>
hla_vector<T> operator- (const hla_vector<T>& l_vec, const T& r_scalar) {
    
    // initialize a new vector to contain operation
    std::vector<T> std_vec(l_vec.size());
    hla_vector<T> new_vec(std_vec);
    
    for (std::size_t i = 0; i < l_vec.size(); ++i) {
        new_vec[i] = l_vec[i] - r_scalar;
    }
    
    return new_vec;
    
}

/* subtraction overload - scalar - vec */
template <typename T>
hla_vector<T> operator- (const T& l_scalar, const hla_vector<T>& r_vec) {
    
    // initialize a new vector to contain operation
    std::vector<T> std_vec(r_vec.size());
    hla_vector<T> new_vec(std_vec);
    
    for (std::size_t i = 0; i < r_vec.size(); ++i) {
        new_vec[i] = l_scalar - r_vec[i];
    }
    
    return new_vec;
    
}

/* normalizes the vector into a unit vector */
 template <typename T>
 hla_vector<double> normalize(const hla_vector<T>& vec) {
     
     // construct a new hla_vector of same size
     std::vector<double> std_vec(vec.size());
     hla_vector<double> norm_vec(std_vec);
     
     double length = vec.norm_2();
     
     for (std::size_t i = 0; i < vec.size(); ++i) {
         double entry = static_cast<double> (vec[i]);
         norm_vec[i] = entry / length;
     }
     
     return norm_vec;
     
 }

/*
int main() {
    return 0;
};
*/


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

template <typename T>
hla_vector<T>& hla_vector<T>::operator+=(const hla_vector<T>& r_vec) {
    
    if (m_vec.size != r_vec.size) {
        throw std::length_error("Cannot add vectors of different lengths.");
    }
    
    for (unsigned int i = 0; i < m_vec.size; ++i) {
        m_vec[i] += r_vec[i];
    }
    
};

int main() {
    return 0;
};

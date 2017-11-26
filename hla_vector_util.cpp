
#include <vector>
#include "hla_vector.hpp"

/* addition overload */
template <typename T>
hla_vector<T> operator+ (hla_vector<T>& l_vec, hla_vector<T>& r_vec) {
    
    if (l_vec.size != r_vec.size) {
        throw std::length_error("Cannot add vectors of different lengths.");
    };
    
    // initialize a new vector to contain addition
    std::vector<T> new_vec(l_vec.size);
    
    for (size_t i; i < l_vec.size; ++i) {
        new_vec[i] = l_vec[i] + r_vec[i];
    };
    
    return hla_vector<T>(new_vec);
    
};

/* subtraction overload */
template <typename T>
hla_vector<T> operator- (hla_vector<T>& l_vec, hla_vector<T>& r_vec) {
    
    if (l_vec.size != r_vec.size) {
        throw std::length_error("Cannot subtract vectors of different lengths.");
    };
    
    // initialize a new vector to contain addition
    std::vector<T> new_vec(l_vec.size);
    
    for (size_t i; i < l_vec.size; ++i) {
        new_vec[i] = l_vec[i] - r_vec[i];
    };
    
    return hla_vector<T>(new_vec);
    
};

/* multiplication overload */
template <typename T>
hla_vector<T> operator* (hla_vector<T>& l_vec, hla_vector<T>& r_vec) {
    
    if (l_vec.size != r_vec.size) {
        throw std::length_error("Cannot multiply vectors of different lengths.");
    };
    
    // initialize a new vector to contain addition
    std::vector<T> new_vec(l_vec.size);
    
    for (size_t i; i < l_vec.size; ++i) {
        new_vec[i] = l_vec[i] * r_vec[i];
    };
    
    return hla_vector<T>(new_vec);
    
};

/* division overload */
template <typename T>
hla_vector<T> operator/ (hla_vector<T>& l_vec, hla_vector<T>& r_vec) {
    
    if (l_vec.size != r_vec.size) {
        throw std::length_error("Cannot divide vectors of different lengths.");
    };
    
    // initialize a new vector to contain addition
    std::vector<T> new_vec(l_vec.size);
    
    for (size_t i; i < l_vec.size; ++i) {
        new_vec[i] = l_vec[i] / r_vec[i];
    };
    
    return hla_vector<T>(new_vec);
    
};

int main() {
    return 0;
};

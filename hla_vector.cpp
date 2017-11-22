
#include "hla_vector.h"
#include <vector>

/* ctor */
template <typename T>
hla_vector<T>::hla_vector(std::vector<T> vec_) {
    
    vec = vec_;
    
};

/* dtor */
template <typename T>
hla_vector<T>::~hla_vector() {
    
    delete vec;
    
};

int main() {
    return 0;
};

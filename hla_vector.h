
#ifndef HLA_VECTOR_H
#define HLA_VECTOR_H

#include <vector>

template <typename T>
class hla_vector {
    
    std::vector<T> m_vec;
    
public:
    
    /* ctor */
    hla_vector(const std::vector<T>& _vec);
    
    /* dtor */
    ~hla_vector();
    
    /* addition overload
     *
     * @param r_vec right vector to be added
     *
     * @return result vector after addition
     */
    hla_vector& operator+=(const hla_vector& r_vec);
    
private:
    
private:
    
};

#endif


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
    
    /* returns the size of the vector
     *
     * @return size of the vector
     */
    size_t size();
    
    /* access overload
     *
     * @param idx index of vector to access
     *
     * @return value at index i
     */
    T& operator[](size_t idx);
    
    /* addition equals overload
     *
     * @param r_vec right vector to be added
     *
     * @return result vector after addition
     */
    hla_vector& operator+=(const hla_vector& r_vec);
    
    /* subtraction equals overload
     *
     * @param r_vec right vector to be subtracted
     *
     * @return result vector after subtraction
     */
    hla_vector& operator-=(const hla_vector& r_vec);
    
private:
    
private:
    
};

#endif

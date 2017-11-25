
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
    
    /* multiplication equals overload - hadamard product
     *
     * @param r_vec right vector to be multiplied elementwise
     *
     * @return result vector after elementwise multiplication
     */
    hla_vector& operator*=(const hla_vector& r_vec);
    
    /* addition equals overload - scalar broadcast
     *
     * @param scalar to be added to each vector element
     *
     * @return result vector after broadcast addition
     */
    hla_vector& operator+=(const T& scalar);
    
    /* subtraction equals overload - scalar broadcast
     *
     * @param scalar to be subtracted from each vector element
     *
     * @return result vector after broadcast subtraction
     */
    hla_vector& operator-=(const T& scalar);

    /* multiplication equals overload - scalar broadcast
     *
     * @param scalar to be multiplied with each vector element
     *
     * @return result vector after broadcast multiplication
     */
    hla_vector& operator*=(const T& scalar);
    
private:
    
private:
    
};

#endif

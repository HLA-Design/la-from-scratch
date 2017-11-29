
#ifndef HLA_VECTOR_HPP
#define HLA_VECTOR_HPP

// includes : keep these to a minimum. Use forward declarations whenever can
#include <vector>

template <typename T>
class hla_vector {

private:
    // data members
    std::vector<T> m_vec;
    
public:
    
    /* ctor */
    hla_vector(const std::vector<T>& _vec);
    
    /* dtor */
    ~hla_vector();
    
    /* copy constructor */
    hla_vector(const hla_vector& vec);
    
    /* returns the size of the vector
     *
     * @return size of the vector
     */
    std::size_t size() const;
    
    /* access overload - const
     *
     * @param idx index of vector to access
     *
     * @return value at index i
     */
    const T& operator[](std::size_t idx) const;
    
    /* access overload
     *
     * @param idx index of vector to access
     *
     * @return value at index i
     */
    T& operator[](std::size_t idx);
    
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
    
    /* division equals overload
     *
     * @param r_vec right vector to be divided elementwise
     *
     * @return result vector after elementwise division
     */
    hla_vector& operator/=(const hla_vector& r_vec);
    
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
    
    /* division equals overload - scalar broadcast
     *
     * @param scalar to be divided with each vector element
     *
     * @return result vector after broadcast division
     */
    hla_vector& operator/=(const T& scalar);
    
    /* 1-norm computation
     *
     * @return 1 norm of the vector
     */
    double norm_1() const;
    
    /* 2-norm computation
     *
     * @return 2 norm of the vector
     */
    double norm_2() const;
    
    /* infinity-norm computation
     *
     * @return infinity norm of the vector
     */
    double norm_inf() const;
    
    /* generic p-norm computation
     *
     * @param p where p >= 1 - defines order of the norm
     *
     * @return p norm of the vector
     */
    double norm(double& p) const;
    
    /* computes the dot product with another vector
     *
     * @param r_vec
     *
     * @return dot product of this vec and r_vec
     */
    double dot(hla_vector& r_vec);
    
    /* prints the contents of the vector */
    void print();
    
private:
    
private:
    
};

#include "hla_vector.inl"

/******************
 * UTIL FUNCTIONS *
 ******************/

/* addition overload
 *
 * @param l_vec left vector to be added
 * @param r_vec right vector to be added
 *
 * @return new vector equal to the sum of l_vec and r_vec
 */
template <typename T>
hla_vector<T> operator+ (const hla_vector<T>& l_vec, const hla_vector<T>& r_vec);

/* normalizes the vector into a unit vector
 *
 * @return normalized m_vec
 */
template <typename T>
hla_vector<double> normalize(const hla_vector<T>& vec);


#endif

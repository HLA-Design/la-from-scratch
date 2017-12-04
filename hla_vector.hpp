
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
    
    /* default ctor */
    hla_vector();
    
    /* ctor */
    hla_vector(const std::vector<T>& _vec);
    
//    hla_vector(const std::vector<hla_vector<T> >& _vec);
    
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
    double dot(const hla_vector& r_vec) const;

    /*
     * adds a new element after the current last
     * element of hla_vector; effectively increases
     * container size by 1
     * @param _val input value to be appended
     */
    void push_back(const T& _val);
 
    /* appends vector's entries to right of @param this
     *
     * @param r_vec length m vector to be appended
     *
     * @return vector equal to @param r_vec appended to @param this
     */
    hla_vector& append(const hla_vector& r_vec);
    
    /* prints the contents of the vector */
    void print() ;
    
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

/* subtraction overload
 *
 * @param l_vec left vector to be subtracted from
 * @param r_vec right vector to be subtracted
 *
 * @return new vector equal to the l_vec - r_vec
 */
template <typename T>
hla_vector<T> operator- (const hla_vector<T>& l_vec, const hla_vector<T>& r_vec);

/* multiplication overload - hadamard product
 *
 * @param l_vec left vector to be multiplied
 * @param r_vec right vector to be multiplied
 *
 * @return new vector equal to the elementwise multiplication of l_vec and r_vec
 */
template <typename T>
hla_vector<T> operator* (const hla_vector<T>& l_vec, const hla_vector<T>& r_vec);

/* division overload - elementwise division
 *
 * @param l_vec left vector to be divided by (numerator)
 * @param r_vec right vector to divide with (dernominator)
 *
 * @return new vector equal to the elementwise division of l_vec and r_vec
 */
template <typename T>
hla_vector<T> operator/ (const hla_vector<T>& l_vec, const hla_vector<T>& r_vec);

/* addition overload - vec + scalar
 *
 * @param l_vec left vector to be added
 * @param r_scalar right scalar to be added
 *
 * @return new vector equal to the broadcast sum of l_vec and r_scalar
 */
template <typename T>
hla_vector<T> operator+ (const hla_vector<T>& l_vec, const T& r_scalar);

/* addition overload - scalar + vec
 *
 * @param l_scalar left scalar to be added
 * @param r_vec right vector to be added
 *
 * @return new vector equal to the broadcast sum of r_vec and l_scalar
 */
template <typename T>
hla_vector<T> operator+ (const T& l_scalar, const hla_vector<T>& r_vec);

/* subtraction overload - vec - scalar
 *
 * @param l_vec left vector to be suntracted from
 * @param r_scalar right scalar to subtract by
 *
 * @return new vector equal to the broadcast subtraction of l_vec and r_scalar
 */
template <typename T>
hla_vector<T> operator- (const hla_vector<T>& l_vec, const T& r_scalar);

/* subtraction overload - scalar - vec
 *
 * @param l_scalar left scalar to be broadcast subtracted from
 * @param r_vec right vector to be subtracted by
 *
 * @return new vector equal to the broadcast subtraction of r_vec and l_scalar
 */
template <typename T>
hla_vector<T> operator- (const T& l_scalar, const hla_vector<T>& r_vec);

/* multiplication overload - vec * scalar
 *
 * @param l_vec left vector to be multiplied
 * @param r_scalar right scalar to multiplied
 *
 * @return new vector equal to the broadcast multiplication of l_vec and r_scalar
 */
template <typename T>
hla_vector<T> operator* (const hla_vector<T>& l_vec, const T& r_scalar);

/* multiplication overload - scalar * vec
 *
 * @param l_scalar left scalar to be multiplied
 * @param r_vec right vector to be multiplied
 *
 * @return new vector equal to the broadcast multiplication of r_vec and l_scalar
 */
template <typename T>
hla_vector<T> operator* (const T& l_scalar, const hla_vector<T>& r_vec);

/* division overload - vec / scalar
 *
 * @param l_vec left vector to be divided (numerator)
 * @param r_scalar right scalar to divide by (denominator)
 *
 * @return new vector equal to the broadcast division of l_vec and r_scalar
 */
template <typename T>
hla_vector<T> operator/ (const hla_vector<T>& l_vec, const T& r_scalar);

/* division overload - scalar / vec
 *
 * @param l_scalar left scalar to be broadcast divided (numerator)
 * @param r_vec right vector to divide by (denominator)
 *
 * @return new vector equal to the broadcast division of r_vec and l_scalar
 */
template <typename T>
hla_vector<T> operator/ (const T& l_scalar, const hla_vector<T>& r_vec);

/* less than overload
 *
 * @param l_vec left vector of size n to be compared
 * @param r_vec right vector of size n to be compared
 *
 * @return boolean vector where @return[i] = true if l_vec[i] < r_vec[i]
 */
template <typename T>
hla_vector<bool> operator< (const hla_vector<T>& l_vec, const hla_vector<T>& r_vec);

/* less than or equals overload
 *
 * @param l_vec left vector of size n to be compared
 * @param r_vec right vector of size n to be compared
 *
 * @return boolean vector where @return[i] = true if l_vec[i] <= r_vec[i]
 */
template <typename T>
hla_vector<bool> operator<= (const hla_vector<T>& l_vec, const hla_vector<T>& r_vec);

/* greater than overload
 *
 * @param l_vec left vector of size n to be compared
 * @param r_vec right vector of size n to be compared
 *
 * @return boolean vector where @return[i] = true if l_vec[i] > r_vec[i]
 */
template <typename T>
hla_vector<bool> operator> (const hla_vector<T>& l_vec, const hla_vector<T>& r_vec);

/* greater than or equals overload
 *
 * @param l_vec left vector of size n to be compared
 * @param r_vec right vector of size n to be compared
 *
 * @return boolean vector where @return[i] = true if l_vec[i] >= r_vec[i]
 */
template <typename T>
hla_vector<bool> operator>= (const hla_vector<T>& l_vec, const hla_vector<T>& r_vec);

/* equals to overload
 *
 * @param l_vec left vector of size n to be compared
 * @param r_vec right vector of size n to be compared
 *
 * @return boolean vector where @return[i] = true if l_vec[i] == r_vec[i]
 */
template <typename T>
hla_vector<bool> operator== (const hla_vector<T>& l_vec, const hla_vector<T>& r_vec);

/* less than overload - vec < scalar
 *
 * @param l_vec left vector of size n to be compared
 * @param r_scalar right scalar to be compared
 *
 * @return boolean vector where @return[i] = true if l_vec[i] < r_scalar
 */
template <typename T>
hla_vector<bool> operator< (const hla_vector<T>& l_vec, const T& r_scalar);

/* less than overload - scalar < vec
 *
 * @param l_scalar left scalar to be compared
 * @param r_vec right vector of size n to be compared
 *
 * @return boolean vector where @return[i] = true if l_scalar < r_vec[i]
 */
template <typename T>
hla_vector<bool> operator< (const T& l_scalar, const hla_vector<T>& r_vec);

/* less than or equals overload - vec <= scalar
 *
 * @param l_vec left vector of size n to be compared
 * @param r_scalar right scalar to be compared
 *
 * @return boolean vector where @return[i] = true if l_vec[i] <= r_scalar
 */
template <typename T>
hla_vector<bool> operator<= (const hla_vector<T>& l_vec, const T& r_scalar);

/* less than or equals overload - scalar <= vec
 *
 * @param l_scalar left scalar to be compared
 * @param r_vec right vector of size n to be compared
 *
 * @return boolean vector where @return[i] = true if l_scalar <= r_vec[i]
 */
template <typename T>
hla_vector<bool> operator<= (const T& l_scalar, const hla_vector<T>& r_vec);

/* greater than overload - vec > scalar
 *
 * @param l_vec left vector of size n to be compared
 * @param r_scalar right scalar to be compared
 *
 * @return boolean vector where @return[i] = true if l_vec[i] > r_scalar
 */
template <typename T>
hla_vector<bool> operator> (const hla_vector<T>& l_vec, const T& r_scalar);

/* greater than overload - scalar > vec
 *
 * @param l_scalar left scalar to be compared
 * @param r_vec right vector of size n to be compared
 *
 * @return boolean vector where @return[i] = true if l_scalar > r_vec[i]
 */
template <typename T>
hla_vector<bool> operator> (const T& l_scalar, const hla_vector<T>& r_vec);

/* greater than or equal overload - vec >= scalar
 *
 * @param l_vec left vector of size n to be compared
 * @param r_scalar right scalar to be compared
 *
 * @return boolean vector where @return[i] = true if l_vec[i] >= r_scalar
 */
template <typename T>
hla_vector<bool> operator>= (const hla_vector<T>& l_vec, const T& r_scalar);

/* greater than or equal overload - scalar >= vec
 *
 * @param l_scalar left scalar to be compared
 * @param r_vec right vector of size n to be compared
 *
 * @return boolean vector where @return[i] = true if l_scalar >= r_vec[i]
 */
template <typename T>
hla_vector<bool> operator>= (const T& l_scalar, const hla_vector<T>& r_vec);

/* equals to overload - vec == scalar
 *
 * @param l_vec left vector of size n to be compared
 * @param r_scalar right scalar to be compared
 *
 * @return boolean vector where @return[i] = true if l_vec[i] == r_scalar
 */
template <typename T>
hla_vector<bool> operator== (const hla_vector<T>& l_vec, const T& r_scalar);

/* equals to overload - scalar == vec
 *
 * @param l_scalar left scalar to be compared
 * @param r_vec right vector of size n to be compared
 *
 * @return boolean vector where @return[i] = true if l_scalar == r_vec[i]
 */
template <typename T>
hla_vector<bool> operator== (const T& l_scalar, const hla_vector<T>& r_vec);

/* normalizes the vector into a unit vector
 *
 * @return normalized m_vec
 */
template <typename T>
hla_vector<double> normalize(const hla_vector<T>& vec);

/* cosine similarity of two vectors
 *
 * @param vec1 any vector of size n
 * @param vec2 any vector of size n
 *
 * @return cosine similarity of vec1 and vec2
 */
template <typename T>
double cosine_sim(const hla_vector<T>& vec1, const hla_vector<T>& vec2);

/* cosine similarity of two vectors - using normalize
 *
 * @param vec1 any vector of size n
 * @param vec2 any vector of size n
 *
 * @return cosine similarity of vec1 and vec2
 */
template <typename T>
double cosine_sim_norm(const hla_vector<T>& vec1, const hla_vector<T>& vec2);

/* cosine similarity of two vectors - using norm_2 and dot
 *
 * @param vec1 any vector of size n
 * @param vec2 any vector of size n
 *
 * @return cosine similarity of vec1 and vec2
 */
template <typename T>
double cosine_sim_length(const hla_vector<T>& vec1, const hla_vector<T>& vec2);

/* appends two vectors together making a new vector
 *
 * @param l_vec vector of size m
 * @param r_vec vector of size n
 *
 * @return vector of size m + n with first m entries correspond to @param l_vec
 *         and the last n entries correspond to @param r_vec
 */
template <typename T>
hla_vector<T> append(const hla_vector<T>& l_vec, const hla_vector<T>& r_vec);

#endif

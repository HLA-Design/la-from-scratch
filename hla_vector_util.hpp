
#ifndef HLA_VECTOR_UTIL_HPP
#define HLA_VECTOR_UTIL_HPP

#include <vector>
#include "hla_vector.hpp"

/* addition overload
 *
 * @param l_vec left vector to be added
 * @param r_vec right vector to be added
 *
 * @return new vector equal to the sum of l_vec and r_vec
 */
hla_vector<T> operator+ (hla_vector<T>& l_vec, hla_vector<T>& r_vec);

/* subtraction overload
 *
 * @param l_vec left vector to be subtracted from
 * @param r_vec right vector to be subtracted
 *
 * @return new vector equal to the difference of l_vec and r_vec
 */
hla_vector<T> operator- (hla_vector<T>& l_vec, hla_vector<T>& r_vec);

/* multiplication overload
 *
 * @param l_vec left vector to be multiplied
 * @param r_vec right vector to be multiplied
 *
 * @return new vector equal to the elementwise product of l_vec and r_vec
 */
hla_vector<T> operator* (hla_vector<T>& l_vec, hla_vector<T>& r_vec);

/* division overload
 *
 * @param l_vec left vector to be divided - numerator
 * @param r_vec right vector to divide by - denominator
 *
 * @return new vector equal to the elementwise division of l_vec and r_vec
 */
hla_vector<T> operator/ (hla_vector<T>& l_vec, hla_vector<T>& r_vec);

/* normalize vector */

#endif

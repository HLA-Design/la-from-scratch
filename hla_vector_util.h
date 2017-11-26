
#ifndef HLA_VECTOR_UTIL_H
#define HLA_VECTOR_UTIL_H

#include <vector>
#include "hla_vector.h"

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

#endif

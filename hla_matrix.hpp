
#ifndef HLA_MATRIX_HPP
#define HLA_MATRIX_HPP

// includes : keep these to a minimum. Use forward declarations whenever can
#include <vector>
#include "hla_vector.hpp"

template <typename T>
class hla_matrix {

private:
   // data members:
   hla_vector<hla_vector<T> > m_matrix;

public:
   /* default ctor */
   hla_matrix ();

   /* ctor */
   hla_matrix (const std::vector<std::vector <T> >& _vec);

   /* ctor */
   hla_matrix (const std::vector<hla_vector <T> >& _vec);

   /* ctor */
   hla_matrix (const hla_vector<hla_vector <T> >& _vec);

   /* dtor */
   ~hla_matrix ();

   /* print out the contents of the matrix */
   void print() const;

   /* returns the size of the matrix as a hla_vector
    *
    * @return size of the vector as hla_vector. idx 0 = # rows, isx 1 = # cols
    */
   hla_vector<std::size_t> size() const;

   /* returns the number of columns in the matrix
    *
    * @return the number of columns in the matrix
    */
   std::size_t n_col() const;

   /* returns the number of rows in the matrix
    *
    * @return the number of rows in the matrix
    */
   std::size_t n_row() const;

   /* access overload - const
    *
    * @param column idx index of matrix to access
    *
    * @return hla_vector at column index i
    */
   const hla_vector<T>& operator[](std::size_t idx) const;

  /* access overload
   *
   * @param column idx index of matrix to access
   *
   * @return hla_vector at column index i
   */
  hla_vector<T>& operator[](std::size_t idx);

  /* returns value at specified row and column
   *
   * @param row row index of element
   * @param col col index of element
   *
   * @return the value at the specified row and col index
   */
  const T& get(std::size_t row, std:: size_t col) const;

private:

private:

};

#include "hla_matrix.inl"

#endif

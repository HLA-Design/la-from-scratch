
// includes : keep these to a minimum
#include <vector>
#include <cmath>
#include <limits>
#include <iostream>

#include "hla_vector.hpp"

// Fwd declarations
template <typename T> class hla_matrix;

/* default ctor */
template <typename T>
hla_matrix<T>::hla_matrix()
: m_matrix (hla_vector<hla_vector<T> >())
{
}

/* ctor */
template <typename T>
hla_matrix<T>::hla_matrix(const std::vector<std::vector<T> >& _vec)
{
  for (const auto& elem : _vec) {
    m_matrix.push_back(elem);
  }
}

/* ctor */
template <typename T>
hla_matrix<T>::hla_matrix(const std::vector<hla_vector<T> >& _vec)
{
  for (const auto& elem : _vec) {
    m_matrix.push_back(elem);
  }
}

/* ctor */
template <typename T>
hla_matrix<T>::hla_matrix(const hla_vector<hla_vector<T> >& _vec)
{
  for (const auto& elem : _vec) {
    m_matrix.push_back(elem);
  }
}

/* dtor */
template <typename T>
hla_matrix<T>::~hla_matrix()
{
  // no work;
}

/* print out contents of this matrix */
template <typename T>
void hla_matrix<T>::print() const
{
  std::cout << "[" << std::endl << std::endl;

  for (const auto& elem : m_matrix) {
    elem.print();
    std::cout << std::endl;
  }

  std::cout << "]" << std::endl;

  return;
}

/* returns the size of the vector */
template <typename T>
hla_vector<std::size_t> hla_matrix<T>::size() const {

  std::vector<std::size_t> std_vec (2);
  hla_vector<std::size_t> size_vec (std_vec);

  size_vec[0] = m_matrix[0].size();
  size_vec[1] = m_matrix.size();

  return size_vec;
}

/* returns the number of columns in the matrix */
template <typename T>
std::size_t hla_matrix<T>::n_col() const {

  return m_matrix.size();

}

/* returns the number of rows in the matrix */
template <typename T>
std::size_t hla_matrix<T>::n_row() const {

  return m_matrix[0].size();

}

/* access overload - const */
template <typename T>
const hla_vector<T>& hla_matrix<T>::operator[](std::size_t idx) const {

  if (idx >= m_matrix.size()) {
    throw std::length_error("Accessing matrix out of column range");
  }

  return m_matrix[idx];

}

/* access overload */
template <typename T>
hla_vector<T>& hla_matrix<T>::operator[](std::size_t idx) {

  if (idx >= m_matrix.size()) {
    throw std::length_error("Accessing matrix out of column range");
  }

  return m_matrix[idx];

}

/* returns value at specified row and column */
template <typename T>
const T& hla_matrix<T>::get(std::size_t row, std:: size_t col) const {

  if (col >= this->n_col()) {
    throw std::length_error("Accessing matrix out of column range");
  }

  if (row >= this->n_row()) {
    throw std::length_error("Accessing matrix out of row range");
  }

  return m_matrix[col][row];

}

/* addition equals overload */
template <typename T>
hla_matrix<T>& hla_matrix<T>::operator+=(const hla_matrix<T>& r_mat) {

  if (!(r_mat.size().is_equal(this->size()))) {
    throw std::length_error("Cannot add matrices of different sizes");
  }

  for (std::size_t i = 0; i < this->n_col(); ++i) {
    m_matrix[i] += r_mat[i];
  }

  return *this;

}

/* subtraction equals overload */
template <typename T>
hla_matrix<T>& hla_matrix<T>::operator-=(const hla_matrix<T>& r_mat) {

  if (!(r_mat.size().is_equal(this->size()))) {
    throw std::length_error("Cannot subtract matrices of different sizes");
  }

  for (std::size_t i = 0; i < this->n_col(); ++i) {
    m_matrix[i] -= r_mat[i];
  }

  return *this;

}

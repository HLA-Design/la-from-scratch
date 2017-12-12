
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

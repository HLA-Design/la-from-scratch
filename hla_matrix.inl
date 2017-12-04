
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
// TODO: check if it works...may need a size method
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
void hla_matrix<T>::print()
{
  std::cout << "[" << std::endl;

  for (std::size_t i = 0; i < m_matrix.size() - 1; ++i) {
    m_matrix[i].print();
    std::cout << std::endl;
  }

  std::cout << "]" << std::endl;

  return;
}

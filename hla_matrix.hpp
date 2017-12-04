
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
   void print();

private:
    
private:
    
};

#include "hla_matrix.inl"

#endif

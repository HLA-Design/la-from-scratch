#include <vector>
#include "hla_vector.hpp"
#include "hla_matrix.hpp"

int main() {

    std::vector<int> x1(5);
    std::vector<int> x2(5);
    std::vector<int> x3(5);
    std::vector<int> x4(5);
    std::vector<int> x5(5);

    for (int i = 0; i < 5; ++i) {
        x1[i] = i - 2;
        x2[i] = i - 1;
        x3[i] = i;
        x4[i] = i + 1;
        x5[i] = i + 2;
    }

    hla_vector<int> vec1 (x1);
    hla_vector<int> vec2 (x2);
    hla_vector<int> vec3 (x3);
    hla_vector<int> vec4 (x4);
    hla_vector<int> vec5 (x5);

    // -------------------------------------------------------------------------
    // TEST 1 : Construction from std::vector <hla_vector<T> >
    // -------------------------------------------------------------------------
    std::vector<hla_vector<int> > std_mat (5);
    std_mat[0] = x1;
    std_mat[1] = x2;
    std_mat[2] = x3;
    std_mat[3] = x4;
    std_mat[4] = x5;

    // test construction
    hla_matrix<int> mat1 (std_mat);
    std::cout << std::endl << "Printing mat1 constructed from std::vector<hla_vector<int> > " << std::endl;
    mat1.print();

    // -------------------------------------------------------------------------
    // TEST 2 : Construction from hla_vector::vector <hla_vector<T> >
    // -------------------------------------------------------------------------
    hla_vector<hla_vector<int> > hla_mat; // default ctor
    hla_mat.push_back(vec1);
    hla_mat.push_back(vec2);
    hla_mat.push_back(vec3);
    hla_mat.push_back(vec4);
    hla_mat.push_back(vec5);

    // test construction
    hla_matrix<int> mat2 (hla_mat);
    std::cout << std::endl << "Printing mat2 constructed from hla::vector<hla_vector<int> > " << std::endl;
    mat2.print();

    /* test size method */
    std::cout << std::endl << "testing size method for matrix" << std::endl;

    mat2.size().print();

    /* test access method */
    std::cout << std::endl << "testing access opperator" << std::endl;

    mat1[0].print();
    mat1[3].print();

    /* test can't access out of bounds */
    std::cout << std::endl << "test exception handling of out of bounds access" <<std::endl;

    try {
        mat1[10];
    } catch (std::length_error& e) {
        std::cout << e.what();
    }

    return 0;

};

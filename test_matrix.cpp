#include <vector>
#include "hla_vector.hpp"
#include "hla_matrix.hpp"

int main() {

    std::vector<int> x1(5);
    std::vector<int> x2(5);
    std::vector<int> x3(5);
    std::vector<int> x4(5);
    std::vector<int> x5(5);

    std::vector<int> y1(5);
    std::vector<int> y2(5);
    std::vector<int> y3(5);
    std::vector<int> y4(5);
    std::vector<int> y5(5);

    std::vector<int> z1(5);
    std::vector<int> z2(5);
    std::vector<int> z3(5);
    std::vector<int> z4(5);
    std::vector<int> z5(5);
    std::vector<int> z6(5);

    for (int i = 0; i < 5; ++i) {
        x1[i] = i - 2;
        x2[i] = i - 1;
        x3[i] = i;
        x4[i] = i + 1;
        x5[i] = i + 2;
        y1[i] = i + 2;
        y2[i] = i + 1;
        y3[i] = i;
        y4[i] = i - 1;
        y5[i] = i - 2;
        z1[i] = i + 3;
        z2[i] = i + 2;
        z3[i] = i + 1;
        z4[i] = i;
        z5[i] = i - 1;
        z6[i] = i - 2;
    }

    hla_vector<int> x_vec1 (x1);
    hla_vector<int> x_vec2 (x2);
    hla_vector<int> x_vec3 (x3);
    hla_vector<int> x_vec4 (x4);
    hla_vector<int> x_vec5 (x5);

    hla_vector<int> y_vec1 (y1);
    hla_vector<int> y_vec2 (y2);
    hla_vector<int> y_vec3 (y3);
    hla_vector<int> y_vec4 (y4);
    hla_vector<int> y_vec5 (y5);

    hla_vector<int> z_vec1 (z1);
    hla_vector<int> z_vec2 (z2);
    hla_vector<int> z_vec3 (z3);
    hla_vector<int> z_vec4 (z4);
    hla_vector<int> z_vec5 (z5);
    hla_vector<int> z_vec6 (z6);

    // -------------------------------------------------------------------------
    // TEST 1 : Construction from std::vector <hla_vector<T> >
    // -------------------------------------------------------------------------
    std::vector<hla_vector<int> > std_mat_x (5);
    std_mat_x[0] = x1;
    std_mat_x[1] = x2;
    std_mat_x[2] = x3;
    std_mat_x[3] = x4;
    std_mat_x[4] = x5;

    std::vector<hla_vector<int> > std_mat_y (5);
    std_mat_y[0] = y1;
    std_mat_y[1] = y2;
    std_mat_y[2] = y3;
    std_mat_y[3] = y4;
    std_mat_y[4] = y5;

    std::vector<hla_vector<int> > std_mat_z (6);
    std_mat_z[0] = z1;
    std_mat_z[1] = z2;
    std_mat_z[2] = z3;
    std_mat_z[3] = z4;
    std_mat_z[4] = z5;
    std_mat_z[5] = z6;

    // test construction
    hla_matrix<int> mat1 (std_mat_x);
    hla_matrix<int> mat2 (std_mat_y);
    hla_matrix<int> mat3 (std_mat_z);
    std::cout << std::endl << "Printing mat1 constructed from std::vector<hla_vector<int> > " << std::endl;
    mat1.print();

    // -------------------------------------------------------------------------
    // TEST 2 : Construction from hla_vector::vector <hla_vector<T> >
    // -------------------------------------------------------------------------
    hla_vector<hla_vector<int> > hla_mat; // default ctor
    hla_mat.push_back(x_vec1);
    hla_mat.push_back(x_vec2);
    hla_mat.push_back(x_vec3);
    hla_mat.push_back(x_vec4);
    hla_mat.push_back(x_vec5);

    // test construction
    hla_matrix<int> mat_other (hla_mat);
    std::cout << std::endl << "Printing mat2 constructed from hla::vector<hla_vector<int> > " << std::endl;
    mat_other.print();

    /* test size method */
    std::cout << std::endl << "testing size method for matrix" << std::endl;

    mat1.size().print();
    mat2.size().print();

    /* test n_col method */
    std::cout << std::endl << "test n_col method for mat1" << std::endl;
    std::cout << std::endl << mat1.n_col() << std::endl;

    /* test n_row method */
    std::cout << std::endl << "test n_row method for mat1" << std::endl;
    std::cout << std::endl << mat1.n_row() << std::endl;

    /* test access method */
    std::cout << std::endl << "testing access opperator" << std::endl;

    mat1[0].print();
    mat1[3].print();

    /* test can't access out of bounds */
    std::cout << std::endl << "test exception handling of out of bounds access" <<std::endl;

    try {
        mat1[10];
    } catch (std::length_error& e) {
        std::cout << std::endl << e.what() << std::endl;
    }

    /* test get successful get method */
    std::cout << std::endl << "testing get(0, 0) method on mat1" << std::endl;
    std::cout << std::endl << mat1.get(0, 0) << std::endl;

    std::cout << std::endl << "testing get(2, 4) method on mat1" << std::endl;
    std::cout << std::endl << mat1.get(2, 4) << std::endl;

    /* test error handling of get method */
    std::cout << std::endl << "testing get(0, 10) method error method on mat1 - invalid col idx" << std::endl;
    try {
        mat1.get(0, 10);
    } catch (std::length_error& e) {
        std::cout << std::endl << e.what() << std::endl;
    }

    std::cout << std::endl << "testing get(10, 0) method error method on mat1 - invalid row idx" << std::endl;
    try {
        mat1.get(10, 0);
    } catch (std::length_error& e) {
        std::cout << std::endl << e.what() << std::endl;
    }

    std::cout << std::endl << "testing get(10, 10) method error method on mat1 - invalid row and col idx" << std::endl;
    try {
        mat1.get(10, 10);
    } catch (std::length_error& e) {
        std::cout << std::endl << e.what() << std::endl;
    }

    /* test += opperator - matrix */
    std::cout << std::endl << "testing mat1 += mat2" << std::endl;
    mat1 += mat2;
    mat1.print();

    std::cout << std::endl << "testing += error on mat1 += mat3 - different sized matrices" << std::endl;
    try {
        mat1 += mat3;
    } catch (std::length_error& e) {
        std::cout << std::endl << e.what() << std::endl;
    }

    /* test -= opperator - matrix */
    std::cout << std::endl << "testing mat1 -= mat2" << std::endl;
    mat1 -= mat2;
    mat1.print();

    std::cout << std::endl << "testing -= error on mat1 -= mat3 - different sized matrices" << std::endl;
    try {
        mat1 -= mat3;
    } catch (std::length_error& e) {
        std::cout << std::endl << e.what() << std::endl;
    }

    return 0;

};

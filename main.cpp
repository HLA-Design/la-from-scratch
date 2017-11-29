#include <vector>
#include "hla_vector.hpp"
//#include <iostream>

int main() {

    std::vector<int> x(5);
    std::vector<int> y(5);
    std::vector<int> z(6);
    int scalar = 2;
    double p1 = 2.0;
    double p2 = std::numeric_limits<double>::infinity();
    double p3 = 3.75;
    double p4 = 0.99;
    
    for (int i = 1; i < 6; ++i) {
        x[i - 1] = i;
        y[i - 1] = 6 - i;
        z[i - 1] = i;
    }
    
    z[5] = 6;
    
    // test construction
    hla_vector<int> vec1 (x);
    hla_vector<int> vec2 (y);
    hla_vector<int> vec3 (z);
    
    std::cout << "\n" << "Our vectors vec1, vec2, and vec3:" << "\n";
    
    vec1.print();
    vec2.print();
    vec3.print();
    
    // test size
    std::cout << "\n\n" << "the sizes of our three vectors" << "\n";
    
    std::cout << vec1.size() << "\n";
    std::cout << vec2.size() << "\n";
    std::cout << vec3.size() << "\n";
    
    // test += vec op
    std::cout << "\n" << "vec 1 after += vec 2:" << "\n";
    
    vec1 += vec2;
    vec1.print();
    
    std::cout << "\n\n" << "exception after vec2 += vec3:" << "\n";
    
    try {
        vec2 += vec3;
    } catch (std::length_error& e) {
        std::cout << e.what();
    }
    
    // test -= vec op
    std::cout << "\n\n" << "vec 1 after -= vec 2:" << "\n";
    
    vec1 -= vec2;
    vec1.print();
    
    std::cout << "\n\n" << "exception after vec2 -= vec3:" << "\n";
    
    try {
        vec2 -= vec3;
    } catch (std::length_error& e) {
        std::cout << e.what();
    }
    
    // test *= vec op
    std::cout << "\n\n" << "vec 1 after *= vec 2:" << "\n";
    
    vec1 *= vec2;
    vec1.print();

    std::cout << "\n\n" << "exception after vec2 *= vec3:" << "\n";
    
    try {
        vec2 *= vec3;
    } catch (std::length_error& e) {
        std::cout << e.what();
    }
    
    // test /= vec op
    std::cout << "\n\n" << "vec 1 after /= vec 2:" << "\n";
    
    vec1 /= vec2;
    vec1.print();

    std::cout << "\n\n" << "exception after vec2 /= vec3:" << "\n";
    
    try {
        vec2 /= vec3;
    } catch (std::length_error& e) {
        std::cout << e.what();
    }
    
    // test += scalar op
    std::cout << "\n\n" << "vec 1 after += scalar:" << "\n";
    
    vec1 += scalar;
    vec1.print();
  
    // test -= scalar op
    std::cout << "\n\n" << "vec 1 after -= scalar:" << "\n";
    
    vec1 -= scalar;
    vec1.print();
    
    // test *= scalar op
    std::cout << "\n\n" << "vec 1 after *= scalar:" << "\n";
    
    vec1 *= scalar;
    vec1.print();
    
    // test /= scalar op
    std::cout << "\n\n" << "vec 1 after /= scalar:" << "\n";
    
    vec1 /= scalar;
    vec1.print();
    
    // test norm_1
    std::cout << "\n\n" << "vec 1 1-norm" << "\n";
    std::cout << vec1.norm_1();
    
    // test norm_2
    std::cout << "\n\n" << "vec 1 2-norm" << "\n";
    std::cout << vec1.norm_2();
    
    // test norm_inf
    std::cout << "\n\n" << "vec 1 inf-norm" << "\n";
    std::cout << vec1.norm_inf();
    
    // test p_norm p = 2
    std::cout << "\n\n" << "vec 1 p-norm, p = 2" << "\n";
    std::cout << vec1.norm(p1);
    
    // test p_norm p = infinity
    std::cout << "\n\n" << "vec 1 p-norm, p = infinity" << "\n";
    std::cout << vec1.norm(p2);
    
    // test p_norm p = 3.75
    std::cout << "\n\n" << "vec 1 p-norm, p = 3.75" << "\n";
    std::cout << vec1.norm(p3);
    
    // test exception for p < 1
    std::cout << "\n\n" << "exception if p < 1:" << "\n";
    
    try {
        vec1.norm(p4);
    } catch (std::invalid_argument& e) {
        std::cout << e.what();
    }
    
    // test dot method
    std::cout << "\n\n" << "test vec1.dot(vec2)" << "\n";
    std::cout << vec1.dot(vec2) << "\n";
    
    std::cout << "\n" << "test vec1.dot(vec3) throws length exception" << "\n";
    try {
        vec1.dot(vec3);
    } catch (std::length_error& e) {
        std::cout << e.what();
    }
    
    // test vector addition util function
    std::cout << "\n\n" << "test vec1 + vec2" << "\n";
    hla_vector<int> add_vec = vec1 + vec2;
    
    add_vec.print();
    
    std::cout << "\n\n" << "exception after vec1 + vec3:" << "\n";
    
    try {
        hla_vector<int> add_vec_error = vec1 + vec3;
    } catch (std::length_error& e) {
        std::cout << e.what();
    }
 
    // test vector subtraction util function
    std::cout << "\n\n" << "test vec1 - vec2" << "\n";
    hla_vector<int> sub_vec = vec1 - vec2;
    
    sub_vec.print();
    
    std::cout << "\n\n" << "exception after vec1 - vec3:" << "\n";
    
    try {
        hla_vector<int> sub_vec_error = vec1 - vec3;
    } catch (std::length_error& e) {
        std::cout << e.what();
    }

    // test vector multiplication util function
    std::cout << "\n\n" << "test vec1 * vec2" << "\n";
    hla_vector<int> mult_vec = vec1 * vec2;
    
    mult_vec.print();
    
    std::cout << "\n\n" << "exception after vec1 * vec3:" << "\n";
    
    try {
        hla_vector<int> mult_vec_error = vec1 * vec3;
    } catch (std::length_error& e) {
        std::cout << e.what();
    }
    
    // test vector division util function
    std::cout << "\n\n" << "test vec1 / vec2" << "\n";
    hla_vector<int> div_vec = vec1 / vec2;
    
    div_vec.print();
    
    std::cout << "\n\n" << "exception after vec1 / vec3:" << "\n";
    
    try {
        hla_vector<int> div_vec_error = vec1 / vec3;
    } catch (std::length_error& e) {
        std::cout << e.what();
    }
    
    // test addition - vec + scalar - util function
    std::cout << "\n\n" << "test vec1 + scalar" << "\n";
    
    hla_vector<int> add_scalar_vec_l = vec1 + scalar;
    hla_vector<int> add_scalar_vec_r = scalar + vec1;
    
    add_scalar_vec_l.print();
    add_scalar_vec_r.print();
    
    // test normalize vector util function
    std::cout << "\n\n" << "test normalize(vec1)" << "\n";
    
    hla_vector<double> norm_vec1 = normalize(vec1);
    
    norm_vec1.print();
    
    std::cout << "\n\n";
    
    return 0;
};

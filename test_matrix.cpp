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
    
//    std::vector<hla_vector<int> > std_mat (5);
    
//    std_mat[0] = x1;
//    std_mat[1] = x2;
//    std_mat[2] = x3;
//    std_mat[3] = x4;
//    std_mat[4] = x5;
    
//    hla_vector<hla_vector<int> > mat1_vec (std_mat);
    
    // test construction
//    hla_matrix<int> mat1 (std_mat);
    
    hla_matrix<int> mat1;
    
    return 0;
    
};

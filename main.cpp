#include <vector>
#include "hla_vector.hpp"

int main() {

    std::vector<int> x(5);
    
    for (int i = 0; i < 5; ++i) {
        x[i] = i;
    }
    
    hla_vector<int> vec1 (x);

    return 0;
};

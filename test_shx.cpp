#include <cassert>
#include <iostream>
#include "ShxCalculator.h"
#include <cmath>

int main() {
    ShxCalculator calc;
    double result = calc.FuncA(3);
    double expected = 0.0;
    for (int n = 0; n < 3; n++) {
        expected += pow(1.0, 2*n + 1) / tgamma(2*n + 2);
    }
    assert(abs(result - expected) < 1e-6);
    std::cout << "Test passed!" << std::endl;
    return 0;
}

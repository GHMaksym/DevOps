#include <cassert>
#include <iostream>
#include "ShxCalculator.h"
#include <cmath>

int main() {
    ShxCalculator calc;
    double x = 1.0;
    int terms = 3;
    double result = calc.FuncA(terms, x);
    double expected = 0.0;
    for (int n = 0; n < terms; n++) {
        expected += pow(x, 2 * n + 1) / tgamma(2 * n + 2);
    }
    assert(std::abs(result - expected) < 1e-6);
    std::cout << "Test passed!" << std::endl;
    return 0;
}

#include "ShxCalculator.h"
#include <cmath>

double ShxCalculator::FuncA(int n, double x) {
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        double term = pow(x, 2 * i + 1) / tgamma(2 * i + 2);
        result += term;
    }
    return result;
}

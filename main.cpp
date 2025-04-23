#include <iostream>
#include "ShxCalculator.h"

int main() {
    ShxCalculator calc;
    int n;
    double x;

    std::cout << "Enter n: ";
    std::cin >> n;

    std::cout << "Enter x: ";
    std::cin >> x;

    std::cout << "Result for FuncA(" << n << ", " << x << "): " << calc.FuncA(n, x) << std::endl;
    return 0;
}

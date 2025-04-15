#include <iostream>
#include "ShxCalculator.h"

int main() {
    ShxCalculator calc;
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;
    std::cout << "Result for FuncA for " << n << " elements: " << calc.FuncA(n) << std::endl;
    return 0;
}

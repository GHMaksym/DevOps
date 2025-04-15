#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <chrono>
#include "ShxCalculator.h"

int main() {
    ShxCalculator calc;
    auto start = std::chrono::steady_clock::now();

    const int n = 10;
    const int size = 50000;
    std::vector<double> arr;
    for (int i = 0; i < size; ++i)
        arr.push_back(calc.FuncA(n));

    std::sort(arr.begin(), arr.end());

    auto end = std::chrono::steady_clock::now();
    double seconds = std::chrono::duration<double>(end - start).count();

    std::cout << "Execution time: " << seconds << " seconds\n";
    fflush(stdout);
    assert(seconds > 5 && seconds < 20);
    std::cout << "Test passed.\n";
    return 0;
}

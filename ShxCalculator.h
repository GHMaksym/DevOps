#ifndef SHX_CALCULATOR_H
#define SHX_CALCULATOR_H

/**
 * @brief Клас для обчислення гіперболічного синуса sh(x) за рядом Тейлора.
 */
class ShxCalculator {
public:
    /**
     * @brief Обчислює значення гіперболічного синуса sh(x) за рядом Тейлора.
     * @param n Кількість елементів ряду для апроксимації.
     * @param x Точка, в якій обчислюється sh(x).
     * @return Значення функції sh(x), обчислене як сума перших n елементів.
     */
    double FuncA(int n, double x);
};

#endif // SHX_CALCULATOR_H

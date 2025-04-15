#ifndef SHX_CALCULATOR_H
#define SHX_CALCULATOR_H

/**
 * @brief Класс для вычисления гиперболического синуса sh(x) по ряду Тейлора.
 * @note Параметр n определяет количество элементов суммы.
 */
class ShxCalculator {
public:
    /**
     * @param n Количество слагаемых для аппроксимации sh(1).
     * @return Значение гиперболического синуса sh(1) как суммы первых n элементов.
     */
    double FuncA(int n);
};

#endif // SHX_CALCULATOR_H

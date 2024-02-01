#include <iostream>
#include <cmath>

double calculateFactorial(double n);

int main() {
    setlocale(LC_ALL, "Russian");
    bool exit = false;
    while (!exit) {
        std::cout << "Калькулятор" << std::endl;
        std::cout << "Выберите действие:" << std::endl;
        std::cout << "1. Сложить 2 числа" << std::endl;
        std::cout << "2. Вычесть из первое второго" << std::endl;
        std::cout << "3. Перемножить два числа" << std::endl;
        std::cout << "4. Разделить первое на второе" << std::endl;
        std::cout << "5. Возвести в степень N первое число" << std::endl;
        std::cout << "6. Найти квадратный корень из числа" << std::endl;
        std::cout << "7. Найти 1 процент от числа" << std::endl;
        std::cout << "8. Найти факториал из числа" << std::endl;
        std::cout << "9. Выйти из программы" << std::endl;

        int choice;
        std::cin >> choice;

        double number1, number2;
        double result = 0;

        switch (choice) {
        case 1:
        case 2:
        case 3:
        case 4:
            std::cout << "Введите первое число: ";
            std::cin >> number1;
            std::cout << "Введите второе число: ";
            std::cin >> number2;
            switch (choice) {
            case 1:
                result = number1 + number2;
                break;
            case 2:
                result = number1 - number2;
                break;
            case 3:
                result = number1 * number2;
                break;
            case 4:
                if (number2 != 0)
                    result = number1 / number2;
                else
                    std::cout << "Деление на ноль недопустимо." << std::endl;
                break;
            }
            break;
        case 5:
            std::cout << "Введите число: ";
            std::cin >> number1;
            std::cout << "Введите степень: ";
            int exponent;
            std::cin >> exponent;
            result = pow(number1, exponent);
            break;
        case 6:
            std::cout << "Введите число: ";
            std::cin >> number1;
            if (number1 >= 0)
                result = sqrt(number1);
            else
                std::cout << "Извлечение корня из отрицательного числа недопустимо." << std::endl;
            break;
        case 7:
            std::cout << "Введите число: ";
            std::cin >> number1;
            result = number1 * 0.01;
            break;
        case 8:
            std::cout << "Введите число: ";
            std::cin >> number1;
            result = calculateFactorial(number1);
            break;
        case 9:
            exit = true;
            break;
        default:
            std::cout << "Неверный выбор." << std::endl;
            break;
        }

        std::cout << "Результат: " << result << std::endl;
    }

    return 0;
}

double calculateFactorial(double n) {
    if (n < 0) {
        throw std::runtime_error("Факториал отрицательного числа недопустим.");
    }
    if (n == 0) {
        return 1;
    }
    else {
        double result = 1;
        for (int i = 1; i <= n; i++) {
            result *= i;
        }
        return result;
    }
}
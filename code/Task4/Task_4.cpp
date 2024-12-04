#include <iostream>
#include <cmath>

#define PI 3.14159265359

void get_int(int &);
void get_x(double &);
void get_1_or_0(int&);
double my_factorial(double);
double mysin(double, double);

int main()
{
    setlocale(LC_ALL, "Russian");
    int n = 0, accuracy = 0;
    int execute = 0;
    do
    {
        system("clear");
        std::cout << "Необходимо разложить функцию Y(x) из своего варианта в ряд S(x)," << std::endl << "затем с помощью полученного ряда найти значение функции и сравнить его со значением, вычисленным с помощью стандартных функций." <<std::endl;
        std::cout << "Программа должна запросить у пользователя количество членов ряда (n), затем запросить у пользователя количество чисел, от которых он хочет посчитать функцию," << std::endl;
        std::cout << "затем пользователь вводит по одному числу (x от 0.1, до 1), программа считает значение функции с помощью ряда и с помощью стандартных функций и выводит оба значения." << std::endl;
        std::cout << "Выполнил Багаев Леонид" << std::endl;
        std::cout << "Введите количество членов ряда (целое положительное число)" << std::endl;
        get_int(accuracy);
        std::cout << "Введите количество чисел (целое положительное число)" << std::endl;
        get_int(n);
        std::cout << "Введите числа (от 0.1 до 1 включительно)" << std::endl;
        double *numbers = new double[n];
        for (double *q = numbers; q != numbers + n; ++q)
        {
            static int i = 0;
            get_x(numbers[i]);
            ++i;
        }
        for (int i = 0; i < n; ++i)
        {
            std::cout << sin(numbers[i]) << '\t' << mysin(numbers[i], accuracy) << std::endl;
        }
        delete[] numbers;
        std::cout << "Чтобы повторить выполнение программы, введите 1" << std::endl << "Чтобы завершить выполнение программы, введите 0" << std::endl;
        get_1_or_0(execute);
    } while (execute == 1);
}

void get_1_or_0(int& x){
    x = 0;
    while(1){
        std::cin >> x;
        if(std::cin.fail() || (x != 1 && x != 0) ){
            std::cout << "Неверный ввод! Попробуйте ещё раз" << std::endl;
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            x = 0;
        } else {
            break;
        };
    };
}

void get_int(int &x)
{
    x = 0;
    while (1)
    {
        std::cin >> x;
        if (std::cin.fail() || x <= 0)
        {
            std::cout << "Неверный ввод! Попробуйте ещё раз" << std::endl;
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            x = 0;
        }
        else
        {
            break;
        };
    };
}

void get_x(double &x)
{
    x = 0;
    while (1)
    {
        std::cin >> x;
        if (std::cin.fail() || x < 0.1 || x > 1)
        {
            std::cout << "Неверный ввод! Попробуйте ещё раз" << std::endl;
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            x = 0;
        }
        else
        {
            break;
        };
    };
}

double my_factorial(double n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * my_factorial(n - 1);
}

double mysin(double x, double n)
{
    double result = x;
    for (int i = 1; i < n; ++i)
    {
        double term = pow(x, 2 * i + 1) / my_factorial(2 * i + 1);
        if (i % 2 == 1)
        {
            result -= term;
        }
        else
        {
            result += term;
        }
    }
    return result;
}
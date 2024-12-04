#include <iostream>
#define PI 3.14159265359

const double M = 20;
const double A = 0;
const double B = PI / 2;
const double H = (B - A) / M;


void get_1_or_0(int&);
double pow(double, double);
double dabs(double);
double factorial(double);
double sign(double);
double sin(double);
double cos(double);

int main()
{
    setlocale(LC_ALL, "Russian");
    int execute = 1;
    do
    {
        system("clear");
        std::cout << "Использую цикл for составить программу вычисления значений функции y = sin(x) - cos(x)" << std::endl;
        std::cout << "на отрезке [A, B] в точках Xi = A + i * H, где H = (B - A) / M, M = 20, A = 0, B = π / 2." << std::endl;
        std::cout << "Выполнил Багаев Леонид" << std::endl;
        double x = 0, y = 0;
        for (int i = 0; 1; ++i)
        {
            x = A + i * H;
            if (x > B)
            {
                break;
            }
            if (x == PI / 4)
            {
                std::cout << "0" << std::endl;
                continue;
            }
            y = sin(x) - cos(x);
            std::cout << y << std::endl;
        };
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

double dabs(double x)
{
    if (x >= 0)
    {
        return x;
    }
    else
    {
        return -x;
    }
}

double factorial(double n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

double pow(double x, double y)
{
    double res = 1;
    if (y >= 0)
    {
        for (int i = 0; i < y; ++i)
        {
            res = res * x;
        };
    }
    else
    {
        for (int i = 0; i < dabs(y); ++i)
        {
            res = (res) * (1 / x);
        };
    }

    return res;
}
double sign(double x)
{
    if (x > 0)
    {
        return 1;
    }
    else if (x < 0)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

double sin(double x)
{
    while (dabs(x) > (2 * PI))
    {
        x -= sign(x) * 2 * PI;
    }
    double result = x;
    for (int i = 1; i < 8; ++i)
    {
        double term = pow(x, 2 * i + 1) / factorial(2 * i + 1);
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

double cos(double x)
{
    while (dabs(x) > (2 * PI))
    {
        x -= sign(x) * 2 * PI;
    }
    double result = 1;
    for (int i = 1; i < 8; ++i)
    {
        double term = pow(x, 2 * i) / factorial(2 * i);
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
#include <iostream>

void get_1_or_0(int&);
void get_int(int &);
double pow(double, double);
double dabs(double);
double factorial(double);
double sin(double);
double cos(double);
double arctg(double);

int main()
{
    setlocale(LC_ALL, "Russian");
    int execute = 0;
    do
    {
        system("clear");
        int step_num;
        std::cout << "Необходимо приближенно найти корень уравнения f(x) = 0 для функции из своего варианта." << std::endl;
        std::cout << "Корень нужно найти по следующему алгоритму: перебираем значения от начала до конца интервала с некоторым шагом и ищем значение функции, минимальное по модулю." << std::endl;
        std::cout << "Аргумент, при котором оно достигается, считаем корнем уравнения." << std::endl;
        std::cout << "Программа должна запросить у пользователя, на сколько частей разделить область поиска корня," << std::endl << "вычислить шаг, с которым нужно проходить значения, пройти в цикле нужные значения, найти корень и вывести его." << std::endl;
        std::cout << "Выполнил Багаев Леонид" << std::endl << "Вариант 1" << std::endl;
        std::cout << "Введите колисество частей, на которые нужно разбить интервал (целое положительное число)" << std::endl;
        get_int(step_num);
        double step = (double)1 / step_num;
        double min = 100;
        for (double x = 0; x <= 1; x += step)
        {
            double result = sin(x) + cos(x) - 2 * arctg(x);
            if (dabs(result) < dabs(min))
            {
                min = result;
            }
        }
        std::cout << min << std::endl;
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

double sin(double x)
{
    double result = x;
    for (int i = 1; i < 16; ++i)
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
    double result = 1;
    for (int i = 1; i < 16; ++i)
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

double arctg(double x)
{
    double result = x;
    for (int i = 1; i < 16; ++i)
    {
        double term = pow(x, 2 * i + 1) / (2 * i + 1);
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
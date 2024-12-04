#include <iostream>

#include <iostream>
#include <iomanip>
#include <cmath>

const long double my_pi = 3.14159265358979323846;
const long double my_log10 = 2.302585092994045684017;

void get_double(long double&);
void get_1_or_0(int&);
int normalize(long double &x, long double left, long double right);
long double my_abs(long double x);
long double my_sqrt(long double x);
long double my_sin(long double x);
long double my_cos(long double x);
long double my_ln(long double x);

int main()
{
    int execute = 0;
    do
    {
        system("clear");
        std::cout << "Задание 6\n _____________________________________________________________________________ \n";
        std::cout << " |                                                                           | \n";
        std::cout << " |  Из величин, определяемых выражениями a = sinx, b = cosx, c = ln|x| при   | \n";
        std::cout << " |  заданном х, определить и вывести на экран дисплея минимальное значение.  | \n";
        std::cout << " |  Использование стандартных математических методов запрещено.              | \n";
        std::cout << " |                                                                           | \n";
        std::cout << " —————————————————————————————————————————————————————————————————————————————\n\n";
        std::cout << "Выполнил Багаев Леонид\n\n";
        long double x;
        std::cout << "Введите x: ";
        get_double(x);

        long double (*func[4])(long double) = {};
        func[0] = &my_cos;
        func[1] = &my_sin;
        func[2] = &my_ln;
        func[3] = &my_abs;

        std::cout << std::setprecision(15);
        std::cout << "Значение, посчитанное рядом Тейлора: my_cos(" << x << ") = " << func[0](x) << '\n';
        std::cout << "Значение, посчитанное cmath: cos(" << x << ") = " << cos(x) << '\n';
        std::cout << "Значение, посчитанное рядом Тейлора: my_sin(" << x << ") = " << func[1](x) << '\n';
        std::cout << "Значение, посчитанное cmath: sin(" << x << ") = " << sin(x) << '\n';
        std::cout << "Значение, посчитанное рядом Тейлора: my_ln(" << my_abs(x) << ") = " << func[2](x) << '\n';
        std::cout << "Значение, посчитанное cmath: log(" << func[3](x) << ") = " << log(func[3](x)) << '\n';

        std::cout << "Чтобы повторить выполнение программы, введите 1" << std::endl
                  << "Чтобы завершить выполнение программы, введите 0" << std::endl;
        get_1_or_0(execute);
    } while (execute == 1);

    return 0;
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

void get_double(long double &x)
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

int normalize(long double &x, long double left, long double right)
{
    int k = 0;
    while (x<left && x> right)
    {
        x /= 2;
        k++;
    }
    return k;
}

long double my_abs(long double x)
{
    return (x < 0) ? (-x) : x;
}

long double my_sqrt(long double x){
    const double eps = 1e-5;
    double res = 1;
    while (my_abs(res*res - x) > eps){ 
        res = (res + x/ res) / 2;
    };
    return res;
}

long double my_cos(long double x)
{
    long double result = 0, T, n = 1;
    int k;
    k = normalize(x, (-0.5) * my_pi, 0.5 * my_pi);
    T = 1;
    for (int i = 1; i < 19; i++)
    {
        result += (-1 + (i % 2) * 2) * T;
        T *= x * x / (n * (n + 1));
        n += 2;
    }
    for (int i = 0; i < k; i++)
    {
        result = 2 * result * result - 1;
    }

    return result;
}

long double my_sin(long double x)
{
    long double result = 0;
    if (x < 1e-7 && x > 0)
    {
        result = x;
    }
    else
    {
        long double T, n = 2;
        int k;
        k = normalize(x, -my_pi, my_pi);
        T = x;
        for (int i = 1; i < 19; i++)
        {
            result += (-1 + (i % 2) * 2) * T;
            T *= x * x / (n * (n + 1));
            n += 2;
        }
        for (int i = 0; i < k; i++)
        {
            result = 2 * result * cos(x);
            x *= 2;
        }
    }
    return result;
}

long double my_ln(long double x)
{
    x = my_abs(x);
    int count = 0, sign = 1;
    long double result = 0, T = 1;
    if (x < 1)
    {
        x = 1 / x;
        sign = -1;
    }
    while (x > 2)
    {
        x /= 10;
        ++count;
    }
    for (int i = 1; i < 20; ++i)
    {
        T = pow(x-1, i)/i;
        //T *= (x - 1) / i;
        result += (1 - (i % 2) * 2) * T;
    }
    for (int i = 0; i < count; ++i)
    {
        result += my_log10;
    }
    return sign * result;
}
#include <iostream>
#include <cmath>

void get_1_or_0(int&);
void get_int(int&);

int main () {
    int execute = 0;
    do {
        system("clear");
        std::cout << "Вычислить а0 -2a1 + 4*a2 - 8*a3 ... + 2^(n-1) * (-1)^(n-1) * an-1" << std::endl;
        std::cout << "Выполнил Багаев Леонид" << std::endl;
        int a = 0;
        std::cout << "Введите целое число a" << std::endl;
        get_int(a);
        int n = 0;
        std::cout << "Введите количество слагаемых" << std::endl;
        get_int(n);
        int res = 0;
        for(int i = 1; i <= n; ++i){
            res = res + pow(2, n-1) * pow(-1, n-1)* a;
        }
        std::cout << res << std::endl;
        std::cout << "Чтобы повторить выполнение программы, введите 1" << std::endl << "Чтобы завершить выполнение программы, введите 0" << std::endl;
        get_1_or_0(execute);
    } while(execute == 1);
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
        if (std::cin.fail())
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
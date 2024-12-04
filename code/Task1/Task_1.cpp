#include <iostream>

void get_1_or_0(int&);

int main () {
    setlocale(LC_ALL, "Russian");
    int execute = 1;
    do{
        std::system("clear");
        std::cout << "Используя цикл while вычислить N = ∑(i=1, n=30) (ai - bi)^2, где a и b определены по формуле:" << std::endl << "ai = i, если i нечётное(i/2 , если i чётное) bi = i^2, если i нечётное(i/3, если i чётное)"<< std::endl;
        std::cout << "Выполнил Багаев Леонид" << std::cout;
        double result = 0;
        double a = 0, b = 0;
        for (int i = 1; i <=30; ++i){
            a = (i%2) == 1 ? i : i/2;
            b = (i%2) == 1 ? i*i : i*i*i;
            result += (a-b)*(a-b);
    }
        std::cout << result << std::endl << std::endl;
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
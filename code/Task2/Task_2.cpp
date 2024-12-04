#include <iostream>

void get_1_or_0(int&);
double dabs(double);
double pow(double,double);


double E = pow(10, -3);

int main () {
    setlocale(LC_ALL, "Russian");
    int execute = 1;
    do{
        system("clear");
        std::cout << "Используя цикл do while найти сумму ряда с точностью ε = 10^(-3), общий член которого dn =1/2^n + 1/3^n." << std::endl;
        std::cout << "При составлении программы считать, что точность достигнута, если dn < ε" << std::endl;
        double result = 0;
        double d;
        double i = 0;
        do {
            d = (1/pow(2,i)) + (1/pow(3,i));
            ++i;
    } 
        while (d >= E);
        std::cout << d << std::endl;
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

double dabs(double x){
    if (x >= 0){
        return x;
    } else {
        return -x;
    }
}

double pow(double x, double y){
    double res = 1;
    if(y >=0){
        for (int i = 0; i < y; ++i){
        res = res*x;
        };
    } else {
        for (int i = 0; i < dabs(y); ++i){
        res = (res) * (1/x);
        };
    }
    
    return res;
}
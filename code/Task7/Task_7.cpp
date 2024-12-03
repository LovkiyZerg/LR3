#include <iostream>
#include <cmath>


void get_double(double&);

int main() {
    setlocale(LC_ALL, "Russian");
    double x = 0;
    std::cout << "Введите число, до которого считать числа Армстронга (положительное число)" << std::endl;
    get_double(x);
    for(int i = 1; i <= x; ++i){
        int num = i;
        int num2 = i;
        int result = 0;
        int e = 0;
        while(num>0){
            e += 1;
            num = num/10;
        };
        while(num2 > 0){
            result += pow(num2%10,e); 
            num2 = num2/10;
        };
        if(i<10){
            result = i;
        };
        if(result == i){
            std::cout << i << std::endl;
        };
    };
    return 0;
}


void get_double(double& x){
    x = 0;
    while(1){
        std::cin >> x;
        if(std::cin.fail() || x <= 0){
            std::cout << "Неверный ввод! Попробуйте ещё раз" << std::endl;
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            x = 0;
        } else {
            break;
        };
    };
}
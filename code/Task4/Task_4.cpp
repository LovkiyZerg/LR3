#include <iostream>
#include <cmath>

#define PI 3.14159265359

void get_int(int&);
void get_x(double&);
double my_factorial(double);
double mysin(double, double);


int main () {
    setlocale(LC_ALL, "Russian");
    int n = 0, accuracy = 0;
    std::cout << "Введите количество членов ряда (целое положительное число)" << std::endl;
    get_int(accuracy);
    std::cout << "Введите количество чисел (целое положительное число)" << std::endl;
    get_int(n);
    std::cout << "Введите числа (от 0.1 до 1 включительно)" << std::endl;
    double *numbers = new double[n];
    for(double *q = numbers; q != numbers + n; ++q){
        static int i = 0;
        get_x(numbers[i]);
        ++i;
    }
    for (int i = 0; i < n; ++i){
        std::cout << sin(numbers[i]) << '\t' << mysin(numbers[i], accuracy) << std::endl;
    }
    delete [] numbers;

}

void get_int(int& x){
    x = 0;
    while(1){
        std::cin >> x;
        if(std::cin.fail() || x <=0){
            std::cout << "Неверный ввод! Попробуйте ещё раз" << std::endl;
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            x = 0;
        } else {
            break;
        };
    };
}

void get_x(double& x){
    x = 0;
    while(1){
        std::cin >> x;
        if(std::cin.fail() || x < 0.1 || x > 1 ){
            std::cout << "Неверный ввод! Попробуйте ещё раз" << std::endl;
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            x = 0;
        } else {
            break;
        };
    };
}

double my_factorial(double n){
    if(n == 0){
        return 1;
    }
    return n * my_factorial(n-1);
}

double mysin(double x, double n){
    double result = x;
    for(int i = 1; i < n; ++i){
        double term = pow(x, 2*i+1)/my_factorial(2*i+1);
        if (i%2 == 1){
            result -= term;
        } else { 
            result += term;
        }
    }
    return result;
}
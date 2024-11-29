#include <iostream>
#include <cmath>

#define PI 3.14159265359

double mysin(double, double);

int main () {
    int n, accuracy;
    std::cin >> accuracy >> n;
    double *numbers = new double[n];
    for(double *q = numbers; q != numbers + n; ++q){
        static int i = 0;
        std::cin >> numbers[i];
        ++i;
    }
    for (int i = 0; i < n; ++i){
        std::cout << sin(numbers[i]) << '\t' << mysin(numbers[i], accuracy) << std::endl;
    }
}

double factorial(double n){
    if(n == 0){
        return 1;
    }
    return n * factorial(n-1);
}

double mysin(double x, double n){
    double result = x;
    for(int i = 1; i < n; ++i){
        double term = pow(x, 2*i+1)/factorial(2*i+1);
        if (i%2 == 1){
            result -= term;
        } else {
            result += term;
        }
    }
    return result;
}
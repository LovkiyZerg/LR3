#include <iostream>

double pow(double, double);
double dabs(double);
double factorial(double);
double sin(double);
double cos(double);
double arctg(double);


int main () {
    int step_num;
    std::cin >> step_num;
    double step = (double)1 / step_num;
    double min = 100; 
    for(double x = 0; x <= 1; x += step){
        double result = sin(x) + cos(x) - 2 * arctg(x);
        if (dabs(result) < dabs(min)){
            min = result;
        }
    }
    std::cout << min;
    return 0;
}

double dabs(double x){
    if (x>=0){
        return x;
    } else {
        return -x;
    }
}

double factorial(double n) {
  if (n == 0) {
    return 1;
  }
  return n * factorial(n - 1);
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

double sin(double x){
    double result = x;
    for(int i = 1; i < 16; ++i){
        double term = pow(x, 2*i+1)/factorial(2*i+1);
        if (i%2 == 1){
            result -= term;
        } else { 
            result += term;
        }
    }
    return result;
}

double cos(double x){
    double result = 1;
    for(int i = 1; i < 16; ++i){
        double term = pow(x, 2*i)/factorial(2*i);
        if (i%2 == 1){
            result -= term;
        } else { 
            result += term;
        }
    }
    return result;
}

double arctg(double x){
    double result = x;
    for(int i = 1; i < 16; ++i){
        double term = pow(x, 2*i+1)/(2*i + 1);
        if (i%2 == 1){
            result -= term;
        } else { 
            result += term;
        }
    }
    return result;
}
#include <iostream>

double dabs(double);
double pow(double,double);


double E = pow(10, -3);

int main () {
    double result = 0;
    double d;
    double i = 0;
    do {
        d = (1/pow(2,i)) + (1/pow(3,i));
        ++i;
    } 
    while (d >= E);
    std::cout << d;

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
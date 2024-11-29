#include <iostream>

int main () {
    double result = 0;
    double a = 0, b = 0;
    for (int i = 1; i <=30; ++i){
        a = (i%2) == 1 ? i : i/2;
        b = (i%2) == 1 ? i*i : i*i*i;
        result += (a-b)*(a-b);
    }
    std::cout << result;
}
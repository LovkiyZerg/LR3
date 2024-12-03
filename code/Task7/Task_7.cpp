#include <iostream>


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


int main() {
    int x = 0;
    std::cin >> x;
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
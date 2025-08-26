#include <stdio.h>
#include <limits.h>


int reverse(int x){
    int res = 0;
    int digit;

    while(x != 0) {
        digit = x%10;
        x /= 10;
        if (res > INT_MAX/10 || (res == INT_MAX/10 && digit > 7)) {return 0;}
        if (res < INT_MIN/10 || (res == INT_MIN/10 && digit < -8)) {return 0;} 
        res = res*10 + digit;
    }
    return res;
}
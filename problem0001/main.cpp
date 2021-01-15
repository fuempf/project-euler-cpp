// problem 1
// If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
// Find the sum of all the multiples of 3 or 5 below 1000.
#include <iostream>

int main(){
    int sum = 0;
    int multiplier = 1;
    while(true){
        int m5 = multiplier*5;
        int m3 = multiplier*3;
        if(m3 >= 1000) break;
        if(m5 < 1000) sum += m5;
        if(m3 % 5 != 0) sum += m3;
        multiplier++;
    }
    std::cout << sum << std::endl;
    return 0;
}
// A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
// Find the largest palindrome made from the product of two 3-digit numbers.
#include <string>
#include <chrono>
#include <iostream>

typedef long long int lli;

bool is_palindrome(lli n){
    std::string nstr = std::to_string(n);
    int size = nstr.size();
    for(int i = 0; i < size/2; i++){
        if(nstr[i] != nstr[size-1-i]) return false;
    }
    return true;
}


int main(){
    auto start = std::chrono::high_resolution_clock::now();

    int biggest = 0;

    for(int i = 999; i > 99; i--){
        for(int j = 999; j > 99; j--){
            int num = i*j;
            if(num > biggest && is_palindrome(i*j)) biggest = num;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "result: " << biggest << std::endl;
    std::cout << "time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;

    return 0;
}
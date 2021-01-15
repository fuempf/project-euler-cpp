// The sum of the squares of the first ten natural numbers is,
// 1² + 2² + ... + 10² = 385
//
// The square of the sum of the first ten natural numbers is,
// (1 + 2 + ... + 10)² = 55² = 3025
//
// Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is
// 3025 - 385 = 2640
//
// Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

#include <chrono>
#include <iostream>

typedef long long int lli;

int main(){
    auto start = std::chrono::high_resolution_clock::now();

    lli sum_of_squares = 0;
    lli sum = 0;
    for(int i = 1; i <= 100; i++){
        sum += i;
        sum_of_squares += i*i;
    }
    
    lli result = sum*sum - sum_of_squares;

    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "result: " << result << std::endl;
    std::cout << "time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;

    return 0;
}
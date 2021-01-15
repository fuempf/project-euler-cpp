// A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
// a² + b² = c²
// For example, 3² + 4² = 9 + 16 = 25 = 5².
// There exists exactly one Pythagorean triplet for which a + b + c = 1000.
// Find the product abc.


#include <chrono>
#include <iostream>
#include <cmath>

int main(){
    auto start = std::chrono::high_resolution_clock::now();

    int result = -1;
    int a = 1;
    int b = 1;
    while(result < 0){
        double c = std::sqrt(a*a+b*b);
        if(std::floor(c) == c){ // <- checking if c is an integer
            if(a+b+c == 1000){
                result = a*b*c;
            }
        }
        if(a+b+c < 1000) b++;
        else{
            a++;
            b = 1;
        }
    }
    
    int max_c = 1000-a-b;
    





    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "result: " << result << std::endl;
    std::cout << "time: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "ms" << std::endl;

    return 0;
}
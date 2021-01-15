// 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
// What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

#include <chrono>
#include <iostream>

typedef long long int lli;

int main(){
    auto start = std::chrono::high_resolution_clock::now();

    bool found;
    lli result = -1;
    lli current = 20;
    while(result < 0){
        found = true;
        for(int i = 2; i <= 20; i++){
            if(current % i != 0){
                found = false;
                break;
            }
        }
        if(found){
            result = current; 
            break;
        }else current+=20;
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "result: " << result << std::endl;
    std::cout << "time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;

    return 0;
}
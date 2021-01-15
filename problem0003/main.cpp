// The prime factors of 13195 are 5, 7, 13 and 29.
// What is the largest prime factor of the number 600851475143 ?

#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>
#include <chrono>

typedef long long int lli;

std::vector<lli> calculate_primes_up_to(lli limit){
    // vector for primes
    std::vector<lli> primes;
    std::unordered_set<lli> not_primes;
    not_primes.insert(0);
    not_primes.insert(0);
    for(lli i = 2; i < limit; i++){
        // continue if already marked as not prime
        if(not_primes.find(i) != not_primes.end()) continue;
        //push new prime 
        primes.push_back(i);
        //mark all non primes
        for(lli j = 2; j*i < limit; j++){
            not_primes.insert(i*j);
        }
    }
    return primes;
}


int main(){
    auto start = std::chrono::high_resolution_clock::now();
    lli num = 600851475143;
    // calculate primes up to sqrt(num) <- sqrt(num) = biggest possible factor of num
    std::vector<lli> primes = calculate_primes_up_to(std::sqrt(num));
    
    //find the biggest prime factor of num
    lli result = -1;
    for(lli i = primes.size()-1; i >= 0; i--){
        if(num % primes[i] == 0){
            result = primes[i];
            break;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "result: " << result << std::endl;
    std::cout << "time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;
 
    return 0;
}

// By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
// What is the 10 001st prime number?

#include <chrono>
#include <vector>
#include <iostream>
#include <cmath>

typedef long long int lli;

std::vector<lli> calculate_primes_up_to(lli limit){
    // vector for primes
    std::vector<lli> primes;
    bool not_primes[limit];
    for(int i = 0; i < limit; i++) not_primes[i] = false;
    not_primes[0] = true;
    not_primes[1] = true;
    for(lli i = 2; i < limit; i++){
        // continue if already marked as not prime
        if(not_primes[i]){
            continue;
        } 
        //push new prime 
        primes.push_back(i);

        //mark all non prime
        for(lli j = 2; j*i < limit; j++){
            not_primes[i*j] = true;
        }
    }
    return primes;
}


std::vector<lli> calculate_n_primes(lli n){
    // upper bound for nth prime is: n(ln(n)+ln(ln(n)))
    lli limit = n * (std::log(n) + std::log(std::log(n)));
    return calculate_primes_up_to(limit);
}


int main(){
    auto start = std::chrono::high_resolution_clock::now();
   
    int n = 10001;
    int result = -1;
    std::vector<lli> primes = calculate_n_primes(n);
    std::cout << "calculated " << primes.size() << " primes" << std::endl;
    //just making sure the nth prime was calculated...
    if(primes.size() > n) result = primes[n-1]; // starts with 0 so, index n-1 is nth prime 
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "result: " << result << std::endl;
    std::cout << "time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;

    return 0;
}


// The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
// Find the sum of all the primes below two million.

#include <chrono>
#include <iostream>
#include <list>

typedef long long int lli;

std::list<lli> calculate_primes_up_to(lli limit){
    // vector for primes
    std::list<lli> primes;
    bool not_primes[limit] = {0};
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

int main(){
    auto start = std::chrono::high_resolution_clock::now();

    std::list<lli> primes = calculate_primes_up_to(2000000);
    lli result = 0;
    for(lli p: primes) result+=p;

    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "result: " << result << std::endl;
    std::cout << "time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;

    return 0;
}
/*

The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.

*/


#include <chrono>
#include <iostream>
#include <unordered_map>

typedef long llui;

llui next_in_chain(llui n){
    if(n % 2 == 0) return n/2;
    else return 3*n+1;
}

llui chain_length_array[1000000] = {0};

llui get_chain_length(llui n){
    if(n < 1000000 && chain_length_array[n] != 0) return chain_length_array[n];
    else{
        int len = get_chain_length(next_in_chain(n))+1;
        if(n < 1000000) chain_length_array[n] = len;
        return len;
    }
}

int main(){
    auto start = std::chrono::high_resolution_clock::now();

    chain_length_array[1] = 1; // chain of 1 is 1 long (only itself)
    llui maxlength = 1;
    llui maxnumber = 1;
    for(int i = 2; i < 1000000; i++){
        llui tmp = get_chain_length(i);
        if(tmp > maxlength){
            maxlength = tmp;
            maxnumber = i;
        }
        
    }

    std::string result = "The number under 1000000 with the longest chain is: " + std::to_string(maxnumber) + ", chain length: " + std::to_string(maxlength);


    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "result: " << result << std::endl;
    std::cout << "time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;

    return 0;
}
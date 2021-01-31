// 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

// What is the sum of the digits of the number 2^1000?
#include <chrono>
#include <iostream>
#include <cmath>
#include <limits>

int main(){
    auto start = std::chrono::high_resolution_clock::now();

    double numraw = std::pow(2,1000);
    std::string num = std::to_string(numraw);
    num = num.substr(0,num.find('.'));
    int result = 0;
    for(int i = 0; i < num.size(); i++){
        result += std::stoi(num.substr(i,1));
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "result: " << result << std::endl;
    std::cout << "time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;

    return 0;
}
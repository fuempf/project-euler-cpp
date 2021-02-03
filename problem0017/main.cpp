// If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

// If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

// NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. 
// The use of "and" when writing out numbers is in compliance with British usage.


#include <chrono>
#include <iostream>

int get_digit_string_len(int n){
    switch (n){
        case 0: return 0;   // no len for zero 
        case 1: return 3;   // "one"
        case 2: return 3;   // "two"
        case 3: return 5;   // "three"
        case 4: return 4;   // "four"
        case 5: return 4;   // "five"
        case 6: return 3;   // "six"
        case 7: return 5;   // "seven"
        case 8: return 5;   // "eight"
        case 9: return 4;   // "nine"
        default:
            std::cerr << "illegal digit " << n << std::endl;
            return 0;
    }
}

int get_num_str_len_upto_99(int n){
    if(n < 10) return get_digit_string_len(n);
    if(n >= 90) return 5+get_digit_string_len(n-90); // "ninety" + last digit
    if(n >= 80) return 6+get_digit_string_len(n-80); // "eighty" + last digit
    if(n >= 70) return 7+get_digit_string_len(n-70); // "seventy" + last digit
    if(n >= 60) return 5+get_digit_string_len(n-60); // "sixty" + last digit
    if(n >= 50) return 5+get_digit_string_len(n-50); // "fifty" + last digit
    if(n >= 40) return 6+get_digit_string_len(n-40); // "fourty" + last digit
    if(n >= 30) return 6+get_digit_string_len(n-30); // "thirty" + last digit
    if(n >= 20) return 6+get_digit_string_len(n-20); // "twenty" + last digit
    switch(n){
        case 19: return 8; // "nineteen"
        case 18: return 8; // "eighteen"
        case 17: return 9; // "seventeen"
        case 16: return 7; // "sixteen"
        case 15: return 7; // "fifteen"
        case 14: return 8; // "fourteen"
        case 13: return 8; // "thirteen"
        case 12: return 6; // "twelve"
        case 11: return 6; // "eleven"
        case 10: return 3; // "ten"
        default:
            std::cerr << "illegal number " << n << std::endl;
            return 0;
    }
}

int get_num_str_len_upto_999(int n){
    int result = get_digit_string_len((n - (n % 100)) / 100); // first digit of the triple digit number
    if(result > 0) result += 7; // "hundred" only if n > 99  
    int dn = get_num_str_len_upto_99(n % 100); // the following two digit number
    if(result > 0 && dn > 0) result += 3; // "and"
    if(dn > 0) result += dn; // adding digits
    return result;
}

int get_num_str_len_upto_1000(int n){
    if(n > 1000){
        std::cerr << "number larger than 1000" << std::endl;
    }
    if(n == 1000) return 11; // simplest solution for thousand
    else return get_num_str_len_upto_999(n);
}


int main(){
    auto start = std::chrono::high_resolution_clock::now();

    int result = 0;
    for(int i = 1; i < 1001; i++){
        result += get_num_str_len_upto_1000(i);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "result: " << result << std::endl;
    std::cout << "time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;

    return 0;
}
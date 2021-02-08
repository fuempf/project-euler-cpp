// You are given the following information, but you may prefer to do some research for yourself.

// 1 Jan 1900 was a Monday.
// Thirty days has September,
// April, June and November.
// All the rest have thirty-one,
// Saving February alone,
// Which has twenty-eight, rain or shine.
// And on leap years, twenty-nine.
// A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
// How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

#include <chrono>
#include <iostream>
#include <cassert>

bool isLeapYear(int year){
    if(year % 4 != 0)   return false;
    if(year % 100 != 0) return true;
    if(year % 400 == 0) return true;
    return false;
}

int getMonthLength(int month, int year){ //month = 0-11
    assert(month >= 0 && month <= 11);
    switch(month){
        case 3:
        case 5:
        case 8:
        case 10:
            return 30;
        case 1:
            return isLeapYear(year)?29:28;
        default: 
            return 31;
    }
}

enum dayofweek{
    MON,
    TUE,
    WED,
    THU,
    FRI,
    SAT,
    SUN
};

dayofweek nextDayOfWeek(dayofweek currentDay){
    if(currentDay == SUN) return MON;
    else return (dayofweek)(((int)currentDay)+1);
}

dayofweek calculateDayOfWeekIn(dayofweek currentDay, int days){
    dayofweek wd = currentDay;
    for(int i = 0; i < days % 7; i++){
        wd = nextDayOfWeek(wd);
    }
    return wd;
}

int main(){
    auto start = std::chrono::high_resolution_clock::now();

    int result = 0;
    int year = 1901;
    //calculate weekday of 1st Jan 1901, knowing that 1st Jan 1900 was a monday
    dayofweek wd = calculateDayOfWeekIn(MON, isLeapYear(1900)?366:365);  
    while(year < 2001){
        for(int month = 0; month < 12; month++){
            if(wd == SUN) result++;
            wd = calculateDayOfWeekIn(wd, getMonthLength(month, year));
        }
        year++;
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "result: " << result << std::endl;
    std::cout << "time: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "μs" << std::endl;

    return 0;
}
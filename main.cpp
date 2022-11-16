#include <iostream>
#include "funcs.h"

int main(){
    Time time = {25, 30};
    std::cout << minutesSinceMidnight(time) << std::endl;
    std::cout << minutesUntil({14, 30}, {13, 40}) << std::endl;
    std::cout << (addMinutes({8, 10}, 75)).m;
    return 0;
}
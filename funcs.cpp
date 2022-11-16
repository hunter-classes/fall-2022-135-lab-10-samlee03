#include <iostream>
#include "time.h"

//Task A
int minutesSinceMidnight(Time time){
    int midnightHour = 24;
    int midnightMinute = 0;
    if (time.m != 0){
        midnightMinute += 60;
        midnightHour -= 1; // Add 1 hour to 60 minutes
    }
    int mins = ((midnightHour - time.h) * 60) + (midnightMinute - time.m); // Hours
     
    return mins;
}
int minutesUntil(Time earlier, Time later){
    int laterHour = later.h;
    int laterMinute = later.m;
    if (earlier.m > later.m){
        laterHour -= 1;
        laterMinute += 60;
    }
    int mins = ((laterHour - earlier.h) * 60) + (laterMinute - earlier.m);
    return mins;
}

//Task B
Time addMinutes(Time time0, int min){
    int additionalHour = 0;
    while (min > 59){
        additionalHour++;
        min -= 60;
    }
    return {time0.h + additionalHour, time0.m + min};
}
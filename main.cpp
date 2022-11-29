#include <iostream>
#include "funcs.h"

int main(){
    Time time = {25, 30};
    // std::cout << minutesSinceMidnight(time) << std::endl;
    // std::cout << minutesUntil({14, 30}, {13, 40}) << std::endl;
    // std::cout << (addMinutes({8, 15}, 116)).m << std::endl;
    // printMovie()
    Movie movie = {"Back to the Future", COMEDY, 116};
    Time time_start = {9, 15};
    TimeSlot ts = {movie, time_start};
    std::cout << getTimeSlot(ts) << std::endl;

    movie = {"Black Panther", ACTION, 134};
    time_start = {12, 15};
    ts = {movie, time_start};
    std::cout << getTimeSlot(ts) << std::endl;

    movie = {"Test Movie", ROMANCE, 120};
    time_start = {14, 10};
    ts = {movie, time_start};

    Movie next_movie = {"Test Movie: Sequel", ROMANCE, 10};
    std::cout << getTimeSlot(scheduleAfter(ts, next_movie)) << std::endl;
    time_start = {16, 15};
    TimeSlot ts1 = {movie, time_start};
    
    std::cout << getTimeSlot(ts1) << std::endl;
    TimeSlot ts2 = scheduleAfter(ts, next_movie);
    std::cout << timeOverlap(ts1, ts2);
    return 0;
    
}
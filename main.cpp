#include <iostream>
#include "funcs.h"

int main(){
    Time time = {1, 30};
    
    std::cout << "Minutes since midnight of 1:30 = " << minutesSinceMidnight(time) << std::endl;
    std::cout << "Minutes until 13:40 from 10:30 = " << minutesUntil({10, 30}, {13, 40}) << std::endl << std::endl;
    std::cout << "Adding 116 minutes to 8:15 = " <<(addMinutes({8,15}, 116)).h << ":" << (addMinutes({8, 15}, 116)).m << std::endl << std::endl;
    // printMovie()
    Movie movie = {"Back to the Future", COMEDY, 116};
    Time time_start = {9, 15};
    TimeSlot ts = {movie, time_start};
    std::cout << getTimeSlot(ts) << std::endl;

    movie = {"Knives Out", THRILLER, 179};
    time_start = {10, 20};
    ts = {movie, time_start};
    std::cout << getTimeSlot(ts) << std::endl;

    movie = {"Black Panther", ACTION, 134};
    time_start = {12, 15};
    ts = {movie, time_start};
    std::cout << getTimeSlot(ts) << std::endl;

    movie = {"Test Movie", ROMANCE, 120};
    time_start = {14, 10};
    ts = {movie, time_start};
    std::cout << getTimeSlot(ts) << std::endl;

    Movie next_movie = {"Test Movie: Sequel", ROMANCE, 10};
    std::cout << getTimeSlot(scheduleAfter(ts, next_movie)) << std::endl << std::endl;
    time_start = {16, 15};
    TimeSlot ts1 = {movie, time_start};
    
    // std::cout << getTimeSlot(ts1) << std::endl;
    TimeSlot ts2 = scheduleAfter(ts, next_movie);
    std::cout << "timeOverlap? (TimeSlot 1 and 2): " << timeOverlap(ts1, ts2) << std::endl;
    return 0;
}
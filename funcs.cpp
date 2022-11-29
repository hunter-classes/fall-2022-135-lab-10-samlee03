#include <iostream>
#include <string>
#include "time.h"
#include "movie.h"
#include "timeslot.h"

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
    min += time0.m;
    while (min > 59){
        additionalHour++;
        min -= 60;
    }
    return {time0.h + additionalHour, min};
}

//Task C
// enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER}
std::string printMovie(Movie mv){
    std::string g;
    switch (mv.genre) {
        case ACTION: g = "ACTION"; break;
        case COMEDY: g = "COMEDY"; break;
        case DRAMA: g = "DRAMA"; break;
        case ROMANCE: g = "ROMANCE"; break;
        case THRILLER: g = "THRILLER"; break;
    }
    std::string str = "";
    str += mv.title + " " + g + " (" + std::to_string(mv.duration) + " min)";
    // std::cout << mv.title << " " << g << " (" << mv.duration << " min)";
    return str;
}
std::string getTimeSlot(TimeSlot ts) { 
    Time start_time = ts.startTime;
    Movie movie = ts.movie;
    Time end_time = addMinutes(start_time, movie.duration);
    
    std::string movie_desc = printMovie(movie) + " [starts at " + std::to_string(start_time.h) + ":" + std::to_string(start_time.m) + ", ends by " +  std::to_string(end_time.h) + ":" + std::to_string(end_time.m) + "]";
    return movie_desc;
}
// Task D
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){
    Time new_start_time = addMinutes(ts.startTime, ts.movie.duration);
    TimeSlot new_ts = {nextMovie, new_start_time};
    return new_ts;
}

//Task E
bool timeOverlap(TimeSlot ts1, TimeSlot ts2){
    int duration, interval;
    if (minutesUntil(ts1.startTime, ts2.startTime) < 0){
        //ts2 is earlier
        duration = ts2.movie.duration;
        interval = minutesUntil(ts2.startTime, ts1.startTime);
        if (duration > interval){
            return true;
        } 
        return false;
    } else {
        //ts1 is earlier
        duration = ts1.movie.duration;
        interval = minutesUntil(ts1.startTime, ts2.startTime);
    }
    if (duration > interval){
        return true;
    }
    return false;
}
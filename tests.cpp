#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

TEST_CASE("Testing minutesSinceMidnight and minutesUntil Functions"){
    CHECK(minutesSinceMidnight({20, 30}) == (1230));
    CHECK(minutesSinceMidnight({0, 0})== (0));
    CHECK(minutesSinceMidnight({3, 24}) == (204));
    CHECK(minutesUntil({0,10}, {1,50}) == 100);
    CHECK(minutesUntil({0, 0}, {23, 13}) == 1393);
    CHECK(minutesUntil({12,45}, {23,15}) == 630);
}

TEST_CASE("Testing addMinutes Function"){
    // addMinutes({8, 10}, 75) == {9, 25}
    CHECK(addMinutes({8, 10}, 75).h == 9);
    CHECK(addMinutes({8,10}, 75).m == 25);
    // addMinutes({10, 25}), 600) == {20, 25}
    CHECK(addMinutes({10, 25}, 602).h == 20);
    CHECK(addMinutes({10, 25}, 602).m == 27);
}

TEST_CASE("Testing getTimeSlot"){
    Movie movie = {"Test Movie", ACTION, 120};
    Time time_start = {9, 15};
    TimeSlot ts = {movie, time_start};
    CHECK(getTimeSlot(ts) == "Test Movie ACTION (120 min) [starts at 9:15, ends by 11:15]");

    movie = {"Test Movie", COMEDY, 113};
    time_start = {7, 45};
    ts = {movie, time_start};
    CHECK(getTimeSlot(ts) == "Test Movie COMEDY (113 min) [starts at 7:45, ends by 9:38]");
}

TEST_CASE("Testing scheduleAfter function"){
    Movie movie = {"Test Movie", ACTION, 120};
    Time time_start = {9, 15};
    TimeSlot ts = {movie, time_start};
    Movie new_movie = {"Second Movie", COMEDY, 132};
    CHECK(getTimeSlot(scheduleAfter(ts, new_movie)) == "Second Movie COMEDY (132 min) [starts at 11:15, ends by 13:27]");
    time_start = {7, 11};
    ts = {movie, time_start};
    new_movie = {"Second Movie", COMEDY, 97};
    CHECK(getTimeSlot(scheduleAfter(ts, new_movie)) == "Second Movie COMEDY (97 min) [starts at 9:11, ends by 10:48]");
}

TEST_CASE("Testing TimeOverlap function"){
    Movie movie = {"Test Movie", ACTION, 120};
    Time time_start = {9, 15};
    TimeSlot ts = {movie, time_start};
    movie = {"Second Movie", ACTION, 120};
    time_start = {10, 15};
    TimeSlot new_ts = {movie, time_start};
    CHECK(timeOverlap(ts, new_ts) == true);
    CHECK(timeOverlap(new_ts, ts) == true);
    movie = {"Test Movie", ACTION, 10};
    time_start = {9, 15};
    ts = {movie, time_start};
    movie = {"Second Movie", ACTION, 120};
    time_start = {10, 15};
    new_ts = {movie, time_start};
    CHECK(timeOverlap(ts, new_ts) == false);
    CHECK(timeOverlap(new_ts, ts) == false);
}

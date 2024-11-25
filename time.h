#pragma once

#include <ctime>
#include <string>

using namespace std;

class Time
{
public:
    // Constructors
    Time(); // Default constructor initialises to current time
    Time(int year, int month, int day, int hour = 0, int minute = 0, int second = 0);

    // Accessors
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    int getHour() const;
    int getMinute() const;
    int getSecond() const;

    // Modifiers
    void setYear(int year);
    void setMonth(int month);
    void setDay(int day);
    void setHour(int hour);
    void setMinute(int minute);
    void setSecond(int second);

    // Utility functions
    void setCurrentTime();                                                       // Sets to the current system time
    string toString(const string &format = "%Y-%m-%d %H:%M:%S") const; // Formats time as a string

private:
    tm time_;                    // Stores time information
    time_t toTimeT() const;      // Converts tm to time_t
    void fromTimeT(time_t time); // Converts time_t to std::tm
};
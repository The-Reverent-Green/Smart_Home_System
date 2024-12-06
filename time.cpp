#include <iomanip>
#include <sstream>

#include "time.h"

using namespace std;

Time::Time()
{
    setCurrentTime();
}

Time::Time(int year, int month, int day, int hour, int minute, int second)
{
    time_ = {};
    time_.tm_year = year;
    time_.tm_mon = month;
    time_.tm_mday = day;
    time_.tm_hour = hour;
    time_.tm_min = minute;
    time_.tm_sec = second;
    mktime(&time_); // Normalise the time struct
}

// Getters
int Time::getYear() const
{
    return time_.tm_year;
}

int Time::getMonth() const
{
    return time_.tm_mon;
}

int Time::getDay() const
{
    return time_.tm_mday;
}

int Time::getHour() const
{
    return time_.tm_hour;
}

int Time::getMinute() const
{
    return time_.tm_min;
}

int Time::getSecond() const
{
    return time_.tm_sec;
}

// Setters
void Time::setYear(int year)
{
    time_.tm_year = year - 1900;
    mktime(&time_);
}

void Time::setMonth(int month)
{
    time_.tm_mon = month - 1;
    mktime(&time_);
}

void Time::setDay(int day)
{
    time_.tm_mday = day;
    mktime(&time_);
}

void Time::setHour(int hour)
{
    time_.tm_hour = hour;
    mktime(&time_);
}

void Time::setMinute(int minute)
{
    time_.tm_min = minute;
    mktime(&time_);
}

void Time::setSecond(int second)
{
    time_.tm_sec = second;
    mktime(&time_);
}

void Time::setCurrentTime()
{
    time_t now = time(nullptr);
    time_ = *localtime(&now);
}

// Converts to a formatted string based on the provided format
string Time::toString(const string &format) const
{
    ostringstream oss;
    oss << put_time(&time_, format.c_str());
    return oss.str();
}

// Converts tm to time_t
time_t Time::toTimeT() const
{
    tm temp = time_;
    return mktime(&temp);
}

// Sets time_ from a time_t
void Time::fromTimeT(time_t time)
{
    time_ = *localtime(&time);
}

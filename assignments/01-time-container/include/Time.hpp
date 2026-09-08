#pragma once
#include <compare>

class Time {
    double jdInt_;
    double jdFrac_;
public:
    Time(double jd1 = 0, double jd2 = 0) noexcept;

    double jdInt() const noexcept;
    double jdFrac() const noexcept;
    double jd() const noexcept;
    double mjd() const noexcept;
    
    static Time fromJD(double jd) noexcept;
    static Time fromMJD(double mjd) noexcept;

    static Time fromCalendar(int year, int month, int day, int hour, int minute, double seconds);
    //Я это писать не хочу... я даже не знаю сколько дней в каком месяце


    auto operator<=>(const Time& other) const noexcept = default;
};

double operator-(const Time& first, const Time& second) noexcept;

Time operator-(const Time& time, double secs) noexcept;
Time operator+(const Time& time, double secs) noexcept;

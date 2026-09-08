#include <cmath>
#include "Time.hpp"

Time::Time(double jd1, double jd2) noexcept {

    double jd1Int = std::floor(jd1);
    double jd1Frac = jd1 - jd1Int;
    double jd2Int = std::floor(jd2);
    double jd2Frac = jd2 - jd2Int;

    double fracSum = std::floor(jd1Frac + jd2Frac);

    jdInt_ = jd1Int + jd2Int + fracSum;
    jdFrac_ = jd1Frac + jd2Frac - fracSum;
}

double Time::jdInt() const noexcept {
    return jdInt_;
}

double Time::jdFrac() const noexcept {
    return jdFrac_;
}

double Time::jd() const noexcept {
    return jdInt_ + jdFrac_;
}

double Time::mjd() const noexcept {
    return (jdInt_ - 2400000.0) + (jdFrac_ - 0.5);
}


Time Time::fromJD(double jd) noexcept {
    return Time(jd, 0.0);
}


Time Time::fromMJD(double mjd) noexcept {
    return Time(mjd, 2400000.5);
}

double operator-(const Time& first, const Time& second) noexcept {
    double delta;
    delta = (first.jdInt() - second.jdInt()) + (first.jdFrac() - second.jdFrac());
    return delta * 24 * 3600;
}

Time operator-(const Time& time, double secs) noexcept {
    double jdInt = time.jdInt();
    double jdFrac = time.jdFrac();
    double days = secs / (24 * 3600);
    return Time(jdInt, jdFrac - days);
}

Time operator+(const Time& time, double secs) noexcept {
    double jdInt = time.jdInt();
    double jdFrac = time.jdFrac();
    double days = secs / (24 * 3600);
    return Time(jdInt, jdFrac + days);
}
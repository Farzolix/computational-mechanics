#include "Time.hpp"
#include <cassert>
#include <cmath>

int main() {
    Time a1(2460000.7, 0.6);
    Time b1(2460001.2, -0.5);
    Time c1(2460000.9, 0.3);
    Time d1(2460000.1, -0.3);

    assert(a1.jdInt() == 2460001);
    assert(std::abs(a1.jdFrac() - 0.3) < 1e-9);

    assert(b1.jdInt() == 2460000);
    assert(std::abs(b1.jdFrac() - 0.7) < 1e-9);

    assert(c1.jdInt() == 2460001);
    assert(std::abs(c1.jdFrac() - 0.2) < 1e-9);

    assert(d1.jdInt() == 2459999);
    assert(std::abs(d1.jdFrac() - 0.8) < 1e-9);



    Time e1 = Time::fromJD(2460000.7);
    Time e2 = Time::fromMJD(60000.2);

    assert(std::abs(e1.jd() - 2460000.7) < 1e-9);
    assert(std::abs(e1.mjd() - 60000.2) < 1e-9);

    assert(std::abs(e2.jd() - 2460000.7) < 1e-9);
    assert(std::abs(e2.mjd() - 60000.2) < 1e-9);



    Time first1(2460001.5);
    Time second1(2460001.0); 

    assert(std::abs((first1 - second1) - 43200) < 1e-6);
    assert(std::abs((second1 - first1) + 43200.0) < 1e-6);



    Time base(2460000.5);
    Time plus = base + 3600.0;
    Time minus = base - 3600.0;

    assert(std::abs((plus - base) - 3600.0) < 1e-6);
    assert(std::abs((base - minus) - 3600.0) < 1e-6);

    assert(std::abs((base - plus) + 3600.0) < 1e-6);
    assert(std::abs((minus - base) + 3600.0) < 1e-6);   



    Time cmp1(2460000.5);
    Time cmp2(2460001.0);
    Time cmp3(2460000.5);

    assert(cmp1 < cmp2);
    assert(cmp2 > cmp1);
    assert(cmp1 <= cmp3);
    assert(cmp1 >= cmp3);
    assert(cmp1 == cmp3);
    assert(cmp1 != cmp2);   

    return 0;
}
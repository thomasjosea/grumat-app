#include "interest_rate.h"
#include "math.h"

using core::interest_rate;

interest_rate::interest_rate(double annual_rate) {
    auto one_based = 1 + (annual_rate / 100);
    _annual_rate = one_based;
    _monthly_rate = pow(_annual_rate, 1/12.0);
}

double interest_rate::monthly(bool one_based) const {
    if(one_based) {
        return _monthly_rate;
    }
    return (_monthly_rate - 1) * 100;
}

double interest_rate::annual(bool one_based) const {
    if(one_based) {
        return _annual_rate;
    }
    return (_annual_rate - 1) * 100;
}
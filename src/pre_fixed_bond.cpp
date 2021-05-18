#include "pre_fixed_bond.h"
#include "math.h"

using namespace std::chrono;

float core::pre_fixed_bond::price_at(const steady_clock::time_point& now) const {
    if (now > _expiry_date) {
        return 0;
    }
    return _principal * _exponential_growing_indexer.evaluate_at(now);
}

bool core::pre_fixed_bond::is_expired(const steady_clock::time_point& now) const {
    return now > _expiry_date;
}

core::pre_fixed_bond::pre_fixed_bond(float principal, float annual_interest_rate, steady_clock::time_point effective_date, steady_clock::time_point expiry_date) 
    : _principal{principal},
    _exponential_growing_indexer{effective_date,annual_interest_rate},
    _expiry_date{expiry_date} {
}

core::pre_fixed_bond::~pre_fixed_bond() {}
#include "portfolio_asset.h"
#include "math.h"

using namespace std::chrono;

float core::portfolio_asset::price_at(const steady_clock::time_point& now) const {
    if (now < _effective_date) {
        return 0;
    }
    auto max_time = now;
    if (now > _expiry_date) {
        max_time = _expiry_date;
    }
    auto elapsed_time_in_years = duration_cast<hours>(max_time - _effective_date).count() / 8760.0;
    return _principal * pow(1 + _annual_interest_rate / 100, elapsed_time_in_years);
}

bool core::portfolio_asset::is_expired(const steady_clock::time_point& now) const {
    return now > _expiry_date;
}

core::portfolio_asset::portfolio_asset(float principal, float annual_interest_rate, steady_clock::time_point effective_date, steady_clock::time_point expiry_date) 
    : _principal{principal},
    _annual_interest_rate{annual_interest_rate},
    _effective_date{effective_date},
    _expiry_date{expiry_date} {
}

core::portfolio_asset::~portfolio_asset() {}
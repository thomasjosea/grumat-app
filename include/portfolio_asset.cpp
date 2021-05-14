#include "portfolio_asset.h"
#include "math.h"

float core::portfolio_asset::price_at(const time_t& now) const {
    if (now < _effective_date) {
        return 0;
    }
    auto elapsed_time = (now - _effective_date);
    if (elapsed_time > _expiry_date) {
        elapsed_time = _expiry_date;
    }
    return _principal * pow(1 + _annual_interest_rate / 100, elapsed_time / 365.0);
}

bool core::portfolio_asset::is_expired(const time_t& now) const {
    return now > _expiry_date;
}

core::portfolio_asset::portfolio_asset(float principal, float annual_interest_rate, time_t effective_date, time_t expiry_date) 
    : _principal{principal},
    _annual_interest_rate{annual_interest_rate},
    _effective_date{effective_date},
    _expiry_date{expiry_date} {
}

core::portfolio_asset::~portfolio_asset() {}
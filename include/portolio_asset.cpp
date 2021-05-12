#include "portfolio_asset.h"

float portfolio_asset::price_at(time_t now) {
    if (now < _efective_date) {
        return 0;
    }
}

bool portfolio_asset::expired(time_t now) {
    return now > _expiry_date;
}
#include "asset.h"

using core::asset;

asset::asset(steady_clock::time_point effective_date, double principal):
    _effective_date{effective_date},
    _principal{principal}
{}

steady_clock::time_point asset::get_effective_date() const {
    return _effective_date;
}

double asset::get_principal() const {
    return _principal;
}
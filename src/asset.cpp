#include "asset.h"

using core::asset;

asset::asset(steady_clock::time_point effective_date, double principal):
    _effective_date{effective_date},
    _principal{principal}
{}

asset::asset (const asset& other) :
    _effective_date{other._effective_date},
    _principal{other._principal} 
{}

steady_clock::time_point asset::get_effective_date() const {
    return _effective_date;
}

double asset::get_principal() const {
    return _principal;
}
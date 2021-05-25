#include <iostream>
#include "indexed_bond.h"
#include "time_utils.h"

core::indexed_bond::indexed_bond(float principal, steady_clock::time_point effective_date, float rate, bool is_multiple, std::shared_ptr<indexer> _bond_indexer):
    _principal{principal},
    _effective_date{effective_date},
    _rate{rate},
    _is_multiple{is_multiple},
    _bond_indexer{_bond_indexer}
{
}

float core::indexed_bond::price_at(const steady_clock::time_point& now) const {
    if (now < _effective_date) {
        return 0;
    }
    auto principal = _principal;
    auto day = core::days{1};
    for (auto t = _effective_date; t < now; t += day) {
        auto index = _bond_indexer->get_rate_delta(t, t+day) / 100;
        auto interest = 0.0;
        if (_is_multiple) {
            interest = principal * index * _rate;
        } else {
            interest = principal * (index + _rate / 100 / 365.0);
        }
        principal += interest;
    }
    return principal;
}

core::indexed_bond::~indexed_bond() {
}
#include "simple_exponential_indexer.h"
#include <iostream>
#include "math.h"
#include <chrono>
#include "time_utils.h"

using namespace std::chrono;

static double years_delta(const steady_clock::time_point& from, const steady_clock::time_point& to) {
    return duration_cast<core::days>(to - from).count() / 365.0;
}

core::simple_exponential_indexer::simple_exponential_indexer(steady_clock::time_point series_start_date, interest_rate interest):
    _series_start_date{series_start_date},
    _interest{interest}
{}

double core::simple_exponential_indexer::evaluate_at(const steady_clock::time_point& time_point) const {
    if (time_point < _series_start_date) {
        return 0;
    }
    auto elapsed_time_in_years = years_delta(_series_start_date, time_point);
    return pow(_interest.annual(true), elapsed_time_in_years);
}

double core::simple_exponential_indexer::get_rate_delta(const steady_clock::time_point& from, const steady_clock::time_point& to) const {
    return _interest.annual(false) * years_delta(from, to);
}

core::simple_exponential_indexer::~simple_exponential_indexer() {}
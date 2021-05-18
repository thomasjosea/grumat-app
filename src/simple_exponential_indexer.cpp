#include "simple_exponential_indexer.h"
#include "math.h"
#include <chrono>

using namespace std::chrono;

core::simple_exponential_indexer::simple_exponential_indexer(steady_clock::time_point series_start_date, double year_growth):
    _series_start_date{series_start_date},
    _year_growth{year_growth}
{}

double core::simple_exponential_indexer::evaluate_at(const steady_clock::time_point& time_point) const {
    if (time_point < _series_start_date) {
        return 0;
    }
    auto elapsed_time_in_years = duration_cast<hours>(time_point - _series_start_date).count() / 8760.0;
    return pow(1 + _year_growth / 100, elapsed_time_in_years);
}

core::simple_exponential_indexer::~simple_exponential_indexer() {}
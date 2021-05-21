#pragma once
#include "indexer.h"

namespace core {
    class simple_exponential_indexer: public indexer { 
        private:
            steady_clock::time_point _series_start_date;
            double _year_growth;

        public:
            simple_exponential_indexer(steady_clock::time_point series_start_date, double year_growth);
            double evaluate_at(const steady_clock::time_point& time_point) const override;
            double get_rate_delta(const steady_clock::time_point& from, const steady_clock::time_point& to) const override;
            ~simple_exponential_indexer();
    };
}
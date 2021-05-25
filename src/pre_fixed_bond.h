#pragma once
#include "asset_indexer.h"
#include "asset.h"
#include "simple_exponential_indexer.h"
#include <chrono>

using std::chrono::steady_clock;

namespace core {
    class pre_fixed_bond: public asset {
        private:
            simple_exponential_indexer _exponential_growing_indexer;
            steady_clock::time_point _expiry_date;

        public:
            pre_fixed_bond(float principal, float annual_interest_rate, steady_clock::time_point effective_date, steady_clock::time_point expiry_date);
            double price_at(const steady_clock::time_point& now) const override;
            bool is_expired(const steady_clock::time_point& now) const;
    };
};
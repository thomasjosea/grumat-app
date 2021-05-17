#include "asset_indexer.h"
#include <chrono>

using std::chrono::steady_clock;

namespace core {
    class pre_fixed_bond {
        private:
            float _principal;
            float _annual_interest_rate;
            steady_clock::time_point _effective_date;
            steady_clock::time_point _expiry_date;

        public:
            pre_fixed_bond(float principal, float annual_interest_rate, steady_clock::time_point effective_date, steady_clock::time_point expiry_date);
            ~pre_fixed_bond();
            float price_at(const steady_clock::time_point& now) const;
            bool is_expired(const steady_clock::time_point& now) const;
    };
};
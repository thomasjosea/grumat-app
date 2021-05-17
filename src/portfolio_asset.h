#include "asset_indexer.h"
#include <chrono>

using std::chrono::steady_clock;

namespace core {
    class portfolio_asset {
        private:
            float _principal;
            float _annual_interest_rate;
            steady_clock::time_point _effective_date;
            steady_clock::time_point _expiry_date;

        public:
            portfolio_asset(float principal, float annual_interest_rate, steady_clock::time_point effective_date, steady_clock::time_point expiry_date);
            ~portfolio_asset();
            float price_at(const steady_clock::time_point& now) const;
            bool is_expired(const steady_clock::time_point& now) const;
    };
};
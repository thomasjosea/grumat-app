#include "asset_indexer.h"
#include <ctime>

using std::time_t;

namespace core {
    class portfolio_asset {
        private:
            float _principal;
            float _annual_interest_rate;
            time_t _effective_date;
            time_t _expiry_date;

        public:
            portfolio_asset(float principal, float annual_interest_rate, time_t effective_date, time_t expiry_date);
            ~portfolio_asset();
            float price_at(const time_t& now) const;
            bool is_expired(const time_t& now) const;
    };
};
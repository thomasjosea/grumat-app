#include "asset_indexer.h"
#include <ctime>

using std::time_t;

namespace core {
    class portfolio_asset {
        private:
            float _principal;
            asset_indexer _indexType;
            float _annual_interest_rate;
            time_t _effective_date;
            time_t _expiry_date;

        public:
            float price_at(time_t now);
            bool is_expired(time_t now);
    };
}
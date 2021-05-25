#pragma once
#include <chrono>
#include <memory>
#include "simple_exponential_indexer.h"

namespace core {
    class indexed_bond {
        private:
            float _principal;
            steady_clock::time_point _effective_date;
            float _rate;
            bool _is_multiple;
            std::shared_ptr<indexer> _bond_indexer;

        public:
            indexed_bond(float principal, steady_clock::time_point effective_date, float rate, bool is_multiple, std::shared_ptr<indexer> _bond_indexer);
            float price_at(const steady_clock::time_point& now) const;   
    };
}
#pragma once
#include "simple_exponential_indexer.h"
#include "asset.h"
#include <chrono>

namespace core {
    class indexed_bond: public asset {
        private:
            float _rate;
            bool _is_multiple;
            std::shared_ptr<indexer> _bond_indexer;

        public:
            indexed_bond(float principal, steady_clock::time_point effective_date, float rate, bool is_multiple, std::shared_ptr<indexer> bond_indexer);
            double price_at(const steady_clock::time_point& now) const override;   
    };
}
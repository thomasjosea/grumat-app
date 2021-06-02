#pragma once
#include "chrono"

using std::chrono::steady_clock;

namespace core {
    class asset {
        public:
            asset (steady_clock::time_point effective_date, double principal);
            asset (const asset& other);
            steady_clock::time_point get_effective_date() const;
            double get_principal() const;
            virtual double price_at(const steady_clock::time_point& now) const = 0;

        private:
            steady_clock::time_point _effective_date;
            double _principal;
    };
}

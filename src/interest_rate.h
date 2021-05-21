#pragma once

namespace core {
    class interest_rate {
        private:
            double _annual_rate;
            double _monthly_rate;

        public:
            interest_rate(double annual_rate);
            double annual(bool one_based) const;
            double monthly(bool one_based) const;
    };
}
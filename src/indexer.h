#pragma once
#include <chrono>
#include "interest_rate.h"

using std::chrono::steady_clock;

namespace core {
    
    //Interface used to get the rate of an indexer, such as interest rate or inflation, in a given point of time.
    class indexer {
        public:
            virtual double evaluate_at(const steady_clock::time_point& time_point) const = 0; 
            virtual double get_rate_delta(const steady_clock::time_point& from, const steady_clock::time_point& to) const = 0;
    };
}
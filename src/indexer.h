#include <chrono>

using std::chrono::steady_clock;

namespace core {
    
    //Interface used to get the rate of an indexer, such as interest rate or inflation, in a given point of time.
    class indexer {
        public:
            virtual double evaluate_at(const steady_clock::time_point& time_point) = 0; 
    };
}
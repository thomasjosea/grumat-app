#include <gtest/gtest.h>
#include "indexed_bond.h"
#include "simple_exponential_indexer.h"

using core::indexed_bond;
using namespace std::chrono;
using std::make_shared;

const duration<int> one_year = duration<int>(31536000); 

TEST(indexed_bond,test_multiplier_bond_after_1_year) {
    auto effective_date = steady_clock::now();
    auto indexer = make_shared<core::simple_exponential_indexer>(effective_date - 5*one_year,10);
    indexed_bond subject{100,effective_date,1.2,true,indexer};
    EXPECT_NEAR(subject.price_at(effective_date + one_year), 112.747, 0.001);
}

TEST(indexed_bond,test_multiplier_bond_after_3_year) {
    auto effective_date = steady_clock::now();
    auto indexer = make_shared<core::simple_exponential_indexer>(effective_date - 5*one_year,10);
    indexed_bond subject{100,effective_date,1.2,true,indexer};
    EXPECT_NEAR(subject.price_at(effective_date + 3*one_year), 143.325, 0.001);
}
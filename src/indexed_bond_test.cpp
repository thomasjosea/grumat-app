#include <gtest/gtest.h>
#include "indexed_bond.h"
#include "simple_exponential_indexer.h"
#include "time_utils.h"

using core::indexed_bond;
using namespace std::chrono;
using std::make_shared;

TEST(indexed_bond,test_multiplier_bond_after_1_year) {
    auto effective_date = steady_clock::now();
    auto indexer = make_shared<core::simple_exponential_indexer>(effective_date - core::years{5},10);
    indexed_bond subject{100,effective_date,1.2,true,indexer};
    EXPECT_NEAR(subject.price_at(effective_date + core::years{1}), 112.747, 0.001);
}

TEST(indexed_bond,test_multiplier_bond_after_3_year) {
    auto effective_date = steady_clock::now();
    auto indexer = make_shared<core::simple_exponential_indexer>(effective_date - core::years{5},10);
    indexed_bond subject{100,effective_date,1.2,true,indexer};
    EXPECT_NEAR(subject.price_at(effective_date + core::years{3}), 143.325, 0.001);
}

TEST(indexed_bond,test_additive_bond_after_1_year) {
    auto effective_date = steady_clock::now();
    auto indexer = make_shared<core::simple_exponential_indexer>(effective_date - core::years{5},10);
    indexed_bond subject{100,effective_date,5,false,indexer};
    EXPECT_NEAR(subject.price_at(effective_date + core::years{1}), 116.18, 0.001);
}

TEST(indexed_bond,test_additive_bond_after_3_year) {
    auto effective_date = steady_clock::now();
    auto indexer = make_shared<core::simple_exponential_indexer>(effective_date - core::years{5},10);
    indexed_bond subject{100,effective_date,5,false,indexer};
    EXPECT_NEAR(subject.price_at(effective_date + core::years{3}), 156.816, 0.001);
}
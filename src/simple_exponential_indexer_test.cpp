#include <gtest/gtest.h>
#include "simple_exponential_indexer.h"

using core::simple_exponential_indexer;
using namespace std::chrono;

const duration<int> one_year = duration<int>(31536000); 

TEST(simple_exponential_indexer, index_before_start_is_zero) {
  auto effective_date = steady_clock::now();
  simple_exponential_indexer index{effective_date, 10};
  EXPECT_EQ(index.evaluate_at(effective_date - duration<int>(1)), 0);
}

TEST(simple_exponential_indexer, index_after_10_years_grows_exponentially) {
  auto effective_date = steady_clock::now();
  simple_exponential_indexer index{effective_date, 10};
  EXPECT_NEAR(index.evaluate_at(effective_date + one_year * 10), 2.59374, 0.0001);
}

TEST(simple_exponential_indexer, index_delta_in_2_year_is_20) {
  auto effective_date = steady_clock::now();
  simple_exponential_indexer index{effective_date, 10};
  EXPECT_EQ(index.get_rate_delta(effective_date, effective_date + one_year * 2), 20);
}
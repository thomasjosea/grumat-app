#include <gtest/gtest.h>
#include "pre_fixed_bond.h"

using core::pre_fixed_bond;
using namespace std::chrono;

const duration<int> one_year = duration<int>(31536000); 

TEST(pre_fixed_bond, principal_before_effective_is_zero) {
  auto effective_date = steady_clock::now();
  auto expiry_date = effective_date + duration<int>(10);
  pre_fixed_bond subject{100, 10, effective_date, expiry_date};
  EXPECT_EQ(subject.price_at(effective_date - duration<int>(1)), 0);
}

TEST(pre_fixed_bond, principal_after_one_year) {
  auto effective_date = steady_clock::now();
  auto expiry_date = effective_date + one_year;
  pre_fixed_bond subject{100, 10, effective_date, expiry_date};
  EXPECT_EQ(subject.price_at(expiry_date), 110);
}

TEST(pre_fixed_bond, growth_stops_after_expiry_date) {
  auto effective_date = steady_clock::now();
  auto expiry_date = effective_date + one_year;
  pre_fixed_bond subject{100, 10, effective_date, expiry_date};
  EXPECT_EQ(subject.price_at(effective_date + 2 * one_year), 110);
}

TEST(pre_fixed_bond, compound_interest_test) {
  auto effective_date = steady_clock::now();
  auto expiry_date = effective_date + 3 * one_year;
  pre_fixed_bond subject{100, 10, effective_date, expiry_date};
  EXPECT_EQ(subject.price_at(expiry_date), 133.1f);
}
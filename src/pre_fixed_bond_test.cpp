#include <gtest/gtest.h>
#include "pre_fixed_bond.h"
#include "time_utils.h"

using core::pre_fixed_bond;
using namespace std::chrono;

TEST(pre_fixed_bond, principal_before_effective_is_zero) {
  auto effective_date = steady_clock::now();
  auto expiry_date = effective_date + duration<int>(10);
  pre_fixed_bond subject{100, core::interest_rate{10}, effective_date, expiry_date};
  EXPECT_EQ(subject.price_at(effective_date - duration<int>(1)), 0);
}

TEST(pre_fixed_bond, principal_after_one_year) {
  auto effective_date = steady_clock::now();
  auto expiry_date = effective_date + core::years{1};
  pre_fixed_bond subject{100, core::interest_rate{10}, effective_date, expiry_date};
  EXPECT_NEAR(subject.price_at(expiry_date), 110, 0.0001);
}

TEST(pre_fixed_bond, price_is_zero_after_expiry_date) {
  auto effective_date = steady_clock::now();
  auto expiry_date = effective_date + core::years{1};
  pre_fixed_bond subject{100, core::interest_rate{10}, effective_date, expiry_date};
  EXPECT_EQ(subject.price_at(effective_date + core::years{2}), 0);
}

TEST(pre_fixed_bond, compound_interest_test) {
  auto effective_date = steady_clock::now();
  auto expiry_date = effective_date + core::years{3};
  pre_fixed_bond subject{100, core::interest_rate{10}, effective_date, expiry_date};
  EXPECT_NEAR(subject.price_at(expiry_date), 133.1, 0.0001);
}
#include <gtest/gtest.h>
#include "interest_rate.h"

using core::interest_rate;

TEST(interest_rate, annual_one_based_false) {
    interest_rate rate{10};
    ASSERT_NEAR(rate.annual(false), 10, 0.0001);
}

TEST(interest_rate, annual_one_based_true) {
    interest_rate rate{10};
    ASSERT_NEAR(rate.annual(true), 1.10, 0.0001);
}

TEST(interest_rate, monthly_one_based_false) {
    interest_rate rate{10};
    ASSERT_NEAR(rate.monthly(false), 0.7974, 0.0001);
}

TEST(interest_rate, monthly_one_based_true) {
    interest_rate rate{10};
    ASSERT_NEAR(rate.monthly(true), 1.007974, 0.0001);
}
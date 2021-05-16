#include <gtest/gtest.h>
#include "portfolio_asset.h"

using core::portfolio_asset;

TEST(portfolio_asset, principal_before_effective_is_zero) {
  auto effective_date = 1000000;
  auto subject = portfolio_asset{100, 10, effective_date, 2000000};
  EXPECT_EQ(subject.price_at(effective_date - 1), 0);
}
#include "include/portfolio_asset.h"
#include <iostream>

using namespace core;
using std::cout;

int main (int argc, char** argv) {
    auto asset = portfolio_asset(100, asset_indexer::fixed, 10, 0, 1);
    return 0;
}
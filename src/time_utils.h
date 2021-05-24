#pragma once
#include <chrono>

namespace core {
    using days = std::chrono::duration<int, std::ratio_multiply<std::ratio<24>, std::chrono::hours::period>>;
    using years = std::chrono::duration<int, std::ratio_multiply<std::ratio<365>, core::days::period>>;
}

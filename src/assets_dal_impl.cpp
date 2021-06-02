#include "assets_dal_impl.h"
using namespace grumat::dal;

const std::vector<std::unique_ptr<core::asset>>& assets_dal_impl::get() const {
    return assets_;
}
void assets_dal_impl::upsert(std::unique_ptr<core::asset>& subject)  {
    auto iter = find(subject);
    if (iter == assets_.end()) {
        assets_.push_back(std::move(subject));
    } else {
        *iter = std::move(subject);
    }
}

std::vector<std::unique_ptr<core::asset>>::iterator assets_dal_impl::find(const std::unique_ptr<core::asset>& subject) {
    for (auto s = assets_.begin(); s < assets_.end(); s++) {
        if (*s == subject) {
            return s;
        }
    }
    return assets_.end();
}

void assets_dal_impl::remove(std::unique_ptr<core::asset>& subject) {
    auto iter = find(subject);
    if (iter == assets_.end()) {
        throw "object does not exist";
    }
    assets_.erase(iter);
}
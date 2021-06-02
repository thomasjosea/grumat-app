#include "assets_dal.h"

namespace grumat { namespace dal {
    class assets_dal_impl: public assets {
        private:
            std::vector<std::unique_ptr<core::asset>> assets_;
            decltype(assets_)::iterator find(const std::unique_ptr<core::asset>& subject);

        public:
            const std::vector<std::unique_ptr<core::asset>>& get() const override;
            void upsert(std::unique_ptr<core::asset>& subject) override;
            void remove(std::unique_ptr<core::asset>& subject) override;
    };
}}
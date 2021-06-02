#include <vector>
#include "asset.h"

namespace grumat { namespace dal {
    class assets {
      public:
        virtual const std::vector<std::unique_ptr<core::asset>>& get() const = 0;
        virtual void upsert(std::unique_ptr<core::asset>& subject) = 0;
        virtual void remove(std::unique_ptr<core::asset>& subject) = 0;
    };
}}
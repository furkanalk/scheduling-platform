#include "scheduling/academic/domain_info.h"
#include "scheduling/core/platform_info.h"

#include <cassert>

int main() {
    assert(!scheduling::core::platform_name().empty());
    assert(!scheduling::core::platform_version().empty());
    assert(!scheduling::academic::domain_name().empty());

    return 0;
}

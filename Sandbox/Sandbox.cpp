#include <concepts>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

// Unused, but here to confirm that dependency syncing works. Remove when appropriate.
#include <fmt/core.h>
#include <zlib.h>

template <std::integral I>
I factorial(I i) {
    return i > 1 ? factorial(i - 1) * i : 1;
}

TEST_CASE("testing the factorial function") {
    CHECK(factorial(0) == 1);
    CHECK(factorial(1) == 1);
    CHECK(factorial(2) == 2);
    CHECK(factorial(3) == 6);
    CHECK(factorial(10) == 3628800);
}

module;

#include <concepts>

export module math;

namespace math {

export template <std::integral I>
I factorial(I i) {
    return i > 1 ? factorial(i - 1) * i : 1;
}

} // namespace math

// #include <doctest/doctest.h>

// TEST_CASE("testing the factorial function") {
//     using namespace math;
//     CHECK(factorial(0) == 1);
//     CHECK(factorial(1) == 1);
//     CHECK(factorial(2) == 2);
//     CHECK(factorial(3) == 6);
//     CHECK(factorial(10) == 3628800);
// }

#include <concepts>
#include <thread>

#define DOCTEST_CONFIG_IMPLEMENT
#include <doctest/doctest.h>

#include <fmt/core.h>

#include <stlab/concurrency/default_executor.hpp>
#include <stlab/concurrency/future.hpp>

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

TEST_CASE("stlab futures") {
    using namespace std;
    using namespace stlab;

    auto argument1 = async(default_executor, [] { return 42; });
    auto argument2 = async(default_executor, [] { return string("The answer"); });

    auto result = when_all(default_executor, [](int answer, std::string description) {
        return fmt::format("{} is {}", description, answer);
    }, argument1, argument2);

    // Waiting just for illustration purpose
    while (!result.get_try()) { this_thread::sleep_for(chrono::milliseconds(1)); }

    CHECK(result.is_ready());

    CHECK(*result.get_try() == "The answer is 42");
}

int main(int argc, char** argv) {
    doctest::Context context;

    auto res = context.run();

    // stlab::pre_exit(); // TODO: update stlab on vcpkg and add this.

    return res;
}

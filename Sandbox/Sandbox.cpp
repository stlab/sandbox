#include <iostream>

// Doctest seems to misbehave; forward declaring std::tuple causes this type of error:
// https://stackoverflow.com/questions/67952223/c-modules-forward-declaring-entity-from-another-module
// Should revisit ASAP.
// #define DOCTEST_CONFIG_IMPLEMENT
// #include <doctest/doctest.h>

#include <fmt/core.h>

#include <stlab/concurrency/default_executor.hpp>
#include <stlab/concurrency/future.hpp>

import math;

int main(int argc, char** argv) {
    using namespace std;
    using namespace stlab;

    auto argument1 = async(default_executor, [] { return string("10!"); });
    auto argument2 = async(default_executor, [] { return math::factorial(10); });

    auto result = when_all(
        default_executor,
        [](std::string description, int answer) {
            return fmt::format("{} is {}", description, answer);
        },
        argument1, argument2);

    // Waiting just for illustration purpose
    while (!result.get_try()) {
        this_thread::sleep_for(chrono::milliseconds(1));
    }

    std::cout << *result.get_try() << '\n';

    // stlab::pre_exit(); // TODO: update stlab on vcpkg and add this.

    return 42;
}

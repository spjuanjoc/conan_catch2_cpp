/**
 * @brief Implements the tests for a factorial method.
 */

#include <catch2/catch_test_macros.hpp>

std::uint32_t Factorial(std::uint32_t number)
{
  return number <= 1 ? number : Factorial(number - 1) * number;
}

TEST_CASE("Compute factorials 1, 2 and 3", "[factorial]")
{
  REQUIRE(Factorial(1) == 1);
  REQUIRE(Factorial(2) == 2);
  REQUIRE(Factorial(3) == 6);
}

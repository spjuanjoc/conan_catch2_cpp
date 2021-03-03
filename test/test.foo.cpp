#include "catch2/catch.hpp"
#include <optional>

TEST_CASE("test the execution of foo")
{
  REQUIRE( 1 == 1);
  std::optional<int> var;
}

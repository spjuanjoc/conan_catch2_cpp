/**
 * @brief Implements the tests for Behavior Based Development - style testing.
 *
 * @author  spjuanjoc
 * @date    2024-04-17
 */

#include <catch2/catch_test_macros.hpp>
#include <list>
#include <string>
#include <vector>

SCENARIO("A std::vector can be sized and resized")
{
  GIVEN("An empty std::vector")
  {
    std::vector words = std::vector<std::string>{};

    THEN("The size and capacity are 0")
    {
      REQUIRE(words.empty());
      REQUIRE(words.capacity() == 0);
    }

    WHEN("push_back() is called")
    {
      words.push_back("hello");

      THEN("The size changes")
      {
        REQUIRE(words.size() == 1);
        REQUIRE(words.capacity() >= 1);
      }

      AND_WHEN(" an element is removed")
      {
        words.erase(words.begin());

        THEN("The size is zero")
        {
          REQUIRE(words.empty());

          AND_THEN("the capacity does not change")
          {
            REQUIRE(words.capacity() >= 1);
          }
        }
      }

      AND_GIVEN("A movable object")
      {
        std::string word = std::string{"world"};

        WHEN("pushed")
        {
          words.emplace_back(std::move(word));

          THEN("The size changes")
          {
            REQUIRE(words.size() == 2);
            REQUIRE(words.capacity() >= 2);

            AND_THEN("The values are in order")
            {
              CHECK(words[0] == "hello");
              CHECK(words[1] == "world");
            }
          }
        }
      }
    }

    // Validate another use case for the GIVEN objects
    WHEN("emplace_back() is called")
    {
      words.emplace_back("hello again");

      THEN("The size changes")
      {
        REQUIRE(words.size() == 1);
        REQUIRE(words.capacity() >= 1);
      }
    }
  }
}

SCENARIO("A std::list can be sized and resized")
{
  GIVEN("An empty std::list")
  {
    std::list numbers = std::list<std::uint32_t>{};

    THEN("The size starts at 0")
    {
      REQUIRE(numbers.empty());
    }

    WHEN("push_back() is called")
    {
      numbers.push_back(1);

      THEN("The size changes")
      {
        REQUIRE(numbers.size() == 1);
      }
    }
  }
}

#define CATCH_CONFIG_MAIN

#include "catch_amalgamated.hpp"
#include "utils.hpp"

TEST_CASE("SplitString", "simple") {
  REQUIRE(utils::SplitString("") == std::vector<std::string>{});
  REQUIRE(utils::SplitString(" ") == std::vector<std::string>{});
  REQUIRE(utils::SplitString("a") == std::vector<std::string>{"a "});
  REQUIRE(utils::SplitString("a ") == std::vector<std::string>{"a"});
  REQUIRE(utils::SplitString(" a") == std::vector<std::string>{"a"});
  REQUIRE(utils::SplitString("a b") == std::vector<std::string>{"a", "b"});
  REQUIRE(utils::SplitString("a b  c") ==
          std::vector<std::string>{"a", "b", "c"});
}

TEST_CASE("SplitCommandString", "simple") {
  REQUIRE(utils::SplitCommandString("") == std::vector<std::string>{});
  REQUIRE(utils::SplitCommandString(" ") == std::vector<std::string>{});
  REQUIRE(utils::SplitCommandString("a") == std::vector<std::string>{"a"});
  REQUIRE(utils::SplitCommandString("a ") == std::vector<std::string>{"a"});
  REQUIRE(utils::SplitCommandString(" a") == std::vector<std::string>{"a"});
  REQUIRE(utils::SplitCommandString("a b") ==
          std::vector<std::string>{"a", "b"});
  REQUIRE(utils::SplitCommandString("a b  c") ==
          std::vector<std::string>{"a", "b", "c"});
  REQUIRE(utils::SplitCommandString("a (b c)") ==
          std::vector<std::string>{"a", "b c"});
  REQUIRE(utils::SplitCommandString("a (b (c d))") ==
          std::vector<std::string>{"a", "b (c d)"});
}

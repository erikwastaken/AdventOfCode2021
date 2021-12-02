#include "catch.hpp"
#include "day02.hpp"

using namespace aoc21;

SCENARIO( "Day 2" ) {
  GIVEN( "test instructions" ) {
    std::vector<std::string> input = {"forward 5",
        "down 5",
        "forward 8",
        "up 3",
        "down 8",
        "forward 2"};
    auto cut = Day02(input);
    WHEN( "Part 1: multiply final depth and horizontal position" ) {
      THEN( "result is 150" ) {
        REQUIRE( cut.part1() == "150" );
      }
    }
  }
}

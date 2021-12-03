#include "catch.hpp"
#include "day03.hpp"

using namespace aoc21;

SCENARIO( "Day 3" ) {
  GIVEN( "test instructions" ) {
    std::vector<std::string> input = {
        "00100",
        "11110",
        "10110",
        "10111",
        "10101",
        "01111",
        "00111",
        "11100",
        "10000",
        "11001",
        "00010",
        "01010"
    };
    auto cut = Day03(input);
    WHEN( "Part 1: multiply gamma and epsilon rate" ) {
      THEN( "result is 198" ) {
        REQUIRE( cut.part1() == "198" );
      }
    }

    WHEN( "Part 2: multiply oxygen and CO2 scrubber ratings" ) {
      THEN( "result is 230" ) {
        REQUIRE( cut.part2() == "230" );
      }
    }
  }
}

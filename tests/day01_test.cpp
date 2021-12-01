#include <string>
#include <vector>
#include "catch.hpp"
#include "day01.hpp"

using namespace aoc21;

SCENARIO( "Day 1" ) {
  
  GIVEN( "test input" ){
    std::vector<std::string> input = {"199", "200", "208", "210", "200", "207", "240", "269", "260", "263"};
    auto cut = Day01(input);
    WHEN( "part 1" ) {
      THEN( "result is 7") {
        REQUIRE(cut.part1() == "7");
      }
    }
  }

}

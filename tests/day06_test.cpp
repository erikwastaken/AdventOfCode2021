#include "catch.hpp"
#include "day06.hpp"

using namespace aoc21;

SCENARIO( "Day 6" ) {
    GIVEN( "a string with the initial state" ) {
        std::string input = "3,4,3,1,2";
        auto cut = Day06(input);
        WHEN( "Part 1 - modelling the reproduction for 18 days" ) {
            THEN( "there are 26 fish" ) {
                REQUIRE( cut.modelGrowth(18) == 26 );
            }
        }
        WHEN( "Part 1 - modelling the reproduction for 80 days" ) {
            THEN( "there are 5934 fish" ) {
                REQUIRE( cut.part1() == "5934" );
            }
        }
        WHEN( "Part 2 - modelling the reproduction for 256 days") {
            THEN( "there are 26984457539" ) {
                REQUIRE( cut.part2() == "26984457539" );
            }
        }
    }
}

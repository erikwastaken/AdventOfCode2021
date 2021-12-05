#include "catch.hpp"
#include "day05.hpp"

SCENARIO( "Day 05" ) {
    GIVEN( "test input" ) {
        std::vector<std::string> input = {
                "0,9 -> 5,9",
                "8,0 -> 0,8",
                "9,4 -> 3,4",
                "2,2 -> 2,1",
                "7,0 -> 7,4",
                "6,4 -> 2,0",
                "0,9 -> 2,9",
                "3,4 -> 1,4",
                "0,0 -> 8,8",
                "5,5 -> 8,2"
        };
        auto cut = aoc21::Day05(input);
        WHEN( "part 1 - at how many points do at least two lines overlap?" ) {
            THEN( "returns 5" ) {
                REQUIRE( cut.part1() == "5" );
            }
        }
        WHEN( "part 2 - consider diagonal lines (45%)" ) {
            THEN( "returns 12" ) {
                REQUIRE( cut.part2() == "12" );
            }
        }
    }
}
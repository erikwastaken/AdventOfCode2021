#include "catch.hpp"
#include "day07.hpp"

SCENARIO("Day 7: aligning crabs") {
    GIVEN("test input") {
        std::string input = "16,1,2,0,4,2,7,1,2,14";
        auto cut = aoc21::Day07(input);
        WHEN("Part 1 - determine minimum linear fuel consumption to align") {
            THEN("result is 37") {
                REQUIRE(cut.part1() == "37");
            }
        }
        WHEN("Part 2 - determine minimum incremental fuel consumption to align") {
            THEN("result is 168") {
                REQUIRE(cut.part2() == "168");
            }
        }
    }
}

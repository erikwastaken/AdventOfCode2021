#include "catch.hpp"
#include "day09.hpp"


SCENARIO("Day 9: Heightmap", "[day09]") {
    GIVEN("test input") {
        std::vector<std::string> input = {
            "2199943210",
            "3987894921",
            "9856789892",
            "8767896789",
            "9899965678"
        };
        auto cut = aoc21::Day09(input);
        WHEN("Part 1 - Sum risk level of local minimums") {
            THEN("result is 15") {
                REQUIRE(cut.part1() == "15");
            }
        }
        WHEN("Part 2 - Find three largest basins and multiply their sizes") {
            THEN("result is 1134") {
                REQUIRE(cut.part2() == "1134");
            }
        }
    }
}

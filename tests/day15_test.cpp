#include "catch.hpp"
#include "day15.hpp"


SCENARIO("Day 15: Chiton", "[day15]") {
    GIVEN("test input") {
        std::vector<std::string> input = {
            "1163751742",
            "1381373672",
            "2136511328",
            "3694931569",
            "7463417111",
            "1319128137",
            "1359912421",
            "3125421639",
            "1293138521",
            "2311944581"
        };
        auto cut = aoc21::Day15(input);
        WHEN("Part 1 - Find path with smallest risk level") {
            THEN("result is 40") {
                REQUIRE(cut.part1() == "40");
            }
        }
        WHEN("Part 2 - Find shortest path in extended grid") {
            THEN("result is 315") {
                REQUIRE(cut.part2() == "315");
            }
        }
    }
}

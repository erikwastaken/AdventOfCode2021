#include "catch.hpp"
#include "day17.hpp"


SCENARIO("Day 17: Packet Decoder", "[day17]") {
    GIVEN("test input") {
        std::string input = "target area: x=20..30, y=-10..-5";
        auto cut = aoc21::Day17(input);
        WHEN("Part 1 - max height") {
            THEN("result is correct") {
                REQUIRE(cut.part1() == "45");
            }
        }
        WHEN("Part 2 - total number of distinct initial velocities to reach target") {
            THEN("result is correct") {
                REQUIRE(cut.part2() == "112");
            }
        }
    }
}

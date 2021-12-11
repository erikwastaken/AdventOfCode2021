#include "catch.hpp"
#include "day11.hpp"


SCENARIO("Day 11: Heightmap", "[day11]") {
    GIVEN("test input") {
        std::vector<std::string> input = {
            "5483143223",
            "2745854711",
            "5264556173",
            "6141336146",
            "6357385478",
            "4167524645",
            "2176841721",
            "6882881134",
            "4846848554",
            "5283751526"
        };
        auto cut = aoc21::Day11(input);
        WHEN("Part 1 - Track number of flashes in 100 steps") {
            THEN("result is 1656") {
                REQUIRE(cut.part1() == "1656");
            }
        }
        WHEN("Part 2 - Determine first step on which all octopuses flash simultaneously") {
            THEN("step 195") {
                REQUIRE(cut.part2() == "195");
            }
        }
    }
}

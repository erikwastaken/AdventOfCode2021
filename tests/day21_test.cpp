#include "catch.hpp"
#include "day21.hpp"

SCENARIO("Day 21: Dirac Dice", "[day21]") {
    GIVEN("test input") {
        std::vector<std::string> input = {
            "Player 1 starting position: 4",
            "Player 2 starting position: 8"
        };
        auto cut = aoc21::Day21(input);
        WHEN("Part 1 - Product of losing points and total die rolls") {
            THEN("result is correct") {
                REQUIRE(cut.part1() == "739785");
            }
        }
        WHEN("Part 2 - how many universes does the winning player win?") {
            THEN("result is correct") {
                REQUIRE(cut.part2() == "444356092776315");
            }
        }
    }
}

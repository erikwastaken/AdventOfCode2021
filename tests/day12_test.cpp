#include "catch.hpp"
#include "day12.hpp"


SCENARIO("Day 12: Paths through cave system", "[day12]") {
    GIVEN("test input") {
        std::vector<std::string> input = {
            "dc-end",
            "HN-start",
            "start-kj",
            "dc-start",
            "dc-HN",
            "LN-dc",
            "HN-end",
            "kj-sa",
            "kj-HN",
            "kj-dc"
        };
        auto cut = aoc21::Day12(input);
        WHEN("Part 1 - determine number of paths through cave system") {
            THEN("result is 19") {
                REQUIRE(cut.part1() == "19");
            }
        }
        WHEN("Part 2 - determine number of paths through cave system, one small cave can be visited twice") {
            THEN("result is 103") {
                REQUIRE(cut.part2() == "103");
            }
        }
    }
}

#include "catch.hpp"
#include "day14.hpp"


SCENARIO("Day 14: Extended Polymerization", "[day14]") {
    GIVEN("test input") {
        std::vector<std::string> input = {
            "NNCB",
            "",
            "CH -> B",
            "HH -> N",
            "CB -> H",
            "NH -> C",
            "HB -> C",
            "HC -> B",
            "HN -> C",
            "NN -> C",
            "BH -> H",
            "NC -> B",
            "NB -> B",
            "BN -> B",
            "BB -> N",
            "BC -> B",
            "CC -> N",
            "CN -> C"
        };
        auto cut = aoc21::Day14(input);
        WHEN("Part 1 - Subtract least common from most common after 10 steps") {
            THEN("result is 1588") {
                REQUIRE(cut.part1() == "1588");
            }
        }
        WHEN("Part 2 - Subtract least common from most common after 40 steps") {
            THEN("result is 2188189693529") {
                REQUIRE(cut.part2() == "2188189693529");
            }
        }
    }
}

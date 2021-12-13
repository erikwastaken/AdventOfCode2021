#include "catch.hpp"
#include "day13.hpp"


SCENARIO("Day 13: Transparent Origami", "[day13]") {
    GIVEN("test input") {
        std::vector<std::string> input = {
            "6,10",
            "0,14",
            "9,10",
            "0,3",
            "10,4",
            "4,11",
            "6,0",
            "6,12",
            "4,1",
            "0,13",
            "10,12",
            "3,4",
            "3,0",
            "8,4",
            "1,10",
            "2,14",
            "8,10",
            "9,0",
            "",
            "fold along y=7",
            "fold along x=5"
        };
        auto cut = aoc21::Day13(input);
        WHEN("Part 1 - number of dots after first fold") {
            THEN("result is 17") {
                REQUIRE(cut.part1() == "17");
            }
        }
        WHEN("Part 2 - final configuration of points") {
            THEN("result is a square") {
                auto exp = std::string("\n#####\n#...#\n#...#\n#...#\n#####\n.....\n.....");
                REQUIRE(cut.part2() == exp );
            }
        }
    }
}

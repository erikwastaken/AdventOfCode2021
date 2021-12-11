#include "catch.hpp"
#include "day10.hpp"


SCENARIO("Day 10: Heightmap", "[day10]") {
    GIVEN("test input") {
        std::vector<std::string> input = {
            "[({(<(())[]>[[{[]{<()<>>",
            "[(()[<>])]({[<{<<[]>>(",
            "{([(<{}[<>[]}>{[]{[(<()>",
            "(((({<>}<{<{<>}{[]{[]{}",
            "[[<[([]))<([[{}[[()]]]",
            "[{[{({}]{}}([{[{{{}}([]",
            "{<[[]]>}<{[{[{[]{()[[[]",
            "[<(<(<(<{}))><([]([]()",
            "<{([([[(<>()){}]>(<<{{",
            "<{([{{}}[<[[[<>{}]]]>[]]"
        };
        auto cut = aoc21::Day10(input);
        WHEN("Part 1 - Sum points of first illegal character") {
            THEN("result is 26397") {
                REQUIRE(cut.part1() == "26397");
            }
        }
        WHEN("Part 2 - Calculate points for completed chunks") {
            THEN("result is 288957") {
                REQUIRE(cut.part2() == "288957");
            }
        }
    }
}

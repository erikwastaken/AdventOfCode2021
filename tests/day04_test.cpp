#include "catch.hpp"
#include "day04.hpp"
#include <string>
#include <vector>

SCENARIO("Day 4: playing bingo") {
    GIVEN("test input") {
        std::vector<std::string> input = {
                "7,4,9,5,11,17,23,2,0,14,21,24,10,16,13,6,15,25,12,22,18,20,8,19,3,26,1",
                "",
                "22 13 17 11  0",
                "8  2 23  4 24",
                "21  9 14 16  7",
                "6 10  3 18  5",
                "1 12 20 15 19",
                "",
                "3 15  0  2 22",
                "9 18 13 17  5",
                "19  8  7 25 23",
                "20 11 10 24  4",
                "14 21 16 12  6",
                "",
                "14 21 17 24  4",
                "10 16 15  9 19",
                "18  8 23 26 20",
                "22 11 13  6  5",
                "2  0 12  3  7"
        };
        auto cut = aoc21::Day04(input);
        WHEN("Part 1") {
            THEN("result is 4512") {
                REQUIRE(cut.part1() == "4512");
            }
        }
        WHEN("Part 2 - choose the last board to win") {
            THEN("result is 1924") {
                REQUIRE(cut.part2() == "1924");
            }
        }
    }
}

SCENARIO("Parsing input") {
    GIVEN("test input") {
        WHEN("parsing numbers on first line") {
            std::string input = "1,22,3";
            auto act = aoc21::parseBingoNumbers(input);
            THEN("returns {1,22,3}") {
                std::vector exp{1, 22, 3};
                REQUIRE(act == exp);
            }
        }
    }
}

SCENARIO("Bingo Board") {
    GIVEN("some input") {
        std::vector<std::string> input = {
                "22 13 17 11  0",
                "8  2 23  4 24",
                "21  9 14 16  7",
                "6 10  3 18  5",
                "1 12 20 15 19"
        };
        auto cut = aoc21::BingoBoard(input);
        WHEN("marking off a row") {
            cut.mark(8);
            cut.mark(2);
            cut.mark(23);
            cut.mark(4);
            cut.mark(24);
            THEN("board is complete") {
                REQUIRE(cut.isComplete());
            }
        }
        WHEN("marking off a column") {
            cut.mark(17);
            cut.mark(23);
            cut.mark(14);
            cut.mark(3);
            cut.mark(20);
            THEN("board is complete") {
                REQUIRE(cut.isComplete());
            }
        }
    }
    GIVEN("a completed board") {
        std::vector<int> numbers{7, 4, 9, 5, 11, 17, 23, 2, 0, 14, 21, 24};
        std::vector<std::string> input{
                "14 21 17 24  4",
                "10 16 15  9 19",
                "18  8 23 26 20",
                "22 11 13  6  5",
                "2  0 12  3  7"
        };
        auto cut = aoc21::BingoBoard(input);
        for (auto num: numbers) {
            cut.mark(num);
        }
        WHEN("calculating the final score") {
            auto score = cut.calculatePoints();
            THEN("score is 188") {
                REQUIRE(score == 188);
            }
        }
    }
}

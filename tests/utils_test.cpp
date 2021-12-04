#include "catch.hpp"
#include "utils.hpp"

SCENARIO( "Split strings" ) {
    GIVEN( "a string" ) {
        std::string input = "hello world";
        WHEN( "splitting at ' '") {
            auto act = aoc21::splitString(input, ' ');
            THEN( "returns vector containing the two words" ) {
                std::vector<std::string> exp {"hello", "world"};
                REQUIRE(act == exp);
            }
        }
    }
    GIVEN( "a string of integers" ) {
        std::string input = "1 2 3";
        WHEN( "splitting at space" ) {
            auto act = aoc21::splitString(input, ' ', [](const std::string& s) { return std::stoi(s); });
        }
    }
}


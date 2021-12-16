#include "catch.hpp"
#include "day16.hpp"


SCENARIO("Day 16: Packet Decoder", "[day16]") {
    GIVEN("test input") {
        std::vector<std::string> input = {
            "8A004A801A8002F478",
            "620080001611562C8802118E34",
            "C0015000016115A2E0802F182340",
            "A0016C880162017C3686B18A3D4780"
        };
        WHEN("Part 1 - sum packet versions") {
            auto cut0 = aoc21::Day16(input[0]);
            auto cut1 = aoc21::Day16(input[1]);
            auto cut2 = aoc21::Day16(input[2]);
            auto cut3 = aoc21::Day16(input[3]);
            THEN("result is correct") {
                REQUIRE(cut0.part1() == "16");
                REQUIRE(cut1.part1() == "12");
                REQUIRE(cut2.part1() == "23");
                REQUIRE(cut3.part1() == "31");
            }
        }
        WHEN("Part 2 - evaluate transmission") {
            auto cut0 = aoc21::Day16("C200B40A82");
            auto cut1 = aoc21::Day16("04005AC33890");
            auto cut2 = aoc21::Day16("880086C3E88112");
            auto cut3 = aoc21::Day16("CE00C43D881120");
            auto cut4 = aoc21::Day16("D8005AC2A8F0");
            auto cut5 = aoc21::Day16("F600BC2D8F");
            auto cut6 = aoc21::Day16("9C005AC2F8F0");
            auto cut7 = aoc21::Day16("9C0141080250320F1802104A08");
            THEN("result is correct") {
                REQUIRE(cut0.part2() == "3");
                REQUIRE(cut1.part2() == "54");
                REQUIRE(cut2.part2() == "7");
                REQUIRE(cut3.part2() == "9");
                REQUIRE(cut4.part2() == "1");
                REQUIRE(cut5.part2() == "0");
                REQUIRE(cut6.part2() == "0");
                REQUIRE(cut7.part2() == "1");
            }
        }
    }
}

SCENARIO("Hex to Binary", "[day16]") {
    GIVEN("a hex string") {
        std::string input = "D2FE28";
        WHEN("converting to binary") {
            std::string bin = "";
            for (auto c : input) {
                bin += aoc21::hexToBin(c);
            }
            THEN("converts correctly") {
                REQUIRE(bin == "110100101111111000101000");
            }
        }
        WHEN("converting a hex string to binary") {
            THEN("converts correctly") {
                REQUIRE(aoc21::hexStringToBinary(input) == "110100101111111000101000");
            }
        }
    }
}

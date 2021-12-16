#ifndef AOC21_DAY16_HPP
#define AOC21_DAY16_HPP

#include <vector>
#include <string>

namespace aoc21 {

    std::string hexToBin(char c);
    std::string hexStringToBinary(const std::string &input);

    class Day16 {
        public:
            Day16(const std::string &input);
            std::string part1() const;
            std::string part2() const;
        private:
            struct Packet {
                int version {};
                int typeID {};
                int length {};
                long long litValue {};
                std::vector<Packet> subPackets {};
                Packet(const std::string &binary);
                long long evaluate() const;
            };
            Packet _packet;
            void sumVersionNumbers(const aoc21::Day16::Packet* p, int* sum) const;
    };

}

#endif


#ifndef AOC21_DAY22_HPP
#define AOC21_DAY22_HPP

#include <vector>
#include <string>
#include <utility>

namespace aoc21 {

    class Day22 {
        public:
            Day22(const std::vector<std::string> &input);
            std::string part1() const;
            std::string part2() const;
        private:
            static std::pair<int,int> parseBounds(const std::string &line);
            struct Instruction {
                bool state;
                std::pair<int,int> x;
                std::pair<int,int> y;
                std::pair<int,int> z;
                Instruction(bool _state, std::pair<int,int> _x, std::pair<int,int> _y, std::pair<int,int> _z);
            };
            struct Point {
                int x,y,z;
                Point(int _x, int _y, int _z);
                std::string to_string() const;
            };
            std::vector<Instruction> _instructions{};

    };

}

#endif


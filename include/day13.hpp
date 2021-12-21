#ifndef AOC21_DAY13_HPP
#define AOC21_DAY13_HPP

#include <vector>
#include <string>
#include <unordered_set>
#include <utility>
#include "utils.hpp"

namespace aoc21 {

    class Day13 {
        public:
            Day13(const std::vector<std::string> &input);
            std::string part1() const;
            std::string part2() const;
        private:
            struct Instruction {
                bool foldUp;
                int value;
            };
            std::unordered_set<std::pair<int,int>> _dots {};
            std::vector<Instruction> _instructions {};
    };

}

#endif


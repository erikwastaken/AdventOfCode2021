#ifndef AOC21_DAY08_HPP
#define AOC21_DAY08_HPP

#include <vector>
#include <string>
#include <array>

namespace aoc21 {

    class Day08 {
        public:
            Day08(const std::vector<std::string> &input);
            std::string part1() const;
            std::string part2() const;
        private:
            struct SignalSet {
                std::array<std::string,10> patterns;
                std::array<std::string,4> output;
            };
            std::vector<SignalSet> _signalSets;
            bool contains(const std::string &str, char c) const;
            std::string oldPart2() const;
            std::string newPart2() const;
    };

}

#endif


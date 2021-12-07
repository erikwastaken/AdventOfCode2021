#ifndef AOC21_DAY07_HPP
#define AOC21_DAY07_HPP

#include <string>
#include <vector>

namespace aoc21 {

    class Day07 {
        public:
            Day07(const std::string &input);
            std::string part1() const;
            std::string part2() const;
        private:
            std::vector<int> _initialPositions {};
            int _min;
            int _max;
            int totalLinearFuelConsumption(int destination) const;
            int totalIncrementalFuelConsumption(int destination) const;
    };

}

#endif


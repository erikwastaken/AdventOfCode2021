#ifndef AOC21_DAY17_HPP
#define AOC21_DAY17_HPP

#include <string>

namespace aoc21 {

    class Day17 {
        public:
            Day17(const std::string &input);
            std::string part1() const;
            std::string part2() const;
        private:
            int _minX {};
            int _maxX {};
            int _minY {};
            int _maxY {};
            bool isValid(int x, int y) const;
    };

}

#endif


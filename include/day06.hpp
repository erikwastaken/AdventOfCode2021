#ifndef AOC21_DAY06_HPP
#define AOC21_DAY06_HPP

#include <string>
#include <array>

namespace aoc21 {

    class Day06 {
        public:
            Day06(const std::string &input);
            std::string part1() const;
            std::string part2() const;
            unsigned long modelGrowth(int days) const;
        private:
            std::array<unsigned long,9> _initialState {};
    };

}

#endif


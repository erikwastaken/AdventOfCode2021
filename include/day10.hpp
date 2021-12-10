#ifndef AOC21_DAY10_HPP
#define AOC21_DAY10_HPP

#include <vector>
#include <string>
#include <stack>

namespace aoc21 {
    
    class Day10 {
        public:
            Day10(const std::vector<std::string> &input);
            std::string part1() const;
            std::string part2() const;
        private:
            int _errorPoints {0};
            long long _completionPoints {0};
            constexpr int points(char c) const;
            constexpr bool isOpen(char c) const;
            constexpr char match(char c) const;
            constexpr int completionPoints(char c) const;
            unsigned long calculateCompletionPoints(std::stack<char> &open) const;
    };

}

#endif


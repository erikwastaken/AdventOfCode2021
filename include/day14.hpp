#ifndef AOC21_DAY14_HPP
#define AOC21_DAY14_HPP

#include <string>
#include <vector>
#include <unordered_map>

namespace aoc21 {
    
    class Day14 {
        public:
            explicit Day14(const std::vector<std::string> &input);
            std::string part1() const;
            std::string part2() const;
        private:
            std::string _template {};
            std::unordered_map<std::string,std::string> _rules {};
            std::unordered_map<std::string,long long> step(int n) const;
            std::unordered_map<char,long long> countsPerChar(const std::unordered_map<std::string, long long>& polymerPairs) const;
            std::pair<long long, long long> minMax(const std::unordered_map<char, long long> &counts) const;
    };

}

#endif


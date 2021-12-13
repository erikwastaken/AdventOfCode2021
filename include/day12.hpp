#ifndef AOC21_DAY12_HPP
#define AOC21_DAY12_HPP

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

namespace aoc21 {

    class Day12 {
        public:
            Day12(const std::vector<std::string> &input);
            std::string part1() const;
            std::string part2() const;
        private:
            std::unordered_map<std::string, std::unordered_set<std::string>> _connections;
            class PathFinder {
                public:
                    explicit PathFinder(const std::unordered_map<std::string, std::unordered_set<std::string>> &connections);
                    void countPathsFrom(const std::string &from);
                    int pathCounter() const;
                    void allowSecondVisit();
                private:
                    std::unordered_map<std::string, std::unordered_set<std::string>> _connections;
                    std::unordered_set<std::string> _visited {};
                    int _pathCounter {};
                    bool _secondVisitAllowed {false};
                    std::string _secondVisit {};
                    void move(const std::string &from);
                    bool isLower(const std::string &str) const;
            };
    };

}

#endif


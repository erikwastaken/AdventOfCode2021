#ifndef AOC21_DAY09_HPP
#define AOC21_DAY09_HPP

#include <string>
#include <vector>
#include <unordered_set>
#include <utility>

namespace aoc21 {

    class Day09 {
        public:
            struct Point {
                int row, col;
                std::string to_string() const { return std::to_string(row) + "," + std::to_string(col); };
            };

            explicit Day09(const std::vector<std::string> &input);
            std::string part1() const;
            std::string part2() const;

        private:
            std::vector<std::vector<int>> _heatmap;
            bool isLocalMinimum(int row, int col) const;
            class BasinFinder {
                public:
                    BasinFinder(const std::vector<std::vector<int>> &heatmap, int row, int col);
                    void determineBasin(Point idx);
                    int getBasinSize() const;
                private:
                    const std::vector<std::vector<int>> &_heatmap;
                    std::unordered_set<std::string> _seen{};
            };
    };

    std::vector<Day09::Point> getAdjacent(const std::vector<std::vector<int>> &v, int row, int col);

}

#endif
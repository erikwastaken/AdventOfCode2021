#ifndef AOC21_DAY20_HPP
#define AOC21_DAY20_HPP

#include <vector>
#include <string>
#include <array>
#include <unordered_set>
#include "utils.hpp"

namespace aoc21 {

    class Day20 {
        public:
            Day20(const std::vector<std::string> &input);
            std::string part1() const;
            std::string part2() const;
        private:
            constexpr int translate(char c) const;
            class Image {
                public:
                    Image() = default;
                    Image(const std::unordered_set<std::pair<int,int>> &points, const std::array<int,512> &reference);
                    void enhance();
                    int numberOfPixels() const;
                private:
                    static constexpr int gridWidth {300};
                    static constexpr int gridLength {gridWidth * gridWidth};
                    static constexpr int startingPosition {100};
                    std::array<int,512> _reference {};
                    std::array<int,gridLength> _grid {};
                    std::pair<int,int> _window {startingPosition,startingPosition};
                    void updateWindow();
                    std::vector<int> getIndexes(int idx) const;
            };
            Image _image;
    };

}

#endif


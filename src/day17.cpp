#include "day17.hpp"
#include <cstdlib>
#include "utils.hpp"

aoc21::Day17::Day17(const std::string &input) {
    auto splits = splitString(input, ' ');
    auto xSplits = splitString(splits[2], '.');
    _minX = std::stoi(xSplits[0].substr(2));
    _maxX = std::stoi(splitString(xSplits[1],',')[0]);

    auto ySplits = splitString(splits[3], '.');
    _minY = std::stoi(ySplits[0].substr(2));
    _maxY = std::stoi(ySplits[1]);
}

std::string aoc21::Day17::part1() const {
    // the velocity decreases by 1 on each step;
    // therefore, for a given velocity the max height will be sum(range(0,velocity));
    // hence, the max allowed height such that the probe still falls into the
    // target area can be found by taking the lower end of the target area and
    // calculating sum(range(0,abs(lowerEnd+1))) for it; otherwise the probe could
    // not reach the target zone;
    auto maxHeightIndex = abs(_minY + 1);
    auto maxHeight = (maxHeightIndex + 1) * maxHeightIndex / 2;
    return std::to_string(maxHeight);
}

std::string aoc21::Day17::part2() const {
    auto count = 0;
    for (auto x = 1; x != _maxX + 1; ++x) {
        for (auto y = -abs(_minY); y != abs(_minY) + 1; ++y) {
            if (isValid(x,y))
                ++count;
        }
    }
    return std::to_string(count);
}

bool aoc21::Day17::isValid(int x, int y) const {
    auto sumX = x;
    auto sumY = y;
    while (!(sumX > _maxX || sumY < _minY)) {
        if (_minX <=sumX && sumX <= _maxX && _minY <= sumY && sumY <= _maxY) {
            return true;
        }
        if (x == 0) {
            if (sumX < _minX || sumX > _maxX)
                return false;
        }
        if (x > 0)
            sumX += --x;
        sumY += --y;
    }
    return false;
}

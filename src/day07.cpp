#include "day07.hpp"
#include "utils.hpp"
#include <numeric>
#include <limits>
#include <cstdlib>

aoc21::Day07::Day07(const std::string &input) {
    // set min and max to values that will be overwritten for sure;
    _min = std::numeric_limits<int>::max();
    _max = std::numeric_limits<int>::min();
    for (auto s : splitString(input, ',')) {
        auto number = std::stoi(s);
        _initialPositions.emplace_back(number);
        if (number < _min)
            _min = number;
        if (number > _max)
            _max = number;
    }
}

std::string aoc21::Day07::part1() const {
    auto minFuel = std::numeric_limits<int>::max();
    for (auto i=_min; i!=_max + 1; ++i) {
        auto currentFuel = totalLinearFuelConsumption(i);
        if (currentFuel < minFuel) {
            minFuel = currentFuel;
        }
    }
    return std::to_string(minFuel);
}

int aoc21::Day07::totalLinearFuelConsumption(int destination) const {
    auto sum = 0;
    for (auto p : _initialPositions) {
        sum += abs(p-destination);
    }
    return sum;
}

std::string aoc21::Day07::part2() const {
    auto minFuel = std::numeric_limits<int>::max();
    for (auto i=_min; i!=_max + 1; ++i) {
        auto currentFuel = totalIncrementalFuelConsumption(i);
        if (currentFuel < minFuel) {
            minFuel = currentFuel;
        }
    }
    return std::to_string(minFuel);
}

int aoc21::Day07::totalIncrementalFuelConsumption(int destination) const {
    auto sum = 0;
    for (auto p : _initialPositions) {
        auto distance = abs(p-destination);
        // Gauss' grade school formula
        auto fuelConsumption = ((distance + 1) * distance) / 2;
        sum += fuelConsumption;
    }
    return sum;
}

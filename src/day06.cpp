#include "day06.hpp"
#include "utils.hpp"
#include <numeric>
#include <array>

aoc21::Day06::Day06(const std::string &input) {
    auto splits = splitString(input, ',');
    // track the fish in an array (index == remaining days, value = number of fish with this many days
    for (const auto &s : splits) {
        ++_initialState[std::stoi(s)];
    }
}

std::string aoc21::Day06::part1() const {
    return std::to_string(modelGrowth(80));
}

std::string aoc21::Day06::part2() const {
    return std::to_string(modelGrowth(256));
}

unsigned long aoc21::Day06::modelGrowth(int days) const {
    auto fish = _initialState;
    for (auto i = 0; i != days; ++i) {
        auto tmp = fish[0];
        for (auto ii = 0; ii != fish.size() - 1; ++ii) {
            fish[ii] = fish[ii + 1];
        }
        // put the old fish back to 6 days and the new ones on 8 days
        fish[6] += tmp;
        fish[8] = tmp;
    }
    return std::accumulate(fish.begin(), fish.end(), 0ul);
}

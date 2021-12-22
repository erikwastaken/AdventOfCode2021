#include "day14.hpp"
#include "utils.hpp"

aoc21::Day14::Day14(const std::vector<std::string> &input) {
    _template = input[0];
    for (auto i = 2ul; i != input.size(); ++i) {
        auto splits = splitString(input[i], ' ');
        _rules[splits[0]] = splits[2][0]; // double subscript to get the char
    }
}

std::string aoc21::Day14::part1() const {
    auto polymerPairs = step(10);
    auto counts = countsPerChar(polymerPairs);
    auto [min, max] = minMax(counts);
    return std::to_string(max - min);
}

std::string aoc21::Day14::part2() const {
    auto polymerPairs = step(40);
    auto counts = countsPerChar(polymerPairs);
    auto [min, max] = minMax(counts);
    return std::to_string(max - min);
}

std::unordered_map<std::string,long long> aoc21::Day14::step(int n) const {
    auto polymerPairs = std::unordered_map<std::string,long long>();
    for (auto i = 0ul; i != _template.length() - 1; ++i) {
        auto key = _template.substr(i,2);
        ++polymerPairs[key];
    }
    for (auto i = 0; i != n; ++i) {
        auto current = std::unordered_map<std::string, long long>();
        for (const auto& [key,value] : polymerPairs) {
            if (_rules.contains(key)) {
                auto key1 = key.at(0) + _rules.at(key);
                auto key2 = _rules.at(key) + key.at(1);
                current[key1] += value;
                current[key2] += value;
            } else {
                current[key] += value;
            }
        }
        polymerPairs = current;
    }

    return polymerPairs;
}

std::unordered_map<char, long long>
aoc21::Day14::countsPerChar(const std::unordered_map<std::string, long long int>& polymerPairs) const {
    auto counts = std::unordered_map<char, long long>();
    for (const auto &[key,value] : polymerPairs) {
        auto c = key.at(0);
        // only count the first letter of each two-letter combination to avoid doubling the quantity
        counts[c] += value;
    }
    // add one to the count of the last letter in the template, because it will otherwise not be counted by the method above
    counts[*(--_template.end())] += 1;
    return counts;
}

std::pair<long long, long long> aoc21::Day14::minMax(const std::unordered_map<char, long long int> &counts) const {
    auto max = counts.at(_template[0]);
    auto min = counts.at(_template[0]);
    for (const auto &[key,value] : counts) {
        if (value < min)
            min = value;
        if (value > max)
            max = value;
    }
    return std::make_pair(min, max);
}


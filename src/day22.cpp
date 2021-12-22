#include "day22.hpp"
#include "utils.hpp"
#include <unordered_set>

aoc21::Day22::Day22(const std::vector<std::string> &input) {
    for (const auto &line : input) {
        auto splitAtSpace = splitString(line, ' ');
        auto state = (splitAtSpace[0] == "on") ? true : false;
        auto coordinateSplits = splitString(splitAtSpace[1], ',');
        auto x = parseBounds(coordinateSplits[0]);
        auto y = parseBounds(coordinateSplits[1]);
        auto z = parseBounds(coordinateSplits[2]);
        _instructions.emplace_back(Instruction(state,x,y,z));
    }
}

std::string aoc21::Day22::part1() const {
    auto on = std::unordered_set<std::string>();
    for (const auto &ins : _instructions) {
        for (auto x = std::max(-50,ins.x.first); x <= std::min(50,ins.x.second); ++x) {
            for (auto y = std::max(-50,ins.y.first); y <= std::min(50,ins.y.second); ++y) {
                for (auto z = std::max(-50,ins.z.first); z <= std::min(50,ins.z.second); ++z) {
                    auto p = Point(x,y,z);
                    if (ins.state) {
                        on.insert(p.to_string());
                    } else {
                        on.erase(p.to_string());
                    }
                }
            }
        }
    }
    return std::to_string(on.size());
}

std::string aoc21::Day22::part2() const {
    return "Not implemented";
}

aoc21::Day22::Instruction::Instruction(bool _state, std::pair<int,int> _x, std::pair<int,int> _y, std::pair<int,int> _z) :
    state(_state), x(_x), y(_y), z(_z) {};

aoc21::Day22::Point::Point(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {};

std::string aoc21::Day22::Point::to_string() const {
    return std::to_string(x) + "," + std::to_string(y) + "," + std::to_string(z);
}

std::pair<int,int> aoc21::Day22::parseBounds(const std::string &line) {
    auto lowUp = splitString(line,'.');
    auto lowerBound = std::stoi(lowUp[0].substr(2));
    auto upperBound = std::stoi(lowUp[1]);
    return std::make_pair(lowerBound, upperBound);
}

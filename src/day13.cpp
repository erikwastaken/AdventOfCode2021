#include "day13.hpp"
#include "utils.hpp"

aoc21::Day13::Day13(const std::vector<std::string> &input) {
    auto isInstruction = false;
    for (const auto &line : input) {
        if (line.empty()) {
            isInstruction = true;
            continue;
        }
        if (isInstruction) {
            auto splits = splitString(line, '=');
            Instruction ins;
            ins.foldUp = (splits[0] == "fold along y");
            ins.value = std::stoi(splits[1]);
            _instructions.push_back(ins);
        } else {
            auto splits = splitString(line, ',', [](std::string s) { return std::stoi(s); });
            _dots.insert(std::make_pair(splits[0],splits[1]));
        }
    }
}

std::string aoc21::Day13::part1() const {
    auto dots = std::unordered_set<std::pair<int,int>>();
    auto instruction = _instructions[0];
    for (const auto &dot : _dots) {
        if (instruction.foldUp) {
            if (dot.second < instruction.value) {
                dots.insert(dot);
            } else {
                dots.insert(std::make_pair(dot.first, 2 * instruction.value - dot.second));
            }
        } else {
            if (dot.first < instruction.value) {
                dots.insert(dot);
            } else {
                dots.insert(std::make_pair(2 * instruction.value - dot.first, dot.second));
            }
        }
    }
    return std::to_string(dots.size());
}

std::string aoc21::Day13::part2() const {
    auto prevDots = _dots;
    auto maxWidth = 0;
    auto maxHeight = 0;
    for (const auto &instruction : _instructions) {
        auto dots = std::unordered_set<std::pair<int,int>>();
        for (const auto &dot : prevDots) {
            if (instruction.foldUp) {
                if (dot.second < instruction.value) {
                    dots.insert(dot);
                } else {
                    dots.insert(std::make_pair(dot.first, 2 * instruction.value - dot.second));
                }
                maxHeight = instruction.value;
            } else {
                if (dot.first < instruction.value) {
                    dots.insert(dot);
                } else {
                    dots.insert(std::make_pair(2 * instruction.value - dot.first, dot.second));
                }
                maxWidth = instruction.value;
            }
        }
        prevDots = dots;
    }
    auto result = std::string();
    for (auto i = 0; i != maxHeight; ++i) {
        result += '\n';
        for (auto ii = 0; ii != maxWidth; ++ii) {
            char output = (prevDots.contains(std::make_pair(ii,i))) ? '#' : '.';
            result += output;
        }
    }
    return result;
}

#include "day10.hpp"
#include <stack>

aoc21::Day10::Day10(const std::vector<std::string> &input) {
    auto completionPoints = std::vector<unsigned long>();
    for (const auto &line : input) {
        auto opened = std::stack<char>();
        auto isCorrupted = false;
        for (auto c : line) {
            if (isOpen(c)) {
                opened.push(c);
            } else if (opened.empty() || c != match(opened.top())) {
                isCorrupted = true;
                _errorPoints += points(c);
                break; // disregard corrupted lines
            } else {
                opened.pop();
            }
        }
        if (!isCorrupted)
            completionPoints.push_back(calculateCompletionPoints(opened));
    }
    auto medianIdx = completionPoints.size() / 2;
    std::sort(completionPoints.begin(), completionPoints.end());
    _completionPoints = completionPoints[medianIdx];
}

std::string aoc21::Day10::part1() const {
    return std::to_string(_errorPoints);
}

std::string aoc21::Day10::part2() const {
    return std::to_string(_completionPoints);
}

constexpr int aoc21::Day10::points(char c) const {
    switch (c) {
        case ')': return 3;
        case ']': return 57;
        case '}': return 1197;
        case '>': return 25137;
        default:  return 0;
    }
}

constexpr bool aoc21::Day10::isOpen(char c) const {
    return c == '(' || c == '[' || c == '{' || c == '<';
}

constexpr char aoc21::Day10::match(char c) const {
    switch(c) {
        case '(': return ')';
        case '[': return ']';
        case '{': return '}';
        case '<': return '>';
        case ')': return '(';
        case ']': return '[';
        case '}': return '{';
        case '>': return '<';
        default: return c;
    }
}

unsigned long aoc21::Day10::calculateCompletionPoints(std::stack<char> &open) const {
    auto total = 0ul;
    while (!open.empty()) {
        auto c = open.top();
        total *= 5;
        total += completionPoints(c);
        open.pop();
    }
    return total;
}

constexpr int aoc21::Day10::completionPoints(char c) const {
    switch (match(c)) {
        case ')': return 1;
        case ']': return 2;
        case '}': return 3;
        case '>': return 4;
        default: return 0;
    }
}

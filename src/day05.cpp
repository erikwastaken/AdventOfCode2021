#include "day05.hpp"
#include "utils.hpp"
#include <cstdlib>

aoc21::Day05::Day05(const std::vector<std::string> &input) {
    for (const auto &inp : input) {
        auto s = splitString(inp, ' ');
        auto begin = splitString(s[0], ',');
        auto end = splitString(s[2],',');
        Point p1 = {std::stoi(begin[0]), std::stoi(begin[1])};
        Point p2 = {std::stoi(end[0]), std::stoi(end[1])};
        Line line = {p1,p2};
        _lines.emplace_back(line);
    }
}

std::string aoc21::Day05::part1() const {
    auto diagram = LineDiagram(_lines);
    return std::to_string(diagram.getIntersections(false));
}

std::string aoc21::Day05::part2() const {
    auto diagram = LineDiagram(_lines);
    return std::to_string(diagram.getIntersections(true));
}

aoc21::Day05::LineDiagram::LineDiagram(const std::vector<Line> &lines) {
    _lines = lines;
}

int aoc21::Day05::LineDiagram::getDrawnIntersections() const {
    int count = 0;
    for (const auto &it : _drawnPoints) {
        if (it.second > 1) {
            ++count;
        }
    }
    return count;
}

void aoc21::Day05::LineDiagram::drawPoint(int x, int y) {
    const Point lookUp {x, y};
    // if lookUp is not in the map, yet, its value will be initialized to 0 and then incremented
    ++_drawnPoints[lookUp.to_string()];
}

void aoc21::Day05::LineDiagram::drawLines(bool diagonals) {
    for (const auto &line : _lines) {
        if (line.begin.x == line.end.x) {
            auto x = line.begin.x;
            auto loopStart = (line.begin.y <= line.end.y) ? line.begin.y : line.end.y;
            auto loopEnd = (line.begin.y <= line.end.y) ? line.end.y : line.begin.y;
            for (auto i = loopStart; i != loopEnd + 1; ++i) {
                drawPoint(x, i);
            }
        } else if (line.begin.y == line.end.y) {
            auto y = line.begin.y;
            auto loopStart = (line.begin.x <= line.end.x) ? line.begin.x : line.end.x;
            auto loopEnd = (line.begin.x <= line.end.x) ? line.end.x : line.begin.x;
            for (auto i = loopStart; i != loopEnd + 1; ++i) {
                drawPoint(i, y);
            }
        } else if (diagonals && abs(line.begin.x - line.end.x) == abs(line.begin.y - line.end.y)) {
            auto lineLength = abs(line.begin.x - line.end.x);
            auto xFactor = (line.begin.x < line.end.x) ? 1 : -1;
            auto yFactor = (line.begin.y < line.end.y) ? 1 : -1;
            for (auto i = 0; i != lineLength + 1; ++i) {
                drawPoint(line.begin.x + (i * xFactor), line.begin.y + (i * yFactor));
            }
        }
    }
}

int aoc21::Day05::LineDiagram::getIntersections(bool diagonals) {
    drawLines(diagonals);
    return getDrawnIntersections();
}

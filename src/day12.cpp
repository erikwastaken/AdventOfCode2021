#include "day12.hpp"
#include "utils.hpp"
#include <algorithm>

aoc21::Day12::Day12(const std::vector<std::string> &input) {
    _connections = std::unordered_map<std::string, std::unordered_set<std::string>>();
    for (const auto &line : input) {
        auto splits = splitString(line, '-');
        if(splits[1] != "start" && splits[0] != "end")
            _connections[splits[0]].insert(splits[1]);
        if(splits[0] != "start" && splits[1] != "end")
            _connections[splits[1]].insert(splits[0]);
    }
}

std::string aoc21::Day12::part1() const {
    auto pf = PathFinder(_connections);
    pf.countPathsFrom("start");
    return std::to_string(pf.pathCounter());
}

std::string aoc21::Day12::part2() const {
    auto pf = PathFinder(_connections);
    pf.allowSecondVisit();
    pf.countPathsFrom("start");
    return std::to_string(pf.pathCounter());
}

aoc21::Day12::PathFinder::PathFinder(const std::unordered_map<std::string, std::unordered_set<std::string>>& connections) {
    _connections = connections;
}

void aoc21::Day12::PathFinder::move(const std::string &from) {
    if (from == "end") {
        ++_pathCounter;
        return;
    }
    if (from != "start") {
        auto lower = from; // give lower the appropriate length
        std::transform(from.begin(), from.end(), lower.begin(),
                       [](unsigned char c) -> unsigned char { return std::tolower(c); });
        if (lower == from && _visited.contains(from)) {
            if (_secondVisitAllowed && _secondVisit.empty()) {
                _secondVisit = lower;
            } else {
                return;
            }
        }
    }
    _visited.insert(from);
    for (auto &conn : _connections[from]) {
        move(conn);
    }
    if (_secondVisitAllowed && from == _secondVisit) {
        _secondVisit = std::string();
    } else {
        _visited.erase(from);
    }
}

int aoc21::Day12::PathFinder::pathCounter() const {
    return _pathCounter;
}

void aoc21::Day12::PathFinder::allowSecondVisit() {
    _secondVisitAllowed = true;
}

void aoc21::Day12::PathFinder::countPathsFrom(const std::string& from) {
    move(from);
}

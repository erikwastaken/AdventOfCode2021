#include "day09.hpp"
#include <algorithm>

aoc21::Day09::Day09(const std::vector<std::string> &input) {
    for (const auto &line : input) {
        auto tmp = std::vector<int>();
        for (auto c : line) {
            // subtract ASCII value of zero and convert to integer
            int i = c - '0';
            tmp.emplace_back(i);
        }
        _heatmap.emplace_back(tmp);
    }
}

std::string aoc21::Day09::part1() const {
    auto sum = 0;
    for (auto i = 0ul; i != _heatmap.size(); ++i) {
        for (auto ii=0ul; ii != _heatmap[i].size(); ++ii) {
            if (isLocalMinimum(i,ii)) {
                sum += _heatmap[i][ii] + 1;
            }
        }
    }
    return std::to_string(sum);
}

std::string aoc21::Day09::part2() const {
    auto basinSizes = std::vector<int>();
    for (auto i = 0ul; i != _heatmap.size(); ++i) {
        for (auto ii=0ul; ii != _heatmap[i].size(); ++ii) {
            if (isLocalMinimum(i,ii)) {
                auto bf = BasinFinder(_heatmap, i, ii);
                basinSizes.push_back(bf.getBasinSize());
            }
        }
    }
    std::sort(basinSizes.begin(),basinSizes.end(), std::greater<>());
    return std::to_string(basinSizes[0] * basinSizes[1] * basinSizes[2]);
}

bool aoc21::Day09::isLocalMinimum(int row, int col) const {
    for (const auto &p : getAdjacent(_heatmap, row, col)) {
        if (_heatmap[row][col] >= _heatmap[p.row][p.col])
            return false;
    }
    return true;
}

aoc21::Day09::BasinFinder::BasinFinder(const std::vector<std::vector<int>> &heatmap, int row, int col) : _heatmap(heatmap) {
    determineBasin({row, col});
}

void aoc21::Day09::BasinFinder::determineBasin(Point idx) {
    if (_seen.contains(idx.to_string()) || _heatmap[idx.row][idx.col] == 9)
        return;
    for (const auto &p : getAdjacent(_heatmap, idx.row, idx.col)) {
        _seen.insert(idx.to_string());
        determineBasin(p);
    }
}

int aoc21::Day09::BasinFinder::getBasinSize() const {
    return _seen.size();
}

std::vector<aoc21::Day09::Point> aoc21::getAdjacent(const std::vector<std::vector<int>> &v, int row, int col) {
    auto result = std::vector<Day09::Point>();
    if (row == 0) {
        if (col == 0) {
            result.push_back({row + 1,col});
            result.push_back({row,col + 1});
        } else if (col == (int) v[row].size() - 1) {
            result.push_back({row + 1,col});
            result.push_back({row,col - 1});
        } else {
            result.push_back({row + 1,col});
            result.push_back({row,col + 1});
            result.push_back({row,col - 1});
        }
    } else if (row == (int) v.size() - 1) {
        if (col == 0) {
            result.push_back({row - 1, col});
            result.push_back({row, col + 1});
        } else if (col == (int) v[row].size() - 1) {
            result.push_back({row - 1, col});
            result.push_back({row, col - 1});
        } else {
            result.push_back({row - 1, col});
            result.push_back({row, col + 1});
            result.push_back({row, col - 1});
        }
    } else {
        if (col == 0) {
            result.push_back({row + 1, col});
            result.push_back({row - 1, col});
            result.push_back({row, col + 1});
        } else if (col == (int) v[row].size() - 1) {
            result.push_back({row + 1, col});
            result.push_back({row - 1, col});
            result.push_back({row, col - 1});
        } else {
            result.push_back({row + 1, col});
            result.push_back({row - 1, col});
            result.push_back({row, col + 1});
            result.push_back({row, col - 1});
        }
    }
    return result;
}





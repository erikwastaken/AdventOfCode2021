#include "day20.hpp"

aoc21::Day20::Day20(const std::vector<std::string> &input) {
    std::array<int,512> reference {};
    std::unordered_set<std::pair<int,int>> points {};
    for (auto i = 0ul; auto c : input[0]) {
        reference[i++] = translate(c);
    }

    for (auto y = 2ul; y != input.size(); ++y) {
        for (auto x = 0; auto c : input[y]) {
            if (translate(c)) {
                points.insert(std::make_pair(x,y - 2));
            }
            ++x;
        }
    }

    _image = Image(points, reference);
}

std::string aoc21::Day20::part1() const {
    auto image = _image;
    image.enhance();
    image.enhance();
    return std::to_string(image.numberOfPixels());
}

std::string aoc21::Day20::part2() const {
    auto image = _image;
    for (auto i = 0; i != 50; ++i) {
        image.enhance();
    }
    return std::to_string(image.numberOfPixels());
}

constexpr int aoc21::Day20::translate(char c) const {
    return (c == '#') ? 1 : 0;
}

aoc21::Day20::Image::Image(const std::unordered_set<std::pair<int,int>> &points, const std::array<int,512> &reference) {
    _reference = reference;
    auto min = 0;
    auto max = 0;
    for (const auto &p : points) {
        // determine window size
        if (p.first < min)
            min = p.first;
        if (p.first > max)
            max = p.first;
        auto row = p.second + startingPosition;
        auto col = p.first + startingPosition;
        auto idx = row * gridWidth + col;
        _grid[idx] = 1;
    }
    _window.first = startingPosition + min;
    _window.second = startingPosition + max;
}

void aoc21::Day20::Image::enhance() {
    auto grid = _grid;
    for (auto i = 0ul; i != _grid.size(); ++i) {
        // flip the outer edge of the grid;
        if (getIndexes(i).size() != 9)
            grid[i] = 1;
        else {
            auto key = 0b0;
            for (auto shifter = 8; auto idx: getIndexes(i)) {
                if (_grid.at(idx))
                    key |= 1 << shifter;
                --shifter;
            }
            grid[i] = _reference.at(key);
        }
    }
    _grid = grid;
    updateWindow();
}

int aoc21::Day20::Image::numberOfPixels() const {
    auto sum = 0;
    for (auto row = _window.first; row != _window.second + 1; ++row) {
        for (auto col = _window.first; col != _window.second + 1; ++col) {
            auto idx = row * gridWidth + col;
            sum += _grid.at(idx);
        }
    }
    return sum;
}

void aoc21::Day20::Image::updateWindow() {
    --_window.first;
    ++_window.second;
}

std::vector<int> aoc21::Day20::Image::getIndexes(int idx) const {
    auto result = std::vector<int>();
    auto row = gridWidth;
    auto col = gridWidth;
    if (idx == 0) {
        result.push_back(idx);
        result.push_back(1);
        result.push_back(col);
        result.push_back(col + 1);
    } else if (idx < col - 1) {
        result.push_back(idx - 1);
        result.push_back(idx);
        result.push_back(idx + 1);
        result.push_back(idx + col - 1);
        result.push_back(idx + col);
        result.push_back(idx + col + 1);
    } else if (idx == col - 1) {
        result.push_back(idx - 1);
        result.push_back(idx);
        result.push_back(idx + col - 1);
        result.push_back(idx + col);
    } else if (idx == (col - 1) * row) {
        result.push_back(idx - col);
        result.push_back(idx - col - 1);
        result.push_back(idx);
        result.push_back(idx + 1);
    } else if ((col - 1) * row < idx && idx < col * row - 1) {
        result.push_back(idx - 1);
        result.push_back(idx);
        result.push_back(idx + 1);
        result.push_back(idx - col - 1);
        result.push_back(idx - col);
        result.push_back(idx - col + 1);
    } else if (idx == col * row - 1) {
        result.push_back(idx - 1);
        result.push_back(idx - col - 1);
        result.push_back(idx - col);
        result.push_back(idx);
    } else if (idx % row == 0) {
        result.push_back(idx - col + 1);
        result.push_back(idx - col);
        result.push_back(idx);
        result.push_back(idx + 1);
        result.push_back(idx + col);
        result.push_back(idx + col + 1);
    } else if (idx % row == row - 1) {
        result.push_back(idx - col - 1);
        result.push_back(idx - col);
        result.push_back(idx - 1);
        result.push_back(idx);
        result.push_back(idx + col);
        result.push_back(idx + col - 1);
    } else {
        result.push_back(idx - col - 1);
        result.push_back(idx - col);
        result.push_back(idx - col + 1);
        result.push_back(idx - 1);
        result.push_back(idx);
        result.push_back(idx + 1);
        result.push_back(idx + col - 1);
        result.push_back(idx + col);
        result.push_back(idx + col + 1);
    }
    return result;
}

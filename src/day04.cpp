#include "day04.hpp"
#include <string>
#include <vector>
#include "exceptions.hpp"
#include <unordered_set>
#include "utils.hpp"

aoc21::Day04::Day04(const std::vector<std::string> &input) {
    auto const numberEndIterator = std::find(input.begin(), input.end(), "");
    fillNumbers(input, numberEndIterator);
    fillBoards(input, numberEndIterator);
}

void aoc21::Day04::fillBoards(const std::vector<std::string> &input,
                              const std::vector<std::string, std::allocator<std::string>>::const_iterator &numberEndIterator) {
    auto buffer = std::vector<std::string>();
    for (auto it = numberEndIterator + 1; it != input.end(); ++it) {
        if ((*it).empty()) {
            if (!buffer.empty()) {
                _boards.emplace_back(BingoBoard(buffer));
                buffer = std::vector<std::string>();
            }
            continue;
        } else {
            buffer.emplace_back(*it);
        }
    }
    if (!buffer.empty()) {
        _boards.emplace_back(BingoBoard(buffer));
    }
}

void aoc21::Day04::fillNumbers(const std::vector<std::string> &input,
                               const std::vector<std::string, std::allocator<std::string>>::const_iterator &numberEndIterator) {
    for (auto it = input.begin(); it != numberEndIterator; ++it) {
        for (auto num: parseBingoNumbers(*it)) {
            _numbers.push_back(num);
        }
    }
}

std::string aoc21::Day04::part1() const {
    auto boards = _boards;
    for (auto number : _numbers) {
        for (auto& board : boards) {
            board.mark(number);
            if (board.isComplete()) {
                return std::to_string(board.calculatePoints() * number);
            }
        }
    }
    throw AoCException("No winner");
}

std::string aoc21::Day04::part2() const {
    auto boards = _boards;
    auto completed = std::unordered_set<int>();
    int lastCompletedIdx = -1;
    int score = 0;
    for (auto number : _numbers) {
        for (auto i=0; i!= boards.size(); ++i) {
            if (completed.contains(i)) {
                continue;
            }
            boards[i].mark(number);
            if (boards[i].isComplete()) {
                completed.insert(i);
                lastCompletedIdx = i;
            }
        }
        if (completed.size() == boards.size()) {
            score = number * boards[lastCompletedIdx].calculatePoints();
            break;
        }
    }
    return std::to_string(score);
}

std::vector<int> aoc21::parseBingoNumbers(const std::string &input) {
    auto numbers = std::vector<int>();
    for (const auto &s : splitString(input, ',')) {
        numbers.emplace_back(std::stoi(s));
    }
    return numbers;
}

aoc21::BingoBoard::BingoBoard(const std::vector<std::string> &input) {
    if (input.size() > 5) throw AoCException("Bingo Board overflow");
    for (auto i = -1; const auto &line: input) {
        for (const auto &s : splitString(line, ' ')) {
            _numbers[++i] = std::stoi(s);
        }
    }
}

void aoc21::BingoBoard::mark(int calledNumber) {
    for (auto i = 0; i != 25; ++i) {
        if (_numbers[i] == calledNumber) {
            auto row = i / 5;
            auto col = i % 5;
            markPosition(row, col);
        }
    }
}

void aoc21::BingoBoard::markPosition(int row, int col) {
    _markedRows[row] |= (1 << (4 - col));
    _markedCols[col] |= (1 << (4 - row));
}

bool aoc21::BingoBoard::isComplete() const {
    for (auto i = 0; i != 5; ++i) {
        if (_markedRows[i] == FULL || _markedCols[i] == FULL)
            return true;
    }
    return false;
}

int aoc21::BingoBoard::calculatePoints() const {
    if (!isComplete()) throw AoCException("Board not complete");
    auto result = 0;
    for (auto i=0; i!=25; ++i) {
        auto row = i / 5;
        auto col = i % 5;
        if (!isPositionMarked(row, col)) {
            result += _numbers[i];
        }
    }
    return result;
}

bool aoc21::BingoBoard::isPositionMarked(int row, int col) const {
    return (_markedRows[row] >> (4 - col) & 1) == 1;
}

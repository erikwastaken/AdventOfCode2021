#include "day04.hpp"
#include <string>
#include <vector>
#include "exceptions.hpp"

aoc21::Day04::Day04(const std::vector<std::string>& input) {
  auto const numberEndIterator = std::find(input.begin(), input.end(), "");
  for (auto it = input.begin(); it!=numberEndIterator; ++it) {
    for (auto num : parseBingoNumbers(*it)) {
      this->_numbers.push_back(num);
    }
  }
}

std::string aoc21::Day04::part1() const {
  return "";
}

std::string aoc21::Day04::part2() const {
  return "";
}

std::vector<int> aoc21::parseBingoNumbers(const std::string& input) {
  auto numbers = std::vector<int>();
  auto buffer = std::string();
  for (auto c : input) {
    if (c == ',') {
      numbers.push_back(std::stoi(buffer));
      buffer = std::string();
    } else {
      buffer += c;
    }
  }
  if (buffer.length() != 0) {
    numbers.push_back(std::stoi(buffer));
  }
  return numbers;
}

aoc21::BingoBoard::BingoBoard(const std::vector<std::string> &input) {
    if (input.size() > 5) throw AoCException("Bingo Board overflow");
    for (auto i=-1; const auto& line : input) {
        auto buffer = std::string();
        for (auto c : line) {
            if (c==' ') {
                if (buffer.length() == 0) {
                    continue;
                } else {
                    this->_numbers[++i] = std::stoi(buffer);
                    buffer = std::string();
                }
            } else {
                buffer += c;
            }
        }
        if (buffer.length() != 0) {
            this->_numbers[++i] = std::stoi(buffer);
        }
    }
}

void aoc21::BingoBoard::mark(int calledNumber) {
    for (auto i=0; i!=25; ++i) {
        if (_numbers[i] == calledNumber) {
            auto row = i / 5;
            auto col = i % 5;
            _markedRows[row] |= ( 1 << (4 - col) );
            _markedCols[col] |= ( 1 << (4 - row) );
        }
    }
}

bool aoc21::BingoBoard::isComplete() {
    for (auto i=0; i!=5; ++i) {
        if (_markedRows[i] == 0b11111 || _markedCols[i] == 0b11111)
            return true;
    }
    return false;
}

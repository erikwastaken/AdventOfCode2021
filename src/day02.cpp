#include "day02.hpp"
#include "exceptions.hpp"

aoc21::Day02::Day02(const std::vector<std::string>& input) {
  _position.x = 0;
  _position.y = 0;
  for (const auto& line : input) {
    this->_instructions.push_back(parseInputLine(line));
  }
}

std::string aoc21::Day02::part1() {
  for (const auto& ins : _instructions) {
    if (ins.direction == "forward") {
      _position.x += ins.distance;
    } else if (ins.direction == "down") {
      _position.y += ins.distance;
    } else if (ins.direction == "up") {
      _position.y -= ins.distance;
    } else {
      throw AoCException("instruction not supported");
    }
  }
  int res = _position.x * _position.y;
  return std::to_string(res);
}

aoc21::Instruction aoc21::Day02::parseInputLine(const std::string& line) {
  int splitPoint = line.find(" ");
  Instruction result;
  result.direction = line.substr(0,splitPoint);
  result.distance = std::stoi(line.substr(splitPoint));
  return result;
}

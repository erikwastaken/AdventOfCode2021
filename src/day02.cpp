#include "day02.hpp"
#include "exceptions.hpp"

aoc21::Day02::Day02(const std::vector<std::string>& input) {
  for (const auto& line : input) {
    this->_instructions.push_back(parseInputLine(line));
  }
}

std::string aoc21::Day02::part1() const {
  Point position;
  position.x = 0;
  position.y = 0;
  for (const auto& ins : _instructions) {
    if (ins.direction == "forward") {
      position.x += ins.distance;
    } else if (ins.direction == "down") {
      position.y += ins.distance;
    } else if (ins.direction == "up") {
      position.y -= ins.distance;
    } else {
      throw AoCException("instruction not supported");
    }
  }
  int res = position.x * position.y;
  return std::to_string(res);
}

std::string aoc21::Day02::part2() const {
  Point position;
  position.x = 0;
  position.y = 0;
  int aim = 0;
  for (const auto& ins : _instructions) {
    if (ins.direction == "forward") {
      position.x += ins.distance;
      position.y += aim * ins.distance;
    } else if (ins.direction == "down") {
      aim += ins.distance;
    } else if (ins.direction == "up") {
      aim -= ins.distance;
    } else {
      throw AoCException("instruction not supported");
    }
  }
  int res = position.x * position.y;
  return std::to_string(res);
}

aoc21::Instruction aoc21::Day02::parseInputLine(const std::string& line) {
  int splitPoint = line.find(" ");
  Instruction result;
  result.direction = line.substr(0,splitPoint);
  result.distance = std::stoi(line.substr(splitPoint));
  return result;
}

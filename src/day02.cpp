#include "day02.hpp"
#include "exceptions.hpp"

aoc21::Day02::Day02(const std::vector<std::string>& input) {
  for (const auto& line : input) {
    this->_instructions.push_back(parseInputLine(line));
  }
}

std::string aoc21::Day02::part1() const {
  int hpos = 0;
  int depth = 0;
  for (const auto& ins : _instructions) {
    if (ins.direction == "forward") {
      hpos += ins.distance;
    } else if (ins.direction == "down") {
      depth += ins.distance;
    } else if (ins.direction == "up") {
      depth -= ins.distance;
    } else {
      throw AoCException("instruction not supported");
    }
  }
  return std::to_string(hpos * depth);
}

std::string aoc21::Day02::part2() const {
  int hpos = 0;
  int depth = 0;
  int aim = 0;
  for (const auto& ins : _instructions) {
    if (ins.direction == "forward") {
      hpos += ins.distance;
      depth += aim * ins.distance;
    } else if (ins.direction == "down") {
      aim += ins.distance;
    } else if (ins.direction == "up") {
      aim -= ins.distance;
    } else {
      throw AoCException("instruction not supported");
    }
  }
  return std::to_string(hpos*depth);
}

aoc21::Day02::Instruction aoc21::Day02::parseInputLine(const std::string& line) const {
  int splitPoint = line.find(" ");
  Instruction result;
  result.direction = line.substr(0,splitPoint);
  result.distance = std::stoi(line.substr(splitPoint));
  return result;
}

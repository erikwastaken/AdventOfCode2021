#include <iostream>
#include <memory>
#include <cstdlib>
#include "advent_day.h"
#include "default_day.h"
#include "file_reader.h"

std::unique_ptr<AdventDay> createDay(int day, std::string path);
std::unique_ptr<AdventDay> createDayWithDefaultPath(int num);
int parseCommandLineArguments(int argc, char* argv[]);
int getDayFromUser();

class AoCException : public std::exception {
  public:
    AoCException(std::string s) : _msg(s) {};
    ~AoCException() {};
    const char* what() const noexcept override { return _msg.c_str(); };
  private:
    std::string _msg;
};

int main(int argc, char* argv[]) {
  try {
    std::unique_ptr<AdventDay> day;
    switch (argc) {
      case 3:
        day = createDay(std::atoi(argv[1]), argv[2]);
        break;
      case 2:
        day = createDayWithDefaultPath(std::atoi(argv[1]));
        break;
      default:
        day = createDayWithDefaultPath(getDayFromUser());
    }
    std::cout << "Part1: " << day->part1() << std::endl;
    std::cout << "Part2: " << day->part2() << std::endl;
  } catch (AoCException& e) {
    std::cout << e.what() << std::endl;
  }
}

std::unique_ptr<AdventDay> createDay(int day, std::string path) {
  try {
    auto fr = FileReader(path);
    switch (day) {
      default: return std::unique_ptr<AdventDay>{ new DefaultDay() };
    }
  } catch (FileReaderException& e) {
    throw AoCException(e.what());
  }
}

std::unique_ptr<AdventDay> createDayWithDefaultPath(int num) {
  std::string path {"inputs/inputDay" + std::to_string(num) + ".txt"};
  return createDay(num, path);
}

int getDayFromUser() {
  while (true) {
    std::string d {};
    std::cout << "Please provide the day: ";
    std::cin >> d;
    try {
      int n = std::stoi(d);
      if (0 < n && n < 26) return n;
    } catch (std::invalid_argument) {
      continue;
    }
  }
}

#include <iostream>
#include <memory>
#include <cstdlib>
#include "advent_day.h"
#include "default_day.h"
#include "file_reader.h"

std::unique_ptr<AdventDay> createDay(int day);
int parseCommandLineArguments(int argc, char* argv[]);
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
    int num = parseCommandLineArguments(argc, argv);
    auto day = createDay(num);
    std::cout << "Day" << num << std::endl;
    std::cout << "Part1: " << day->part1() << std::endl;
    std::cout << "Part2: " << day->part2() << std::endl;
  } catch (AoCException& e) {
    std::cout << e.what() << std::endl;
  }
}

std::unique_ptr<AdventDay> createDay(int day) {
  try {
    std::string inputPath = "inputs/inputDay" + std::to_string(day) + ".txt";
    auto fr = FileReader(inputPath);
    switch (day) {
      default: return std::unique_ptr<AdventDay>{ new DefaultDay() };
    }
  } catch (FileReaderException& e) {
    throw AoCException(e.what());
  }
}

int getDayNumber() {
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

int parseCommandLineArguments(int argc, char* argv[]) {
  if (argc < 2) return getDayNumber();
  else return std::atoi(argv[1]);
}

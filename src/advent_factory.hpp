#ifndef ADVENT_FACTORY_HPP
#define ADVENT_FACTORY_HPP
#include <iostream>
#include <memory>
#include <cstdlib>
#include "advent_day.hpp"
#include "default_day.hpp"
#include "file_reader.hpp"
#include "exceptions.hpp"

namespace aoc21 {

  std::unique_ptr<AdventDay> createDay(const int day, const std::string& path) {
    try {
      auto fr = FileReader(path);
      switch (day) {
        default: return std::make_unique<DefaultDay>();
      }
    } catch (FileReaderException& e) {
      throw FactoryException(e.what());
    }
  }

  std::unique_ptr<AdventDay> createDayWithDefaultPath(const int num) {
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

  std::unique_ptr<AdventDay> createDayFromCommandLine(int argc, char* argv[]) {
    switch (argc) {
      case 3:
        return createDay(std::atoi(argv[1]), argv[2]);
      case 2:
        return createDayWithDefaultPath(std::atoi(argv[1]));
      default:
        return createDayWithDefaultPath(getDayFromUser());
    }
  }

}

#endif

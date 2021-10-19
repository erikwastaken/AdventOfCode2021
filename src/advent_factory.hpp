#ifndef ADVENT_FACTORY_H
#define ADVENT_FACTORY_H
#include <iostream>
#include <memory>
#include <cstdlib>
#include "advent_day.hpp"
#include "default_day.hpp"
#include "file_reader.hpp"
#include "exceptions.hpp"

class AdventFactory {
  public:
    std::unique_ptr<AdventDay> createDay(const int day, const std::string& path) const;
    std::unique_ptr<AdventDay> createDayWithDefaultPath(const int num) const;
    std::unique_ptr<AdventDay> createDayFromCommandLine(int argc, char* argv[]) const;
  private:
    int getDayFromUser() const;
};

#endif

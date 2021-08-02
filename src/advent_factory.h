#ifndef ADVENT_FACTORY_H
#define ADVENT_FACTORY_H
#include <iostream>
#include <memory>
#include <cstdlib>
#include "advent_day.h"
#include "default_day.h"
#include "file_reader.h"
#include "exceptions.h"

class AdventFactory {
  public:
    std::unique_ptr<AdventDay> createDay(int day, std::string path) const;
    std::unique_ptr<AdventDay> createDayWithDefaultPath(int num) const;
    std::unique_ptr<AdventDay> createDayFromCommandLine(int argc, char* argv[]) const;
  private:
    int getDayFromUser() const;
};
#endif

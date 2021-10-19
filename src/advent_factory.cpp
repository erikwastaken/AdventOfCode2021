#include "advent_factory.hpp"

std::unique_ptr<AdventDay> AdventFactory::createDay(const int day, const std::string& path) const {
  try {
    auto fr = FileReader(path);
    switch (day) {
      default: return std::make_unique<DefaultDay>();
    }
  } catch (FileReaderException& e) {
    throw FactoryException(e.what());
  }
}

std::unique_ptr<AdventDay> AdventFactory::createDayWithDefaultPath(const int num) const {
  std::string path {"inputs/inputDay" + std::to_string(num) + ".txt"};
  return createDay(num, path);
}

int AdventFactory::getDayFromUser() const {
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

std::unique_ptr<AdventDay> AdventFactory::createDayFromCommandLine(int argc, char* argv[]) const {
  switch (argc) {
    case 3:
      return createDay(std::atoi(argv[1]), argv[2]);
    case 2:
      return createDayWithDefaultPath(std::atoi(argv[1]));
    default:
      return createDayWithDefaultPath(getDayFromUser());
  }
}

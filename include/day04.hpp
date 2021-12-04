#ifndef DAY04_HPP
#define DAY04_HPP
#include <string>
#include <vector>
#include <array>

namespace aoc21 {
  
  std::vector<int> parseBingoNumbers(const std::string&);

  class BingoBoard {
    public:
      explicit BingoBoard(const std::vector<std::string>& input);
      void mark(int);
      bool isComplete();
      int calculatePoints();

    private:
      std::array<int,25> _numbers {};
      std::array<int,5> _markedRows {0b00000,0b00000, 0b00000, 0b00000, 0b00000};
      std::array<int,5> _markedCols {0b00000,0b00000, 0b00000, 0b00000, 0b00000};
  };

  class Day04 {
    public:
      explicit Day04(const std::vector<std::string>&);
      std::string part1();
      std::string part2() const;
    private:
      std::vector<int> _numbers {};
      std::vector<BingoBoard> _boards {};
  };

}

#endif


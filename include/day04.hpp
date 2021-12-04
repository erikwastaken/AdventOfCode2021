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
      bool isComplete() const;
      int calculatePoints() const;

    private:
      static constexpr int FULL = 0b11111;
      static constexpr int EMPTY = 0b00000;
      std::array<int,25> _numbers {};
      std::array<int,5> _markedRows {EMPTY,EMPTY, EMPTY, EMPTY, EMPTY};
      std::array<int,5> _markedCols {EMPTY,EMPTY, EMPTY, EMPTY, EMPTY};
      void markPosition(int row, int col);
      bool isPositionMarked(int row, int col) const;
  };

  class Day04 {
    public:
      explicit Day04(const std::vector<std::string>&);
      std::string part1() const;
      std::string part2() const;
    private:
      std::vector<int> _numbers {};
      std::vector<BingoBoard> _boards {};
      void fillNumbers(const std::vector<std::string> &input,
                       const std::vector<std::string, std::allocator<std::string>>::const_iterator &numberEndIterator);
      void fillBoards(const std::vector<std::string> &input,
                      const std::vector<std::string, std::allocator<std::string>>::const_iterator &numberEndIterator);
  };

}

#endif


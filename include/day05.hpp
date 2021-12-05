#ifndef AOC21_DAY05_HPP
#define AOC21_DAY05_HPP

#include <string>
#include <vector>
#include <unordered_map>

namespace aoc21 {


  class Day05 {
    public:
      explicit Day05(const std::vector<std::string> &input);
      std::string part1() const;
      std::string part2() const;
    private:
      struct Point {
          int x,y;
          std::string to_string() const { return std::to_string(x) + "," + std::to_string(y); };
      };

      struct Line {
          Point begin;
          Point end;
      };

      class LineDiagram {
        public:
          explicit LineDiagram(const std::vector<Line> &lines);
          int getIntersections(bool diagonals);
        private:
          std::vector<Line> _lines {};
          std::unordered_map<std::string,int> _drawnPoints {};
          void drawPoint(int x, int y);
          int getDrawnIntersections() const;
          void drawLines(bool diagonals);
      };
      std::vector<Line> _lines {};
  };

}
#endif //AOC21_DAY05_HPP

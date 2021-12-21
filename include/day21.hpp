#ifndef AOC21_DAY21_HPP
#define AOC21_DAY21_HPP

#include <string>
#include <vector>

namespace aoc21 {

    class Day21 {
        public:
            explicit Day21(const std::vector<std::string> &input);
            std::string part1() const;
            std::string part2() const;
        private:
            int _p1Start {0};
            int _p2Start {0};
            struct Player {
                int position {0};
                int score {0};
                constexpr explicit Player(int pos) : position(pos) {};
                constexpr void move(int n);
            };
            static constexpr int dd100(int n) ;
            static constexpr int moveBy(int curr, int by) ;
            static constexpr int possibilities(int number);
            constexpr std::pair<int,int> play(int p1, int p2) const;
            constexpr void playDirac(const Player &p1, const Player &p2, long long *winsP1, long long *winsP2, bool isP1, long long times) const;
    };

}

#endif


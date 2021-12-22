#include "day21.hpp"

aoc21::Day21::Day21(const std::vector<std::string> &input) {
    _p1Start = input[0][input[0].length() - 1] - '0';
    _p2Start = input[1][input[1].length() - 1] - '0';
}

std::string aoc21::Day21::part1() const {
    auto [losingPoints, rolls] = play(_p1Start, _p2Start);
    return std::to_string(losingPoints * rolls);
}

std::string aoc21::Day21::part2() const {
    auto p1 = Player(_p1Start);
    auto p2 = Player(_p2Start);
    auto winsP1 = 0ll;
    auto winsP2 = 0ll;
    playDirac(p1, p2, &winsP1, &winsP2, true, 1ll);
    return std::to_string(std::max(winsP1, winsP2));
}

constexpr int aoc21::Day21::dd100(int n) {
    return (n == 100) ? n : n % 100;
}

constexpr int aoc21::Day21::moveBy(int curr, int by) {
    return (curr + by - 1) % 10 + 1;
}

constexpr std::pair<int, int> aoc21::Day21::play(int position1, int position2) const {
    auto p1 = Player(position1);
    auto p2 = Player(position2);
    auto rolls = 0;

    while (!(p1.score > 999 || p2.score > 999)) {
        auto r1 = dd100(++rolls);
        auto r2 = dd100(++rolls);
        auto r3 = dd100(++rolls);
        if (rolls % 2 == 1) {
            p1.move(r1 + r2 + r3);
        } else {
            p2.move(r1 + r2 + r3);
        }
    }
    auto losingPoints = std::min(p1.score, p2.score);
    return std::make_pair(losingPoints, rolls);
}

constexpr void
aoc21::Day21::playDirac(const aoc21::Day21::Player &p1, const aoc21::Day21::Player &p2, long long int *winsP1, long long int *winsP2,
                        bool isP1, long long times) const {
    if (p1.score >= 21) {
        *winsP1 += times;
        return;
    } else if (p2.score >= 21) {
        *winsP2 += times;
        return;
    } else {
        if (isP1) {
            for (auto i = 3; i != 10; ++i) {
                auto p11 = p1;
                p11.move(i);
                playDirac(p11, p2, winsP1, winsP2, false, times * possibilities(i));
            }
        } else {
            for (auto i = 3; i != 10; ++i) {
                auto p22 = p2;
                p22.move(i);
                playDirac(p1, p22, winsP1, winsP2, true, times * possibilities(i));
            }
        }
    }
}

constexpr int aoc21::Day21::possibilities(int number) {
    switch(number) {
        case 3: return 1;
        case 4: return 3;
        case 5: return 6;
        case 6: return 7;
        case 7: return 6;
        case 8: return 3;
        case 9: return 1;
        default: return 0;
    }
}

constexpr void aoc21::Day21::Player::move(int n) {
    position = moveBy(position, n);
    score += position;
}

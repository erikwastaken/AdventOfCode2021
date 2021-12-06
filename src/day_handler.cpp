#include "day_handler.hpp"
#include "utils.hpp"
#include "default_day.hpp"
#include "day01.hpp"
#include "day02.hpp"
#include "day03.hpp"
#include "day04.hpp"
#include "day05.hpp"
#include "day06.hpp"
#include <chrono>

template<aoc21::Day T>
void aoc21::execute(const T& day) {
    auto t0 = std::chrono::high_resolution_clock::now();
    std::cout << "Part1: " << day.part1() << '\n';
    auto t1 = std::chrono::high_resolution_clock::now();
    auto diff1 = std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0);
    std::cout << "Executed in " << diff1.count() << "ms\n";
    std::cout << "Part2: " << day.part2() << '\n';
    auto t2 = std::chrono::high_resolution_clock::now();
    auto diff2 = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
    std::cout << "Executed in " << diff2.count() << "ms\n";
}

void aoc21::runDay(const int day, const std::string &path) {
    switch (day) {
        case 1:
            execute(aoc21::Day01(aoc21::getFileContents(path)));
            break;
        case 2:
            execute(aoc21::Day02(aoc21::getFileContents(path)));
            break;
        case 3:
            execute(aoc21::Day03(aoc21::getFileContents(path)));
            break;
        case 4:
            execute(aoc21::Day04(aoc21::getFileContents(path)));
            break;
        case 5:
            execute(aoc21::Day05(aoc21::getFileContents(path)));
            break;
        case 6:
            execute(aoc21::Day06(aoc21::getFileContents(path)[0]));
            break;
        default:
            execute(aoc21::DefaultDay());
    }
}

#include "day08.hpp"
#include "utils.hpp"
#include <unordered_map>
#include <array>
#include <algorithm>

aoc21::Day08::Day08(const std::vector<std::string> &input) {
    for (const auto &line : input) {
        auto s1 = splitString(line, '|');
        SignalSet s;
        for (auto i = -1; const auto &p : splitString(s1[0], ' ')) {
            s.patterns[++i] = p;
            sort(s.patterns[i].begin(), s.patterns[i].end());
        }
        for (auto i = -1; const auto &o : splitString(s1[1], ' ')) {
            s.output[++i] = o;
            sort(s.output[i].begin(), s.output[i].end());
        }
        _signalSets.emplace_back(s);
    }
}

std::string aoc21::Day08::part1() const {
    auto count = 0;
    for (const auto &s : _signalSets) {
        for (const auto &o : s.output) {
            if (o.length() == 2 || o.length() == 3 || o.length() == 4 || o.length() == 7) {
                ++count;
            }
        }
    }
    return std::to_string(count);
}

std::string aoc21::Day08::part2() const {
    return newPart2();
}

bool aoc21::Day08::contains(const std::string &str, char c) const {
    return str.find(c) != std::string::npos;
}

std::string aoc21::Day08::oldPart2() const {
    auto sum = 0;
    for (const auto &s : _signalSets) {
        char top = ' ';
        char bottom = ' ';
        char middle = ' ';
        char upperLeft = ' ';
        char lowerLeft = ' ';
        char upperRight = ' ';
        char lowerRight = ' ';
        // get immediately identifiable numbers
        auto one = std::string();
        auto four = std::string();
        auto seven = std::string();
        auto eight = std::string();
        for (const auto &p : s.patterns) {
            switch (p.length()) {
                case 2:
                    one = p;
                    break;
                case 3:
                    seven = p;
                    break;
                case 4:
                    four = p;
                    break;
                case 7:
                    eight = p;
                    break;
            }
        }
        // the difference between 7 and 1 is the top segment
        for (auto c : seven) {
            if (!contains(one,c)) {
                top = c;
                break;
            }
        }

        auto three = std::string();
        for (const auto &p : s.patterns) {
            if (p.length() == 5) {
                // the only 5-segment number that contains 1 is 3;
                if (contains(p, one[0]) && contains(p, one[1])) {
                    three = p;
                    break;
                }
            }
        }

        // bottom is 3 without 4 without top
        for (auto c : three) {
            if (!contains(four,c) && c != top) {
                bottom = c;
                break;
            }
        }

        // upper left is 4 without 3
        for (auto c : four) {
            if (!contains(three,c)) {
                upperLeft = c;
                break;
            }
        }

        // 5 is the only 5-segment that contains upper left
        // 2 is the only remaining 5-segment
        auto two = std::string();
        auto five = std::string();
        for (const auto &p : s.patterns) {
            if (p.length() == 5) {
                if (contains(p,upperLeft)) {
                    five = p;
                } else if (p != three) {
                    two = p;
                }
            }
        }

        // lower right is the intersection of 5 and 1
        for (auto c : one) {
            if (contains(five,c)) {
                lowerRight = c;
            } else {
                upperRight = c;
            }
        }

        // 5 without top, bottom, upper left, and lower right is middle
        for (auto c : five) {
            if (c != top && c != bottom && c != upperLeft && c != lowerRight) {
                middle = c;
            }
        }

        // lower left is the only remaining segment
        for (auto c : eight) {
            if (c != top &&
                c != bottom &&
                c != upperLeft &&
                c != lowerRight &&
                c != upperRight &&
                c != middle) {
                lowerLeft = c;
            }
        }

        // knowing the char for each segment, decode the output
        auto numStr = std::string();
        for (const auto &o : s.output) {
            switch (o.length()) {
                case 2:
                    numStr += "1";
                    break;
                case 3:
                    numStr += "7";
                    break;
                case 4:
                    numStr += "4";
                    break;
                case 5:
                    if (contains(o, lowerLeft)) {
                        numStr += "2";
                    } else if (contains(o, upperLeft)) {
                        numStr += "5";
                    } else {
                        numStr += "3";
                    }
                    break;
                case 6:
                    if (!contains(o, middle)) {
                        numStr += "0";
                    } else if (!contains(o, upperRight)) {
                        numStr += "6";
                    } else {
                        numStr += "9";
                    }
                    break;
                case 7:
                    numStr += "8";
                    break;
            }
        }
        sum += std::stoi(numStr);
    }
    return std::to_string(sum);
}

std::string aoc21::Day08::newPart2() const {
    auto sum = 0;
    for (const auto &s : _signalSets) {
        auto frequencies = std::unordered_map<char,int>();
        for (const auto &p : s.patterns) {
            for (auto c : p) {
                ++frequencies[c];
            }
        }

        auto numbers = std::array<std::string,10>();
        for (const auto &p : s.patterns) {
            auto freq_4 = 0;
            auto freq_6 = 0;
            auto freq_7 = 0;
            auto freq_8 = 0;
            auto freq_9 = 0;
            switch (p.length()) {
                case 2:
                    numbers[1] = p;
                    break;
                case 3:
                    numbers[7] = p;
                    break;
                case 4:
                    numbers[4] = p;
                    break;
                case 5:
                    for (auto c : p) {
                        switch (frequencies[c]) {
                            case 4: ++freq_4; break;
                            case 6: ++freq_6; break;
                            case 9: ++freq_9; break;
                        }
                    }
                    if (freq_4 == 0 && freq_6 == 0) {
                        numbers[3] = p;
                        break;
                    } else if (freq_4 == 0) {
                        numbers[5] = p;
                        break;
                    } else if (freq_9 == 0) {
                        numbers[2] = p;
                        break;
                    }
                    break;
                case 6: // 0,6,9
                    for (auto c : p) {
                        switch (frequencies[c]) {
                            case 4: ++freq_4; break;
                            case 7: ++freq_7; break;
                            case 8: ++freq_8; break;
                        }
                    }
                    if (freq_4 == 0) {
                        numbers[9] = p;
                        break;
                    } else if (freq_7 == 1) {
                        numbers[0] = p;
                        break;
                    } else if (freq_8 == 1) {
                        numbers[6] = p;
                        break;
                    } else {
                        break;
                    }
                case 7:
                    numbers[8] = p;
                    break;
            }
        }

        auto outputNumber = std::string();
        for (auto k=0; const auto &o : s.output) {
            for (auto i=0; i!=numbers.size(); ++i) {
                if (numbers[i] == o) {
                   outputNumber += std::to_string(i);
                   break;
                }
            }
        }
        sum += std::stoi(outputNumber);
    }
    
    return std::to_string(sum);
}

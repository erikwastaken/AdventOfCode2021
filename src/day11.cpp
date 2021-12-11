#include "day11.hpp"

aoc21::Day11::Day11(const std::vector<std::string> &input) {
    auto octopuses = std::array<Octopus, 100>();
    auto flashCount = 0;
    for (auto i=0; const auto &line : input) {
        for (auto c : line) {
            octopuses[i++] = Octopus((int) c - '0', &flashCount);
        }
    }

    for (auto i = 0; auto &octopus: octopuses) {
        for (auto idx: getAdjacentIndexes(i++)) {
            octopus.addNeighbour(&octopuses[idx]);
        }
    }

    auto step = 0;
    while (true) {
        ++step;
        // 1 - increment energy level of octopuses by 1
        for (auto &octo: octopuses) {
            ++octo;
        }

        // 2 - octopuses with enough energy will flash
        auto tmp = flashCount;
        for (auto &octo: octopuses) {
            octo.flash();
        }

        if (step == 100)
            _flashCountAt100 = flashCount;

        if (flashCount - tmp == 100) {
            _synchronizationStep = step;
            break;
        }

        // 3 - set energy of flashed octopuses back to 0
        for (auto &octo: octopuses) {
            octo.reset();
        }
    }
}

std::string aoc21::Day11::part1() const {
    return std::to_string(_flashCountAt100);
}

std::string aoc21::Day11::part2() const {
    return std::to_string(_synchronizationStep);
}

aoc21::Day11::Octopus::Octopus() : _energy(0) {}
aoc21::Day11::Octopus::Octopus(int energy, int *count) : _energy(energy) {
    this->_flashCount = count;
}

aoc21::Day11::Octopus& aoc21::Day11::Octopus::operator++() {
    ++_energy;
    return *this;
}

void aoc21::Day11::Octopus::flash() {
    if (_hasFlashed || _energy < 10) {
        return;
    }
    _hasFlashed = true;
    ++(*_flashCount);
    for (auto n : _neighbours) {
        ++(*n);
        n->flash();
    }
}

void aoc21::Day11::Octopus::addNeighbour(aoc21::Day11::Octopus* neighbour) {
    _neighbours.push_back(neighbour);
}

bool aoc21::Day11::Octopus::reset() {
    if (_hasFlashed) {
        _hasFlashed = false;
        _energy = 0;
        return true;
    }
    return false;
}

std::vector<int> aoc21::Day11::getAdjacentIndexes(int idx) {
    auto result = std::vector<int>();
    if (idx == 0) {
        result.push_back(1);
        result.push_back(10);
        result.push_back(11);
    } else if (idx < 9) {
        result.push_back(idx - 1);
        result.push_back(idx + 1);
        result.push_back(idx + 9);
        result.push_back(idx + 10);
        result.push_back(idx + 11);
    } else if (idx == 9) {
        result.push_back(idx - 1);
        result.push_back(idx + 9);
        result.push_back(idx + 10);
    } else if (idx == 90) {
        result.push_back(idx - 10);
        result.push_back(idx - 9);
        result.push_back(idx + 1);
    } else if (90 < idx && idx < 99) {
        result.push_back(idx - 1);
        result.push_back(idx + 1);
        result.push_back(idx - 9);
        result.push_back(idx - 10);
        result.push_back(idx - 11);
    } else if (idx == 99) {
        result.push_back(idx - 1);
        result.push_back(idx - 11);
        result.push_back(idx - 10);
    } else if (idx % 10 == 0) {
        result.push_back(idx - 10);
        result.push_back(idx - 9);
        result.push_back(idx + 1);
        result.push_back(idx + 10);
        result.push_back(idx + 11);
    } else if (idx % 10 == 9) {
        result.push_back(idx - 10);
        result.push_back(idx - 11);
        result.push_back(idx - 1);
        result.push_back(idx + 10);
        result.push_back(idx + 9);
    } else {
        result.push_back(idx - 11);
        result.push_back(idx - 10);
        result.push_back(idx - 9);
        result.push_back(idx - 1);
        result.push_back(idx + 1);
        result.push_back(idx + 9);
        result.push_back(idx + 10);
        result.push_back(idx + 11);
    }
    return result;
}

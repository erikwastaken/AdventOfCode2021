#ifndef AOC21_DAY11_HPP
#define AOC21_DAY11_HPP

#include <string>
#include <vector>
#include <array>

namespace aoc21 {

    class Day11 {
        public:
            explicit Day11(const std::vector<std::string> &input);
            std::string part1() const;
            std::string part2() const;
        private:
            static std::vector<int> getAdjacentIndexes(int idx);
            int _flashCountAt100 {0};
            int _synchronizationStep {0};
            class Octopus {
                public:
                    Octopus();
                    explicit Octopus(int energy, int *count);
                    Octopus& operator++(); // prefix
                    void flash();
                    void addNeighbour(Octopus *neighbour);
                    bool reset();
                private:
                    int _energy;
                    int *_flashCount {nullptr};
                    bool _hasFlashed {false};
                    std::vector<Octopus*> _neighbours {};
            };
    };

}

#endif


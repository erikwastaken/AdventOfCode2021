#ifndef AOC21_DAY15_HPP
#define AOC21_DAY15_HPP

#include <vector>
#include <string>

namespace aoc21 {
    
    struct Node {
        int position;
        int weight;
        int distance;
        bool visited {false};
        Node* previous;
        Node(int p, int w);
        Node(int p, int w, int d);
    };

    inline bool operator<(const Node& lhs, const Node& rhs);
    inline bool operator>(const Node& lhs, const Node& rhs);
    inline bool operator<=(const Node& lhs, const Node& rhs);
    inline bool operator>=(const Node& lhs, const Node& rhs);

    class NodeLess {
        public:
            bool operator()(const Node* lhs, const Node* rhs);
    };

    class Day15 {
        public:
            explicit Day15(const std::vector<std::string> &input);
            std::string part1() const;
            std::string part2() const;
        private:
            struct Graph {
                std::vector<Node> nodes;
                int cols {};
                int rows {};
                Graph(const std::vector<int> &weights, int _cols);
            };
            int _rowSize {};
            std::vector<int> _weights {};
            std::vector<int> _weights2 {};
            std::vector<Node> _nodes {};
            static std::vector<int> neighbours(int idx, int cols, int rows);
            static int shortestDistanceToEnd(aoc21::Day15::Graph &graph);
    };

}

#endif


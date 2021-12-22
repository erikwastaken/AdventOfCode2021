#include "day15.hpp"
#include "exceptions.hpp"
#include <limits>
#include <algorithm>

aoc21::Day15::Day15(const std::vector<std::string> &input) {
    _rowSize = input[0].length();
    for (const auto &line : input) {
        for (auto c : line) {
            int weight = c - '0';
            _weights.push_back(weight);
        }
    }
    for (const auto &line : input) {
        for (auto i = 0; i != 5; ++i) {
            for (auto c : line) {
                int weight = ((c - '0') + i - 1) % 9 + 1; // wrap around from 9 to 1
                _weights2.push_back(weight);
            }
        }
    }
    int originalSize = _weights2.size();
    for (auto i = 1; i != 5; ++i) {
        for (auto ii = 0; ii != originalSize; ++ii) {
            int weight = (_weights2[ii] + i - 1) % 9 + 1;
            _weights2.push_back(weight);
        }
    }
}

std::string aoc21::Day15::part1() const {
    auto graph = Graph(_weights, _rowSize);
    return std::to_string(shortestDistanceToEnd(graph));
}

std::string aoc21::Day15::part2() const {
    auto graph = Graph(_weights2, _rowSize * 5);
    return std::to_string(shortestDistanceToEnd(graph));
}

int aoc21::Day15::shortestDistanceToEnd(aoc21::Day15::Graph &graph) {
    auto hp = std::vector<Node*>();
    for (auto& node : graph.nodes) {
        hp.push_back(&node);
    }
    while (!hp.empty()) {
        std::sort(hp.begin(), hp.end(), NodeLess());
        auto current = hp[0];
        hp.erase(hp.begin());
//        auto it = std::min_element(hp.begin(), hp.end(), [](const auto it1, const auto it2) { return *it1 < *it2; });
//        auto current = *it;
//        hp.erase(it);
        if (current->position == (int) graph.nodes.size() - 1) {
            return current->distance;
        }
        current->visited = true;
        for (auto idx : neighbours(current->position, graph.cols, graph.rows)) {
            auto& node = graph.nodes[idx];
            if (node.visited)
                continue;
            auto dist = current->distance + node.weight;
            if (dist < node.distance) {
                node.distance = dist;
                node.previous = current;
            }
        }
    }
    throw AoCException("Edsgar did not find the shortest path");
}

std::vector<int> aoc21::Day15::neighbours(int idx, int cols, int rows) {
    auto result = std::vector<int>();
    if (idx == 0) {
        result.push_back(1);
        result.push_back(cols);
    } else if (idx < cols - 1) {
        result.push_back(idx - 1);
        result.push_back(idx + 1);
        result.push_back(idx + cols);
    } else if (idx == cols - 1) {
        result.push_back(idx - 1);
        result.push_back(idx + cols);
    } else if (idx == rows * (cols - 1)) {
        result.push_back(idx - cols);
        result.push_back(idx + 1);
    } else if ((rows - 1) * cols < idx && idx < rows * cols - 1) {
        result.push_back(idx - 1);
        result.push_back(idx + 1);
        result.push_back(idx - cols);
    } else if (idx == (cols * rows - 1)) {
        result.push_back(idx - 1);
        result.push_back(idx - cols);
    } else if (idx % cols == 0) {
        result.push_back(idx - cols);
        result.push_back(idx + 1);
        result.push_back(idx + cols);
    } else if (idx % cols == rows - 1) {
        result.push_back(idx - cols);
        result.push_back(idx - 1);
        result.push_back(idx + cols);
    } else {
        result.push_back(idx - cols);
        result.push_back(idx - 1);
        result.push_back(idx + 1);
        result.push_back(idx + cols);
    }
    return result;
}

aoc21::Node::Node(int idx, int w) : position(idx), weight(w), distance(std::numeric_limits<int>::max()), previous(nullptr) {}

aoc21::Node::Node(int idx, int w, int d) : position(idx), weight(w), distance(d), previous(nullptr) {}

bool aoc21::operator<(const Node& lhs, const Node& rhs) {
    return lhs.distance < rhs.distance;
}

bool aoc21::operator>(const Node& lhs, const Node& rhs) {
    return rhs < lhs;
}

bool aoc21::operator<=(const Node& lhs, const Node& rhs) {
    return !(lhs > rhs);
}

bool aoc21::operator>=(const Node& lhs, const Node& rhs) {
    return !(lhs < rhs);
}

bool aoc21::NodeLess::operator()(const Node* lhs, const Node* rhs) {
    return (lhs->distance < rhs->distance);
}

aoc21::Day15::Graph::Graph(const std::vector<int> &weights, int _cols) : cols(_cols) {
    rows = weights.size() / cols;
    nodes.emplace_back(Node(0,0,0));
    for (auto i = 1ul; i != weights.size(); ++i) {
        nodes.emplace_back(Node(i,weights[i]));
    }
}

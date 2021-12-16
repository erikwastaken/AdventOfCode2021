#include "day16.hpp"
#include "exceptions.hpp"

aoc21::Day16::Day16(const std::string &input) : _packet {aoc21::hexStringToBinary(input)} { }

std::string aoc21::hexToBin (char c) {
    switch (c) {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'A': return "1010";
        case 'B': return "1011";
        case 'C': return "1100";
        case 'D': return "1101";
        case 'E': return "1110";
        case 'F': return "1111";
        default: throw AoCException("Unsupported character");
    }
}

std::string aoc21::hexStringToBinary(const std::string &input) {
    auto result = std::string();
    for (auto c : input) {
        result += hexToBin(c);
    }
    return result;
}

std::string aoc21::Day16::part1() const {
    auto sum = 0;
    sumVersionNumbers(&_packet, &sum);
    return std::to_string(sum);
}

std::string aoc21::Day16::part2() const {
    return std::to_string(_packet.evaluate());
}

void aoc21::Day16::sumVersionNumbers(const aoc21::Day16::Packet* p, int* sum) const {
    *sum += p->version;
    if (p->subPackets.empty())
        return;
    for (const auto &s : p->subPackets) {
        sumVersionNumbers(&s, sum);
    }
}

aoc21::Day16::Packet::Packet(const std::string &binary) {
    if (binary.size() < 6)
        throw AoCException("Error while parsing input");
    version = std::stoi(binary.substr(0, 3), nullptr, 2);
    typeID = std::stoi(binary.substr(3, 3), nullptr, 2);
    length = 6;
    if (typeID == 4) { // literal value
        auto buffer = std::string();
        while (true) {
            buffer += binary.substr(length + 1, 4);
            if (binary.at(length) == '0') {
                length += 5;
                break;
            }
            length += 5;
        }
        litValue = std::stoll(buffer, nullptr, 2);
    } else { // operator
        auto lengthType = (binary.at(6) == '0') ? 0 : 1;
        if (lengthType == 0) {
            auto totalSubLength = std::stoi(binary.substr(7, 15), nullptr, 2);
            auto subPacketLength = 0;
            length = 22;
            while (subPacketLength < totalSubLength) {
                auto packetSubString = binary.substr(length, totalSubLength - subPacketLength);
                auto subPacket = Packet(packetSubString);
                subPacketLength += subPacket.length;
                length += subPacket.length;
                subPackets.push_back(subPacket);
            }
        } else {
            length = 18;
            auto numberOfSubPackets = std::stoi(binary.substr(7, 11), nullptr, 2);
            while (subPackets.size() < numberOfSubPackets) {
                auto subPacket = Packet(binary.substr(length));
                length += subPacket.length;
                subPackets.push_back(subPacket);
            }
        }
    }
}

long long aoc21::Day16::Packet::evaluate() const {
    switch (typeID) {
        //TODO replace loops with standard algorithms;
        case 0: {
            auto sum = 0ll;
            for (auto &p: subPackets) {
                sum += p.evaluate();
            }
            return sum;
        }
        case 1: {
            auto prod = 1ll;
            for (const auto &p : subPackets) {
                prod *= p.evaluate();
            }
            return prod;
        }
        case 2: {
            auto min = std::numeric_limits<long long>::max();
            for (const auto &p : subPackets) {
                auto val = p.evaluate();
                if (val < min) {
                    min = val;
                }
            }
            return min;
        }
        case 3: {
            auto max = std::numeric_limits<long long>::min();
            for (const auto &p : subPackets) {
                auto val = p.evaluate();
                if (val > max)
                    max = val;
            }
            return max;
        }
        case 4: return litValue;
        case 5: return (subPackets[0].evaluate() > subPackets[1].evaluate()) ? 1 : 0;
        case 6: return (subPackets[0].evaluate() < subPackets[1].evaluate()) ? 1 : 0;
        case 7: return (subPackets[0].evaluate() == subPackets[1].evaluate()) ? 1 : 0;
        default: throw AoCException("Non-supported operation");
    }
}

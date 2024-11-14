#include "RandNumber.h"
#include <iostream>
#include <conio.h>
#include <chrono>

using namespace std;

RandomNumberGenerator::RandomNumberGenerator()
{
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    m_generator.seed(seed);
}

long long RandomNumberGenerator::getRandomInRange(long long lower, long long upper)
{
    uniform_int_distribution<long long> distribution(lower, upper);
    return distribution(m_generator);
}

std::unordered_map<int, int> RandomNumberGenerator::randomIndexMap(int size, int maxRange) {
    RandomNumberGenerator rng;
    std::unordered_map<int, int> map;
    for (int i = 0; i < size; ++i) {
        while (!(map.emplace(rng.getRandomInRange(0, maxRange - 1), i)).second);
    }
    return map;
}

std::vector<fs::path> RandomNumberGenerator::getListOfStartPaths(const fs::path& startDir, const std::unordered_map<int, int>& randomNumberMap) const {
    std::vector<fs::path> list;
    int index = 0;
    for (const auto& entry : fs::directory_iterator(startDir)) {
        if (entry.is_regular_file() && randomNumberMap.count(index) > 0) {
            list.push_back(entry.path());
        }
        ++index;
    }
    return list;
}
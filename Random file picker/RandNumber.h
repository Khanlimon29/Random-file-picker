#pragma once
#include <random>
#include <filesystem>
#include <unordered_map>
#include <vector>

using namespace std;
namespace fs = std::filesystem;

class RandomNumberGenerator {
private:
    mt19937_64 m_generator;

public:
    RandomNumberGenerator();
    long long getRandomInRange(long long lower, long long upper);
    std::unordered_map<int, int> randomIndexMap(int size, int maxRange);
    std::vector<fs::path> getListOfStartPaths(const fs::path& startDir, const std::unordered_map<int, int>& randomNumberMap) const;
};
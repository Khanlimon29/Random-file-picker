#pragma once
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;

class FileMover {
public:
    void replaceFiles(const std::vector<fs::path>& startPaths, const std::vector<fs::path>& finalPaths) const;
    std::vector<fs::path> getListOfFinalPaths(const fs::path& finalDir, const std::vector<fs::path>& startPaths) const;
};
#include "FileMover.h"
#include <filesystem>

void FileMover::replaceFiles(const std::vector<fs::path>& startPaths, const std::vector<fs::path>& finalPaths) const {
    for (size_t i = 0; i < startPaths.size(); ++i) {
        fs::rename(startPaths[i], finalPaths[i]);
    }
}

std::vector<fs::path> FileMover::getListOfFinalPaths(const fs::path& finalDir, const std::vector<fs::path>& startPaths) const {
    std::vector<fs::path> list;
    for (const auto& startPath : startPaths) {
        list.push_back(finalDir / startPath.filename());
    }
    return list;
}
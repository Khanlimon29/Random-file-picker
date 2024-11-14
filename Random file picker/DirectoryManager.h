#pragma once

#include <filesystem>
#include <vector>
#include <iostream>

namespace fs = std::filesystem;

class DirectoryManager {
public:
    bool realDir(const fs::path& path) const;
    fs::path getDirFromUser() const;
    std::vector<fs::path> getDirectoryList(const fs::path& directory) const;
    void printAllSubDirs(const std::vector<fs::path>& list) const;
};
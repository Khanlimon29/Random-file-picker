#pragma once
#include <iostream>
#include <conio.h>
#include <vector>
#include <filesystem>

namespace fs = std::filesystem;

class UserInterface {
public:
    void drawMenu() const;
    bool processUserChoice() const;
    int getNumOfDirectoriesToMove() const;
    int getDirectoryIndex(int dirCount) const;
    std::vector<fs::path> getMultipleStartDirs(const std::vector<fs::path>& dirList) const;
};
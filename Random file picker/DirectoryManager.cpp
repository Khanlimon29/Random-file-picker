#include "DirectoryManager.h"

bool DirectoryManager::realDir(const fs::path& path) const {
    if (fs::exists(path)) {
        return true;
    }
    else {
        std::cout << "Директории не существует\nВведите другую директорию: ";
        return false;
    }
}

fs::path DirectoryManager::getDirFromUser() const {
    fs::path dir;
    std::cin >> dir;
    while (!realDir(dir)) {
        std::cin >> dir;
    }
    return dir;
}

std::vector<fs::path> DirectoryManager::getDirectoryList(const fs::path& directory) const {
    std::vector<fs::path> list;
    for (const auto& entry : fs::directory_iterator(directory)) {
        if (entry.is_directory()) {
            list.push_back(entry.path());
        }
    }
    return list;
}

void DirectoryManager::printAllSubDirs(const std::vector<fs::path>& list) const {
    for (size_t i = 0; i < list.size(); ++i) {
        std::cout << i + 1 << " " << list[i].filename().string() << "\n";
    }
}

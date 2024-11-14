#include "DirectoryManager.h"
#include "RandNumber.h"
#include "FileMover.h"
#include "UserInterface.h"

int main() {
    DirectoryManager directoryManager;
    RandomNumberGenerator randomizer;
    FileMover fileMover;
    UserInterface ui;

    bool multiple;
    fs::path startDir, finalDir;
    std::vector<fs::path> dirList, selectedDirs, fileListStart, fileListFinal;
    int numbOfFilesToMove = 0;

    ui.drawMenu();
    std::cout << "Выберите режим работы:\n1. Одна папка\n2. Несколько папок\n";
    multiple = ui.processUserChoice();

    std::cout << "Введите стартовую директорию: ";
    startDir = directoryManager.getDirFromUser();
    dirList = directoryManager.getDirectoryList(startDir);
    while (dirList.empty()) {
        std::cout << "В выбранной директории нет поддиректорий, введите другую директорию: ";
        startDir = directoryManager.getDirFromUser();
        dirList = directoryManager.getDirectoryList(startDir);
    }

    std::cout << "Введите директорию, в которую будут перемещены файлы: ";
    finalDir = directoryManager.getDirFromUser();

    ui.drawMenu();
    std::cout << "Из директории " << startDir << " в директорию " << finalDir << "\n";
    directoryManager.printAllSubDirs(dirList);

    if (multiple) {
        selectedDirs = ui.getMultipleStartDirs(dirList);
    }
    else {
        int startFolderInd;
        std::cout << "Выберите исходную папку и введите её порядковый номер: ";
        std::cin >> startFolderInd;
        selectedDirs.push_back(dirList[startFolderInd - 1]);
    }

    for (const auto& subDir : selectedDirs) {
        fs::path fullPath = startDir / subDir;
        std::vector<fs::path> allFilesInDir;
        for (const auto& entry : fs::directory_iterator(fullPath)) {
            if (entry.is_regular_file()) {
                allFilesInDir.push_back(entry.path());
            }
        }

        int numbOfFilesInFolder = allFilesInDir.size();
        ui.drawMenu();
        std::cout << "Выбранная папка: " << subDir.filename().string() << "\nКоличество файлов: " << numbOfFilesInFolder << "\nВведите необходимое количество файлов для перемещения: ";
        std::cin >> numbOfFilesToMove;

        while (numbOfFilesToMove < 0 || numbOfFilesInFolder < numbOfFilesToMove) {
            std::cout << "Некорректный ввод, введите другое число: ";
            std::cin >> numbOfFilesToMove;
        }

        auto randomNumberMap = randomizer.randomIndexMap(numbOfFilesToMove, numbOfFilesInFolder);
        auto filesToMove = randomizer.getListOfStartPaths(fullPath, randomNumberMap);
        auto finalPaths = fileMover.getListOfFinalPaths(finalDir, filesToMove);

        fileMover.replaceFiles(filesToMove, finalPaths);
    }

    std::cout << "Файлы перемещены\n";
    _getch();

    return 0;
}
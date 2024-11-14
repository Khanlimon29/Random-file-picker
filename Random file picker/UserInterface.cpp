#include "UserInterface.h"
#include <conio.h>
#include <iostream>

void UserInterface::drawMenu() const {
    system("cls");
    std::cout << "Выбранный вариант: Рандомный выбор файлов из папки\n\n";
}

bool UserInterface::processUserChoice() const {
    char choice;
    while (true) {
        choice = _getch();
        if (choice == '1' || choice == '2') {
            return choice == '2';
        }
    }
}

int UserInterface::getNumOfDirectoriesToMove() const {
    int numDirs;
    std::cout << "Введите количество поддиректорий для перемещения файлов: ";
    std::cin >> numDirs;
    return numDirs;
}

int UserInterface::getDirectoryIndex(int dirCount) const {
    int dirIndex;
    std::cout << "Введите порядковый номер поддиректории: ";
    std::cin >> dirIndex;

    while (dirIndex <= 0 || dirIndex > dirCount) {
        std::cout << "Некорректный номер поддиректории. Введите снова: ";
        std::cin >> dirIndex;
    }
    return dirIndex;
}

std::vector<fs::path> UserInterface::getMultipleStartDirs(const std::vector<fs::path>& dirList) const {
    int numDirs = getNumOfDirectoriesToMove();
    std::vector<fs::path> selectedDirs;

    for (int i = 0; i < numDirs; ++i) {
        int dirIndex = getDirectoryIndex(dirList.size());
        selectedDirs.push_back(dirList[dirIndex - 1]);
    }
    return selectedDirs;
}
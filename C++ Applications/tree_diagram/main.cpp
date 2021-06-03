#include <iostream>
#include <string>
#include <filesystem>
#include <cstdlib>


void printDirTree(const std::filesystem::path &pathAddress, int space, int level) {
    for (const auto &p : std::filesystem::directory_iterator(pathAddress)){
        std::string spacing = std::string(space * 4, ' ');
        auto filename = p.path().filename();
        if (std::filesystem::is_directory(p.status()) && level < 3) {
            std::cout << spacing << " || " << filename << std::endl;
            printDirTree(p.path(), space + 1, level + 1);
            std::cout << std::endl;
        } else if (std::filesystem::is_directory(p.status())) {
            std::cout << spacing << " || " << filename << std::endl;
        } else if (std::filesystem::is_regular_file(p.status())){
            std::cout << spacing << " |- " << filename << std::endl;
        } else {
            std:: cout << spacing << " |- " << filename << std::endl;
        }
    }
}

void printDirTree(const std::filesystem::path &pathAddress) {
    for (const auto &p : std::filesystem::recursive_directory_iterator(pathAddress)) {
        std::cout << p.path() << std::endl;
    }
}

int main() {
    std::cout << "Welcome to Tree Diagram Utility" << std::endl;
    std::cout << "Please enter the address from where you want to run tree diagram : " << std::endl;
    std::string path;
    std::cin >> path;
    printDirTree(path, 0, 0);
    system("PAUSE");
}

#include <iostream>
#include <string>
#include <filesystem>
#include <cstdlib>

namespace fs = std::filesystem;
/* @brief This code uses filesystem directory iterator to iterate through directories recursively
  and print the filenames and directory names at 3 level deep */

void printDirTree(const fs::path &pathAddress, int space, int level, int finalLevel) {
    for (const auto &p : fs::directory_iterator(pathAddress, fs::directory_options::skip_permission_denied)){
        // try and catch is used to filter out any errors occured during the execution of the code
        try {
            std::string spacing = std::string(space * 4, ' ');
            auto filename = p.path().filename();
            if (fs::is_directory(p.status()) && level < finalLevel) {
                std::cout << spacing << " || " << filename << std::endl;
                printDirTree(p.path(), space + 1, level + 1, finalLevel);
                std::cout << std::endl;
                throw 505;
            } else if (fs::is_directory(p.status())) {
                std::cout << spacing << " || " << filename << std::endl;
            } else if (fs::is_regular_file(p.status())){
                std::cout << spacing << " |- " << filename << std::endl;
            } else {
                std:: cout << spacing << " |- " << filename << std::endl;
            }
        }  catch (...) {
        }
    }
}

int main(int argc,char* argv[]) {
    std::cout << "Welcome to Tree Diagram Utility" << std::endl;
    std::cout << std::endl;
    if(argc == 1) {
        std::cout << "--HELP" << std::endl;
        std::cout << "--First Argument - Pass path of folder as first argument" << std::endl;
        std::cout << "--Second Argument - Pass the level of deepness (1-9) for iterations as second argument" << std::endl;
    } else if( argc == 2) {
        std::cout << "Only one argument passed. Please pass two arguments" << std::endl;
        std::cout << "--First Argument - Pass path of folder as first argument" << std::endl;
        std::cout << "--Second Argument - Pass the level of deepness (1-9) for iterations as second argument" << std::endl;
    }
    if(argc > 2) {
    // first argument passed through terminal should be the directory path
        std::string path = argv[1];
    // second argument passed through terminal should be level of deepness 
        char finalLevelChar = *argv[2];
        if(static_cast<int>(finalLevelChar) > 48 && static_cast<int>(finalLevelChar) < 58) {
            int finalLevel = static_cast<int>(finalLevelChar) - 48;
            if(fs::is_directory(path)) {
                printDirTree(path, 0, 0, finalLevel);
            } else {
                std::cout << "Please enter a valid directory!! " << std::endl; 
            }
        } else {
            std::cout << "Please enter a valid number between 1 to 9." << std::endl;
        }
    }
    system("PAUSE");
}

#include <cstdlib>
#include <iostream>
#include <filesystem>

void copy(std::string &firstFolder, std::string &secondFolder){
    if(std::filesystem::exists(firstFolder) && std::filesystem::exists(secondFolder)) {
        std::cout << "Copying...." << std::endl;
        std::filesystem::copy(firstFolder, secondFolder, std::filesystem::copy_options::recursive);
        std::cout << "Completed Copying." << std::endl;
    } else if (!std::filesystem::exists(firstFolder)) {
        std::cout << "Please enter correct path to copy." << std::endl;
    } else if (!std::filesystem::exists(secondFolder)) {
        std::cout << "Please enter correct destination path." << std::endl;
    }
}

int main() {
    std::string first, second;
    std::cout << "Welcome to the Copy Utility" << std::endl;
    std::cout << "Enter path of the file/folder to be copied : ";
    std::cin >> first;
    std::cout << "Enter the path of destination folder : ";
    std::cin >> second;
    copy(first, second);
    system("PAUSE");
}

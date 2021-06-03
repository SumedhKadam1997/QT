//#include <iostream>
//#include <string>
//#include <filesystem>


//void printDirTree(const std::filesystem::path &pathAddress, int space, int level) {
//    for (const auto &p : std::filesystem::directory_iterator(pathAddress)){
//        std::string spacing = std::string(space * 4, ' ');
//        auto filename = p.path().filename();
//        if (std::filesystem::is_directory(p.status()) && level < 3) {
//            std::cout << spacing << "|| " << filename << std::endl;
//            printDirTree(p.path(), space + 1, level + 1);
//            std::cout << std::endl;
//        } else if (std::filesystem::is_directory(p.status())) {
//            std::cout << spacing << "|| " << filename << std::endl;
//        } else if (std::filesystem::is_regular_file(p.status())){
//            std::cout << spacing << " |- " << filename << std::endl;
//        } else {
//            std:: cout << spacing << " |- " << filename << std::endl;
//        }
//    }
//}

//int main() {
//    std::string path = "C:\\Users\\uxoriousghost\\Desktop";
//    printDirTree(path, 0, 0);
//}

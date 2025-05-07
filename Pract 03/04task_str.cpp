#include <iostream>
#include <fstream>
#include <string>
void compareFiles(std::ifstream& file1, std::ifstream& file2) {
    bool areLinesEqual = true;
    std::string lineFile1;
    std::string lineFile2;

    while (std::getline(file1, lineFile1) && std::getline(file2, lineFile2)) {
        if (lineFile1 != lineFile2) {
            std::cout << "Differences here: \n";
            std::cout << "File1: " << lineFile1 << "\n";
            std::cout << "File2: " << lineFile2 << "\n";
            areLinesEqual = false;
            break; 
        }
    }
    // Check if one file has more lines than the other
    if (std::getline(file1, lineFile1) && areLinesEqual) {
        std::cout << "File1: " << lineFile1 << "\n";
        areLinesEqual = false;
    }
    if (std::getline(file2, lineFile2) && areLinesEqual) {
        std::cout << "File2: " << lineFile2 << "\n";
        areLinesEqual = false;
    }
    //conclude
    if (areLinesEqual) {
        std::cout << "Files are identical.";
    }
   
}
int main() {
    std::ifstream inputFile1("example.txt");
    std::ifstream inputFile2("example1.txt");
    if (!inputFile1 || !inputFile2) {
        std::cerr << "File/s could not be opened!" << std::endl;
        return 1;
    }
    compareFiles(inputFile1, inputFile2);
    inputFile1.close();
    inputFile2.close();
}

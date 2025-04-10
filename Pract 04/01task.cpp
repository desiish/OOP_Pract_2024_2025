#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <cstring>

void createNewArrays(int *arr, const std::string& fileName) {
    std::ofstream writeFile(fileName, std::ios::binary);
    if (!writeFile) {
        std::cerr << "Error: Failed to open the file for writing!" << std::endl;
        return;
    }
    writeFile.write(reinterpret_cast<char*>(arr), sizeof(arr)*5);
    writeFile.close();

    std::ifstream readFile(fileName, std::ios::binary);
    if (!readFile) {
        std::cerr << "Error: Failed to open the file for reading!" << std::endl;
        return;
    }

    readFile.read(reinterpret_cast<char*>(arr), sizeof(arr));

    //for checking in console, also comment line 22
  /*  std::cout << "\nContents of the file (as integers): ";
    char buffer[sizeof(int)];
    while (readFile.read(buffer, sizeof(int))) {
        int num;
        std::memcpy(&num, buffer, sizeof(int));
        std::cout << num << " "; 
    }
    std::cout << std::endl;*/

    readFile.close();
}


void extractNumbers(int* newArr, std::ifstream& infile, int* evens, int* odds, int size) {
    infile.read(reinterpret_cast<char*>(newArr), sizeof(newArr)*size);

   /*char buffer[10];
   while (infile.read(buffer, sizeof(int))) {
       int num;
       std::memcpy(&num, buffer, sizeof(int));
       std::cout << num << " ";
   }*/
    
    int evenCount = 0;
    int oddCount = 0;
        for (int i = 0; i < size; ++i) {
            if (newArr[i] % 2 == 0) {
                evens[evenCount++] = newArr[i];
            }
            else {
                odds[oddCount++] = newArr[i];
            }
        }
    }

int main() {
    const int SIZE = 10;
    int arr[SIZE] = { 1,2,3,4,5,6,7,8,9,10 };
    //first, create the file 
    std::ofstream outfile("C:\\Users\\vikik\\Desktop\\example.bin", std::ios::binary);
    try {    
        if (!outfile) {
            throw std::ios_base::failure("Mistake opening the file");
        }
    }
    catch(const std::ios_base::failure& e){
        std::cerr << "File error: " << e.what();
    }
    outfile.write(reinterpret_cast<char*>(arr), sizeof(arr));
    outfile.close();

    //now we pretend we had the file ready with text in it
    std::ifstream infile("C:\\Users\\vikik\\Desktop\\example.bin", std::ios::binary);
    try {
        if (!infile) {
            throw std::ios_base::failure("Mistake opening the file");
        }
    }
    catch (const std::ios_base::failure& e) {
        std::cerr << "File error: " << e.what();
    }

   /* char buffer[sizeof(int)];
    while (infile.read(buffer, sizeof(int))) {
        int num;
        std::memcpy(&num, buffer, sizeof(int));  
        std::cout << num << " ";
    }*/

    int evens[SIZE]{};
    int odds[SIZE]{};
    int newArr[SIZE]{};
    extractNumbers(newArr, infile, evens, odds, SIZE);
    infile.close();

    //createNewFiles
    createNewArrays(evens, "C:\\Users\\vikik\\Desktop\\evens.bin");
    createNewArrays(odds, "C:\\Users\\vikik\\Desktop\\odds.bin");

}

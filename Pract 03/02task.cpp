#include <iostream>
#include <fstream>

int findLength(std::ifstream& file) {
    int count = 0;
    char ch;
    while (file.get(ch)) {
        if (ch == ' ' || ch == '\n') {
            count++;
        }
        //for last element, to count correctly
        ch = file.peek();
        if (ch == EOF) {
            count++;
        }
    }
    return count;
}

void fillList(std::ifstream &file, int size, int* list) {
    if (!file.is_open()) {
        std::cerr << "Error opening the file!" << std::endl;
        return;
    }
    char ch;
    int index = 0; 

    while (file.get(ch) && index < size) {
        if (ch >= '0' && ch <= '9') {
            *list = *list * 10 + (ch - '0');
        }
        else if (ch == ' ' || ch == '\n') {
            list++;
        }
        else {
            continue;
        }
    }
}

int compareElements(int* list, int i, int size) {
    int count = 0;
    for (int j = i + 1; j < size; j++) {
        if (list[i] == list[j]) {
            count++;
        }
    }
    return count;
}
int findMostFrequent(int* list, int size) {
    int currentElement = list[0];
    int currCount = 0;
    
    for (int i = 0; i < size; i++) {
        int count = 1;
        count += compareElements(list, i, size);
        if (count > currCount) {
            currCount = count;
            currentElement = list[i];
        }
    }
    return currentElement;
}
int main() {
    const int SIZE = 64;
    // Open the file
    std::ifstream inputFile("example.txt");
    if (!inputFile) {
        std::cerr << "File could not be opened!" << std::endl;
        return 1;
    }
    int list[SIZE] = {0};
    int length = findLength(inputFile);
    std::cout << "Length: " << length << std::endl;

    //important to clear after each operation
    inputFile.clear(); 
    inputFile.seekg(0);

    fillList(inputFile, length, list);
    
    //find most frequent element
    int mostFrNumber = findMostFrequent(list, length);
    std::cout << "Most frequent element: " << mostFrNumber;
}

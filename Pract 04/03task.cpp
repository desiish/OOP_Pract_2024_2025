#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <cstring>

struct JobOffer {
    static const int SIZE = 25;
    double salary;   
    int programmers;
    int offDaysPaid;
    char name[SIZE];

    JobOffer(double s = 0.0, int p = 0, int o = 0, const char* n = "Unknown") {
        salary = s;  
        programmers = p;
        offDaysPaid = o;

        strncpy_s(name, n, SIZE - 1);       
        name[SIZE - 1] = '\0';
    }
    void printJob() const {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Programmers: " << programmers << std::endl;
        std::cout << "Paid days off: " << offDaysPaid << std::endl;
        std::cout << "Salary for project: " << salary << std::endl;
    }
};

void makeOffer(const int n, const int size) {
    std::ofstream writeFile("C:\\Users\\vikik\\Desktop\\offers.bin", std::ios::binary);
    if (!writeFile) {
        std::cerr << "Failed to open file.\n";
        return;
    }

    for (int i = 0; i < size; ++i) {
        char name[JobOffer::SIZE];
        unsigned int programmers;
        int offDaysPaid;
        double salary;

        std::cout << "Enter the name of the company: \n";
        std::cin.ignore();
        std::cin.getline(name, JobOffer::SIZE);
    
        std::cout << "Enter amount of programmers: \n";
        std::cin >> programmers;

        std::cout << "Enter amount of paid off days: \n";
        std::cin >> offDaysPaid;

        std::cout << "Enter amount of money for the work: \n";
        std::cin >> salary;
           
        JobOffer job(salary, programmers, offDaysPaid, name);
        writeFile.write(reinterpret_cast<char*>(&job), sizeof(JobOffer));
    }
    writeFile.close();

}


void addOffers(JobOffer** jobOffers, const int size) {
    std::cout << "Enter how many offers you want to create: \n";
    unsigned int n;
    std::cin >> n;

    if (n > size - 1 ) {
        std::cout << "Not enough slots for offers!\n";
        return;
    }
    makeOffer(n, size);
    

}

void setOffers(JobOffer** jobOffers, const int size, int ind) {
    std::ifstream readFile("C:\\Users\\vikik\\Desktop\\offers.bin", std::ios::binary);
    JobOffer temp;
    while (readFile.read(reinterpret_cast<char*>(&temp), sizeof(JobOffer))) {
        if (ind >= size) {
            std::cout << "All offer slots are taken!\n";
            readFile.close();
            return;
        }
        jobOffers[ind] = new JobOffer(temp.salary, temp.programmers, temp.offDaysPaid, temp.name);
        ++ind;
    }
    readFile.close();
}

void filterOffer(const char* filePath, size_t minSalary, const int size, JobOffer** jobOffers) {
    std::ifstream readFile(filePath, std::ios::binary);
    if (!readFile) {
        std::cerr << "Couldn't open file for reading.\n";
        return;
    }
    for (int i = 0; i < size; ++i) {
        if (jobOffers[i]->salary > minSalary) {
            jobOffers[i]->printJob();        
        }
    
    }
    readFile.close();
}

bool findOffer(const char* filePath, const char* chosenName, const int size, JobOffer** jobOffers) {
    std::ifstream readFile(filePath, std::ios::binary);
    if (!readFile) {
        std::cerr << "Couldn't open file for reading.\n";
        return;
    }
    for (int i = 0; i < size; ++i) {
        if (std::strcmp(jobOffers[i] -> name, chosenName) == 0) {
            return true;
        }

    }
    return false;
}


int main() {
    const int JOB_OFFERS = 20;

    std::cout << "Enter minimal salary: \n";
    size_t minSalary;
    std::cin >> minSalary;

    std::cout << "Enter one job's name: \n";
    char name[JOB_OFFERS];
    std::cin.ignore();
    std::cin.getline(name, JobOffer::SIZE);

    
    JobOffer** jobOffers = new JobOffer*[JOB_OFFERS];
    addOffers(jobOffers, JOB_OFFERS);

    setOffers(jobOffers, JOB_OFFERS, 0);

    filterOffer("C:\\Users\\vikik\\Desktop\\offers.bin", minSalary, JOB_OFFERS, jobOffers);
    std::cout << std::boolalpha << findOffer("C:\\Users\\vikik\\Desktop\\offers.bin", name, JOB_OFFERS, jobOffers);
}

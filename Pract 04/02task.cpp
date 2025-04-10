#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <cstring>

enum Type { ELECTRONICS, CLOTHING, BOOKS, FOOD, BEAUTY };

struct Product {
    static const int SIZE = 100;
    char name[SIZE];
    char deliveryGuy[SIZE];
    double price;
    int quantity;
    Type type;

    Product(const char* n = "Unknown", const char* dg = "Unknown guy", double p = 0.0, int q = 0, Type t = ELECTRONICS) {
        strncpy_s(name, n, SIZE - 1);
        name[SIZE - 1] = '\0';

        strncpy_s(deliveryGuy, dg, SIZE - 1);
        deliveryGuy[SIZE - 1] = '\0';

        price = p;
        quantity = q;
        type = t;
    }

    void changeQuantity(unsigned int newQuantity) {
        quantity = newQuantity;
    }

    void printSpecificProduct() const {
        std::cout << "Name: " << name << "\n";
        std::cout << "Delivery Guy: " << deliveryGuy << "\n";
        std::cout << "Price: " << price << "\n";
        std::cout << "Quantity: " << quantity << "\n";
        std::cout << "Type: ";

        switch (type) {
            case ELECTRONICS:   std::cout << "Electronics\n"; break;
            case CLOTHING:      std::cout << "Clothing\n"; break;
            case BOOKS:         std::cout << "Books\n"; break;
            case FOOD:          std::cout << "Food\n"; break;
            case BEAUTY:        std::cout << "Beauty\n"; break;
            default:            std::cout << "Unknown\n"; break;        
        }

        std::cout << std::endl;
    }


};

bool isProductInShop(Product** products, const int ind, Product& temp) {
    for (int i = 0; i < ind; ++i) {
        if (std::strcmp(products[i]->name, temp.name) == 0) {
            return true;            
        }    
    }
    return false;
}

void setProducts(std::ifstream& file, Product** products, const int size, int ind) {
    Product temp; 
    while (file.read(reinterpret_cast<char*>(&temp), sizeof(Product))) {
        if (ind >= size) {
            std::cout << "Shop is full of products!\n";
            return;
        }

        if (isProductInShop(products, ind, temp)) {
            std::cout << "Product with name " << temp.name << " already exists!\n";
            continue;         
        }

        products[ind] = new Product(temp.name, temp.deliveryGuy, temp.price, temp.quantity, temp.type);
        ++ind; 
    }
};

void writeNewProducts() {
    std::ofstream writeFile("C:\\Users\\vikik\\Desktop\\products.bin", std::ios::binary | std::ios::app);
    if (!writeFile) {
        std::cerr << "Failed to open file.\n";
        return;
    }

    std::cout << "How many products do you want to add today?: \n";
    unsigned int count;
    std::cin >> count;

    for (int i = 0; i < count; ++i) {
        char name[Product::SIZE], deliveryGuy[Product::SIZE];
        double price;
        int quantity;
        int typeInt;

        std::cout << "Enter name: ";
        std::cin.ignore();
        std::cin.getline(name, Product::SIZE);

        std::cout << "Enter delivery guy: ";
        std::cin.getline(deliveryGuy, Product::SIZE);

        std::cout << "Enter price: ";
        std::cin >> price;

        std::cout << "Enter quantity: ";
        std::cin >> quantity;

        std::cout << "Enter type (0=ELECTRONICS, 1=CLOTHING, 2=BOOKS, 3=FOOD, 4=BEAUTY): ";
        std::cin >> typeInt;
      
        Product p(name, deliveryGuy, price, quantity, static_cast<Type>(typeInt));
       
        writeFile.write(reinterpret_cast<const char*>(&p), sizeof(Product));
        writeFile.close();
    }
}
void updateFile(const char* productName, int newQuantity) {
    std::fstream file("C:\\Users\\vikik\\Desktop\\products.bin", std::ios::binary | std::ios::in | std::ios::out);
    if (!file) {
        std::cerr << "Couldn't open the file.\n";
        return;
    }
    Product temp;
    while (file.read(reinterpret_cast<char*>(&temp), sizeof(Product))) {
        if (std::strcmp(temp.name, productName) == 0) {
            temp.quantity = newQuantity;

            // Move the file pointer back to overwrite the current record
            std::streampos pos = file.tellg();
            file.seekp(pos - static_cast<std::streamoff>(sizeof(Product)));

            // Write the updated product
            file.write(reinterpret_cast<char*>(&temp), sizeof(Product));

            file.close();
            return;
        }
    }

    std::cout << "Product not found in file.\n";
    file.close();
}

void changeQuantity( Product** products, const int size) {

    char productName[Product::SIZE];
    std::cout << "Which product do you want to change?: \n";
    std::cin.ignore();
    std::cin.getline(productName, Product::SIZE);

    std::cout << "Change quantity to: \n";
    unsigned int newQuantity;
    std::cin >> newQuantity;

    for (int i = 0; i < size; ++i) {
        //check if product exists
        if (std::strcmp(products[i]->name, productName) == 0) {
            products[i]->changeQuantity(newQuantity);
            break;
        }       
    }    

    //update file
    updateFile(productName, newQuantity);
}

void coutAll(Product** products, const int size) {
    for (int i = 0; i < size; ++i) {
        products[i] -> printSpecificProduct(); 
    }
}

void printProductByName(Product** products,const int size) {
    std::cout << "Enter the product's name you want to display: \n";
    char chosenName[Product::SIZE];
    std::cin.ignore();
    std::cin.getline(chosenName, Product::SIZE);
    //check if it exists
    for (int i = 0; i < size; ++i) {
        if (std::strcmp(products[i]->name, chosenName) == 0) {
            products[i]->printSpecificProduct();
            return;
        }
    }
    std::cout << "Product not found: " << chosenName << std::endl;
}


void fillCategoryFile(Product** products, const int size) {
    std::ofstream newWriteFile("C:\\Users\\vikik\\Desktop\\category.bin", std::ios::binary);
    if (!newWriteFile) {
        std::cerr << "Error opening file! \n";
    }
    std::cout << "Choose product's category: \n";
    std::cout << "Enter type (0=ELECTRONICS, 1=CLOTHING, 2=BOOKS, 3=FOOD, 4=BEAUTY): \n";
    int typeInt;
    std::cin >> typeInt;

    Product temp;
    for (int i = 0; i < size; ++i) {

        if (products[i]->type == static_cast<Type>(typeInt)) {
            newWriteFile.write(reinterpret_cast<char*>(&temp), sizeof(Product));            
        }
    
    }
    newWriteFile.close();
}
int main() {
    const int MAX_PRODUCTS = 20;
    //already put stuff in the file
    std::ifstream readFile("C:\\Users\\vikik\\Desktop\\products.bin", std::ios::binary);
    try {
        if (!readFile) {
            throw std::ios_base::failure("Mistake opening file!");
        }
    }
    catch (const std::ios_base::failure& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    Product** products = new Product*[MAX_PRODUCTS];

    //Зареждане на продуктите от двоичен файл в паметта;
    setProducts(readFile, products, MAX_PRODUCTS, 0);
    readFile.close();

    /*По подаден двоичен файл да се вкарат n продукта, като информация за тях се чете от конзолата. 
    Ако информацията, въведена за някой продукт, е валидна, и ако няма вече такова име на продукт във файла, 
    продуктът се запазва в двоичния файл;*/
    writeNewProducts();


    /*Промяна на информацията за наличното количество от даден продукт и записване на новите данни във файла;*/
    changeQuantity(products, MAX_PRODUCTS);

    /*Извеждане на информация за всички продукти от склада;*/
    coutAll(products, MAX_PRODUCTS);

    /*Извеждане на информация за конкретен продукт по подадено име;*/
    printProductByName(products, MAX_PRODUCTS);
   
    /*По подадено име на друг файл и категория да се запишат всички продукти от дадената категория 
    в съответния файл.*/
    fillCategoryFile(products, MAX_PRODUCTS);    
}

#include <iostream>
#include <cstring>

struct Book {
    static const int SIZE = 50;
    char name[SIZE] = "none";
    char author[SIZE] = "none";
    enum GenreType { NOVEL, POETRY, HISTORICAL, OTHERS } selectedGenre;
    struct Genre {
        int novel = 9;
        int poetry = 7;
        int historical = 0;
        int others = 23;
    } genre;

    int amount = 0;

    int getGenreAmount() const {
        switch (selectedGenre) {
        case NOVEL:
            return genre.novel;
        case POETRY:
            return genre.poetry;
        case HISTORICAL:
            return genre.historical;
        case OTHERS:
            return genre.others;
        default:
            return 0;
        }
    }
};
//note: individual books, not really engaged with the amount of each book
struct Library {
    static const short NUM_BOOKS = 10;
    Book books[NUM_BOOKS];
    short currentBookCount = 0;

};


void addBook(Library& library, Book* book) {
    if (library.currentBookCount < Library::NUM_BOOKS) {
        library.books[library.currentBookCount] = *book; 
        library.currentBookCount++;
    }
    else {
        std::cout << "Library is full!" << std::endl;
    }
}
int isReal(Library& library, Book* book) {
    for (int i = 0; i < library.currentBookCount; i++) {
        if (std::strcmp(book->name, library.books[i].name) == 0) {
            return i;
        }
    }
    return -1;

}
void getBook(Library& library, Book* book) {
    //check if it exists
    int realBook = isReal(library, book);
    //check for amount
    if (realBook > -1) {
        if (library.books[realBook].amount > 0) {
            library.books[realBook].amount -= 1;
            std::cout << "You have 30 days to return this book.\n";
        }
        else {
            std::cout << "This book is already taken! Sorry!\n";
        }
    }
    else {
        std::cout << "Book doesn't exists.\n";
    }
}
void giveBook(Library& library, Book* book) {
    //check if it exists
    int realBook = isReal(library, book);
    if (realBook > -1) {
        library.books[realBook].amount += 1;
        std::cout << "Thanks for returning this totaly existing book!\n";
    }
    else {
        char answer;
        std::cout << "You are returning a book that's not registered!\nDo you want to donate this book: y/n?\n";
        std::cin >> answer;
        if (answer == 'y') {
            addBook(library, book);
        } 
    }
}

void displayBooks(const Library& library) {
    for (int i = 0; i < library.currentBookCount; i++) {
        std::cout << "Book " << i + 1 << ": "
            << library.books[i].name << " by "
            << library.books[i].author
            << ", Genre: " << library.books[i].selectedGenre
            << ", Amount: " << library.books[i].amount << std::endl;
    }
}


int main() {
    Book* book1 = new Book{ "I cannot make this shit up","viki", Book::NOVEL };
    Book* book2 = new Book{ "Historical Chronicles","viki", Book::HISTORICAL };
    Book* book4 = new Book{ "The Incredible Misadventures of Flapjack", "unknown", Book::NOVEL };

    book1->amount = book1->getGenreAmount();
    book2->amount = book2->getGenreAmount();
    book4->amount = book4->getGenreAmount();

    Library library;

    addBook(library, book1);
    addBook(library, book2);

    getBook(library, book1);
    giveBook(library, book4);

    displayBooks(library);
    
    //?? can't find a way to delete
    /*since it's a small program, there won't be a problem to let the program delete
    the used dynamic memory after the program ends...*/

    
}

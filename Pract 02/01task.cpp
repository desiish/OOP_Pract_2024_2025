#include <iostream>
#include <cstring>
#pragma warning (disable : 4996)
#include <cctype>
namespace Constants 
{
    const int SIZE = 50;
    const int NUM_BOOKS = 10;
}

struct Book {
    char name[Constants::SIZE] = "";
    char author[Constants::SIZE] = "";
    enum class GenreType 
    { 
        NOVEL, 
        POETRY, 
        HISTORICAL, 
        OTHERS 
    } selectedGenre;

    int amount = 0;
};

struct Library 
{    
    Book books[Constants::NUM_BOOKS];
    short currentBookCount = 0;


};

bool isBookInLibrary(Book& book, Library& libraryShelf)
{
    for (int i = 0; i < libraryShelf.currentBookCount; ++i)
    {
        if (std::strcmp(book.name, libraryShelf.books[i].name) == 0)
        {
            return true;
        }
      
    }
    return false;
}
void addBook(Book& book, Library& libraryShelf)
{
    //check limit
    if (libraryShelf.currentBookCount == Constants::NUM_BOOKS - 1)
    {
        std::cout << "Limit is reached. Can't add a book.\n";
        return;
    }
    //check if book is already there
    else if (isBookInLibrary(book, libraryShelf)) 
    {
        std::cout << "Can't add the same book twice.\n";
        return;
    }
    
    //if book is not available
    else if (book.amount == 0) 
    {
        std::cout << "Book is not available. Can't add the book.\n";
        return;
    }
    libraryShelf.books[libraryShelf.currentBookCount] = book;
    libraryShelf.currentBookCount++;
}

void getBookByName(Book& book, Library& libraryShelf)
{
    if (!isBookInLibrary(book, libraryShelf))
    {
        std::cout << "No such book.\n";
        return;
    }
    else if (book.amount == 0)
    {
        std::cout << "Book is out of stock.\n";
        return;
    }
    std::cout << "Book taken\n";
    book.amount--;
    
}

void returnBookByName(Book& book, Library& libraryShelf)
{
    if (isBookInLibrary(book, libraryShelf))
    {
        std::cout << "Book returned.\n";
        book.amount++;
        return;
    }
    else {
        char answer;
        std::cout << "This is a new book. Would you like make a donation?: Y/N\n";
        std::cin >> answer;
        answer = std::tolower(static_cast<unsigned char>(answer));

        if (answer == 'y')
        {
            Book newBook;
            std::strcpy(newBook.name, book.name);
            std::strcpy(newBook.author, book.author);
            newBook.selectedGenre = book.selectedGenre;
            newBook.amount = book.amount;
            addBook(newBook, libraryShelf);
        }
        else
        {
            std::cout << "Book not added.\n";
        }
    }

}
//for printning
const char* genreToString(Book::GenreType genre) {
    switch (genre) {
    case Book::GenreType::NOVEL: return "Novel";
    case Book::GenreType::POETRY: return "Poetry";
    case Book::GenreType::HISTORICAL: return "Historical";
    case Book::GenreType::OTHERS: return "Others";
    default: return "Unknown";
    }
}

void printAllBooksInLibrary(Library& libraryShelf)
{
    for (int i = 0; i < libraryShelf.currentBookCount; ++i)
    {
        std::cout << "Book: " << i + 1<< std::endl;
        std::cout << "Name: " << libraryShelf.books[i].name << std::endl;
        std::cout << "Author: " << libraryShelf.books[i].author << std::endl;
        std::cout << "Genre: " << genreToString(libraryShelf.books[i].selectedGenre) << std::endl;
        std::cout << "Amount: " << libraryShelf.books[i].amount << std::endl;

    }
}
int main() {
    Library libraryShelf1;
    Book book1 { "I cannot make this shit up","viki", Book::GenreType::NOVEL, 10 };
    Book book2 { "Historical Chronicles","viki", Book::GenreType::HISTORICAL , 0};
    Book book3 { "The Incredible Misadventures of Flapjack", "unknown", Book::GenreType::NOVEL, 12 };

    addBook(book1, libraryShelf1);
    getBookByName(book1, libraryShelf1);
    returnBookByName(book3, libraryShelf1);
    printAllBooksInLibrary(libraryShelf1);


}

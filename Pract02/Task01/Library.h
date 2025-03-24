#pragma once

#include "Book.h"

struct Library {
    static constexpr int MAX_BOOKS = 20;
    Book books[MAX_BOOKS];
    unsigned short countOfBooks;
};

void getLibraryInfo(const Library& library);
void addBook(Library& library, const Book& book);
void getBook(Library& library, const char* title);
void returnBook(Library& library, const char* title);
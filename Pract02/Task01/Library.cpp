#include <iostream>

#include "Library.h"

void getBook(Library& library, const char* title)
{
	for (int i = 0; i < library.countOfBooks;i++)
	{
		if (library.books[i].title == title)
			library.books[i].availability = false;
	}
}

void returnBook(Library& library, const char* title)
{
	for (int i = 0; i < library.countOfBooks; i++)
	{
		if (library.books[i].title == title)
			library.books[i].availability = true;
	}
}

void addBook(Library& library, const Book& book) 
{
	if (library.countOfBooks < library.MAX_BOOKS)
	{
		library.books[library.countOfBooks] = book;
	}
	else {
		std::cout << "The library has full capacity";
	}
}

void getLibraryInfo(const Library& library) 
{
	for (int i = 0; i < library.countOfBooks; i++) 
			printBook(library.books[i]);
}
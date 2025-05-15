#pragma once
#include "Book.h"

class Library 
{
private:
	Book* _books[UserConstants::BOOK_CAPACITY];
	size_t _count;

public:
	Library();
	~Library();

	//setters and getters
	void setSize(size_t _count);
	const size_t getSize() const;

	//additional
	void addBook(const char* title, const char* author, bool isAvailable = true);
	void borrowBook(size_t id, const User& user);
	void returnBook(size_t id);
	void printAllBooks() const;

	Book* findBookById(size_t bookId) const;
	bool isBookInLibrary(const char* name, size_t count);
};

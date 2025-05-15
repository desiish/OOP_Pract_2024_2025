#include "Library.h"
#include <iostream>
#include <stdexcept>
#include <cstring>
#pragma warning (disable : 4996)
//CTOR
Library::Library() 
	:_count(0)
{
	for (size_t i = 0; i < UserConstants::BOOK_CAPACITY; ++i)
	{
		_books[i] = nullptr;
	}
}
//DTOR
Library::~Library()
{
	for (size_t i = 0; i < UserConstants::BOOK_CAPACITY; ++i)
	{
		delete _books[i];
	}
}
bool Library::isBookInLibrary(const char* name, size_t count)
{
	for (size_t i = 0; i < count; ++i)
	{
		if (std::strcmp(name, _books[i]->getName()) == 0)
		{
			return true;
		}
	}
	return false;
}

void Library::addBook(const char* name, const char* author, bool isAvailable)
{
	if (isBookInLibrary(name, _count))
	{
		std::cout << "Book already added.\n";
		return;
	}
	if (name == nullptr || std::strcmp(name, "invalid") == 0)
	{
		std::cout << "A book with invalid data can not be addded. Skipping book.\n";
		return;
	}

	if (_count >= UserConstants::BOOK_CAPACITY)
	{
		std::cout << "Lihbrary is full!\n";
		return;
	}
	_books[_count] = new Book(name, author, isAvailable);
	++_count;

}

void Library::borrowBook(size_t bookId, const User& user)
{
	Book* book = findBookById(bookId);
	if (std::strcmp(user.getName(), "none") == 0)
	{
		std::cout << "Invalid user. Cannot borrow book.\n";
		return;
	}   
	if (bookId > _count)
	{
		std::cout << "Book not found! Try again\n";
		return;
	}
	else if (!book->getStatus())
	{
		book->printName();
		std::cout << "is taken.\n";
		return;
	}

	book->setStatus(false);
	book->setUser(user);
}

void Library::returnBook(size_t bookId)
{
	Book* book = findBookById(bookId);

	if (book == nullptr)
	{
		std::cout << "Book not in register. Cannot return.\n";
		return;
	}
	else if (book->getStatus())
	{
		std::cout << "You are trying to return a book that is already returned.\n";
		return;
	}
	book->setStatus(true);
	book->resetUser();
}

void Library::printAllBooks() const
{
	for (size_t i = 0; i < UserConstants::BOOK_CAPACITY; ++i)
	{
		const Book* book = _books[i];
		if (book)
		{
			std::cout
				<< "Id: " << book->getId()
				<< ", Title: " << book->getName()
				<< ", Author: " << book->getAuthor()
				<< ", Status: " << (book->getStatus() ? "Available" : "Borrowed") << std::endl;
			if (!book->getStatus())
			{
				std::cout << "Borrowed by: ";
				book->getUser().printName();
				std::cout << std::endl;
				book->getUser().printPhone();
				std::cout << std::endl;
			}
		}
	}
}

Book* Library::findBookById(size_t id) const
{
	for (int i = 0; i < _count; ++i) {
		if (_books[i] != nullptr && _books[i]->getId() == id) {
			return _books[i];
		}
	}
	return nullptr;
}

#include <iostream>

#include "Book.h"

Genre readGenre() 
{
	unsigned short genreNumber;
	do {
		std::cout << "Enter genre(number between 1 and 3)";
		std::cin >> genreNumber;
	} while (genreNumber < 1 || genreNumber>3);

	switch (genreNumber)
	{
		case 1:return  Genre::POETRY;
		case 2: return Genre::HISTORICAL;
		case 3: return Genre::NOVEL;
		default: return Genre::GENRE_UNKNOWN;
	}
}

Book readBook()
{
	Book book;

	std::cout << "Enter book title: ";
	std::cin >> book.title;

	std::cout << "Enter book author: ";
	std::cin >> book.author;

	book.genre = readGenre();
	book.availability = true;

	return book;
}

static void printGenre(Genre genre) 
{
	switch (genre) 
	{
	case Genre::POETRY: std::cout << "Poetry";
	case Genre::HISTORICAL: std::cout << "Historical";
	case Genre::NOVEL: std::cout << "Novel";
	default: std::cout << "Unknown genre";
	}

	std::cout << std::endl;
}

void printBook(const Book& book) 
{
	std::cout << "Book: " << book.title << std::endl;
	std::cout << "Author: " << book.author << std::endl;
	std::cout << "Genre: ";
	printGenre(book.genre);
	std::cout << "Availability: " << std::boolalpha << book.availability;
}
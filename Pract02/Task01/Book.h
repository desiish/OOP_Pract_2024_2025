#pragma once

enum class Genre {
    GENRE_UNKNOWN,
    POETRY,
    HISTORICAL,
    NOVEL
};

struct Book {
    char title[51];
    char author[51];
    Genre genre;
    bool availability;
};

void readBook(Book& book);
void printBook(const Book& book);
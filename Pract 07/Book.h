#pragma once
#include "User.h"
class Book
{
private:
	static size_t _idCounter;
	size_t _id;
	char* _name;
	char* _author;
	bool _isAvailable;
	User _user;

private:
	void freeDynamic();
	void copyDynamic(const Book& other);

public:
	Book(const char* name, const char* author, bool isAvailable);
	Book(const Book& other);
	Book& operator=(const Book& other);
	~Book();

	//getters
	const char* getName() const;
	const char* getAuthor() const;
	bool getStatus() const;
	User getUser() const;
	size_t getId() const;
	void printName();
	//setters
	void setName(const char* name);
	void setAuthor(const char* author);
	void setStatus(bool isAvailable);
	void setUser(const User& user);
	void resetUser();

};

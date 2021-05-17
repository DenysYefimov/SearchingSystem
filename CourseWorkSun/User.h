#pragma once
#include <list>
#include <algorithm>
#include "Book.h"

class User
{
	std::string first_name;
	std::string last_name;
	std::string date_of_birth;
	std::list<Book> books;
	static int counter;

public:
	User();
	User(std::string, std::string, std::string, Book&);
	User(const User&);
	std::string GetFirstName();
	std::string GetLastName();
	int GetCounter();
	User& AddBook(Book&);
	User& ReturnBook(Book&);
	User& operator=(const User&);
	friend std::istream& operator>>(std::istream&, User&);
	friend std::ostream& operator<<(std::ostream&, User&);
};


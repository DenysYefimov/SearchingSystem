#pragma once
#include <string>
#include <iostream>

class Book
{
	std::string name;
	std::string author;

public:

	Book();
	Book(std::string, std::string);
	Book(const Book&);
	std::string GetName();
	Book& AddToAuthor(char);
	bool operator==(const Book&);
	friend std::istream& operator>>(std::istream&, Book&);
	friend std::ostream& operator<<(std::ostream&, Book&);
};


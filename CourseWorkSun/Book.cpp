#include "Book.h"

Book::Book()
{
	name = "\"Empty\"";
	author = "None";
}

Book::Book(std::string author, std::string name)
{
	this->author = author;
	this->name = "\"" + name + "\"";
}

Book::Book(const Book & other)
{
	this->name = other.name;
	this->author = other.author;
}

std::string Book::GetName()
{
	return name;
}

Book& Book::AddToAuthor(char ch)
{
	author = ch + author;
	return *this;
}

bool Book::operator==(const Book& other)
{
	if (this->author == other.author && this->name == other.name)
		return true;
	else return false;
}

std::istream& operator>>(std::istream& in, Book& book)
{
	std::string temp_last, temp_first, temp_name, rubish;
	in >> temp_first >> temp_last;
	book.author = temp_first + " " + temp_last;
	std::getline(in, rubish, '\"');
	std::getline(in, temp_name, '\"');
	book.name = "\"" + temp_name + "\"";
	std::getline(in, rubish, '\n');

	return in;
}

std::ostream& operator<<(std::ostream& out, Book& book)
{
	out << book.author << ' ' << book.name;
	return out;
}
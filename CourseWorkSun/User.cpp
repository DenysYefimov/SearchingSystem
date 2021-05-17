#include "User.h"

int User::counter = 6;

User::User()
{
	first_name = "None";
	last_name = "None";
	date_of_birth = "None";
}

User::User(std::string first_name, std::string last_name, std::string date_of_birth, Book & book)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->date_of_birth = date_of_birth;
	books.push_back(book);
	++counter;
}

User::User(const User & other)
{
	this->first_name = other.first_name;
	this->last_name = other.last_name;
	this->date_of_birth = other.date_of_birth;
	for (Book book : other.books)
	{
		this->books.push_back(book);
	}
}

std::string User::GetFirstName()
{
	return first_name;
}

std::string User::GetLastName()
{
	return last_name;
}

int User::GetCounter()
{
	return counter;
}

User& User::AddBook(Book& book)
{
	this->books.push_back(book);
	return *this;
}

User& User::ReturnBook(Book& book)
{
	books.erase(std::find(books.begin(), books.end(), book));

	return *this;
}

User& User::operator=(const User& other)
{
	this->first_name = other.first_name;
	this->last_name = other.last_name;
	this->date_of_birth = other.date_of_birth;
	this->books.clear();
	for (Book book : other.books)
	{
		this->books.push_back(book);
	}
	return *this;
}

std::istream& operator>>(std::istream& in, User& user)
{
	std::string temp, rubish;
	char ch = '\n';
	in >> temp;
	user.first_name = temp;
	in >> temp;
	user.last_name = temp;
	in >> temp;
	user.date_of_birth = temp;
	std::getline(in, rubish, '\n');
	user.books.clear();
	Book temp_book;
	do
	{
		in >> temp_book;
		if (ch != '\n') temp_book.AddToAuthor(ch);
		user.books.push_back(temp_book);
		in.get(ch);
	} while (ch != '\n');
	return in;
}

std::ostream& operator<<(std::ostream& out, User& user)
{
	out << user.first_name << ' ' << user.last_name << ' ' << user.date_of_birth;
	for (Book book: user.books)
	{
		out << std::endl << book;
	}
	return out;
}
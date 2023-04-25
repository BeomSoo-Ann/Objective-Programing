#pragma once
using namespace std;
#include<iostream>
#include <string>

class Book {
private:
	string title;
	string author;
	int year;
	string genre;
public:
	Book();
	~Book();
	void setTitle(std::string newTitle);
	void setAuthor(std::string newAuthor);
	void setYear(int newYear);
	void setGenre(std::string newGenre);
	string getTitle() const;
	string getAuthor() const;
	int getYear() const;
	string getGenre() const;
	void displayBook(std::ostream& out) const;
};

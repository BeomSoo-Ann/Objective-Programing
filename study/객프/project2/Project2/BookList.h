#pragma once
#include <string>
#include"Book.h""
using namespace std;


class BookList {
	Book books[10];
	int count;
	int size;
	void slideUp(int location);
	void slideDown(int location);
public:
	BookList();
	void addBookAt(Book b, int location);
	void addBook(Book b);
	Book findBook(int location) const;
	Book removeBook(int location);
	void displayBooks(std::ostream& out) const;
};


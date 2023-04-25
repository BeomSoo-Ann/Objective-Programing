#include"BookList.h"

	//Book books[10];
	//int count;
	//int size;
BookList::BookList() : count(0), size(10) {}
void BookList::addBookAt(Book b, int location) {
	if (count < size) {
		
		if (location < 0) {
			slideUp(0);
			books[0] = b;
			count++;
		}

		if (location > count) books[++count] = b;

		if (location < count && location >= 0) {
			slideUp(location);
			count++;
			books[0] = b;
		}
	}

}
void BookList::addBook(Book b) {
	books[++count] = b;
	}
Book BookList::findBook(int location) const {
	Book book;
	if (location >= 0 && location < count) {
		return books[location];
	}
	else return book;
}
Book BookList::removeBook(int location) {
	Book DB;
	if (location >= 0 && location < count) {
		Book pop = books[location];
		slideDown(location);
		count--;
		return pop;
	}
	else return DB;
	}

void BookList::displayBooks(std::ostream& out) const {
	for (int i = 0; i < count; i++) {
		books[i].displayBook(cout);
	}

	}
void BookList::slideUp(int location) {
	for (int i = location; i < count; i++) {
		books[i + 1] = books[i];
	}
}
void BookList::slideDown(int location) {
	for (int i = location; i < count; i++) {
		books[i] = books[i + 1];
	}
}
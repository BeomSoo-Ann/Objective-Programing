#include "Book.h"
using namespace std;
Book::Book() : title(""), author(""), year(2016), genre("") {}
Book::~Book() {}
void Book::setTitle(std::string newTitle) {
	title = newTitle;
}
void Book::setAuthor(std::string newAuthor) {
	author = newAuthor;
}
void Book::setYear(int newYear) {
	year = newYear;
}
void Book::setGenre(std::string newGenre)
{
	genre = newGenre;
}
string Book::getTitle() const {
	return title;
}
string Book::getAuthor() const {
	return author;
}
int Book::getYear() const {
	return year;
}
string Book::getGenre() const {
	return genre;
}
void Book::displayBook(std::ostream& out) const {

}
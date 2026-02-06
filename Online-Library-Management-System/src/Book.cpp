#include "../include/Book.h"

Book::Book() : id(0), title(""), author(""), year(0), borrowed(false) {}

Book::Book(int id_, const std::string &title_, const std::string &author_, int year_)
    : id(id_), title(title_), author(author_), year(year_), borrowed(false) {}

int Book::getId() const { return id; }
const std::string &Book::getTitle() const { return title; }
const std::string &Book::getAuthor() const { return author; }
int Book::getYear() const { return year; }
bool Book::isBorrowed() const { return borrowed; }
void Book::setBorrowed(bool b) { borrowed = b; }

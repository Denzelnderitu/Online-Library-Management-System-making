
#include "../include/User.h"

User::User() : id(0), name("") {}

User::User(int id_, const std::string &name_) : id(id_), name(name_) {}

int User::getId() const { return id; }
const std::string &User::getName() const { return name; }

bool User::borrowBook(int bookId) {
    std::pair<std::set<int>::iterator, bool> res = borrowedBooks.insert(bookId);
    return res.second;
}

bool User::returnBook(int bookId) {
    return borrowedBooks.erase(bookId) > 0;
}

bool User::hasBorrowed(int bookId) const {
    return borrowedBooks.find(bookId) != borrowedBooks.end();
}

const std::set<int> &User::getBorrowed() const { return borrowedBooks; }

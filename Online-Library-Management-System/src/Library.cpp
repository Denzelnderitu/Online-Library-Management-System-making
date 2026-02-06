
#include "../include/Library.h"
#include <algorithm>

Library::Library() {}

bool Library::addBook(const Book &book) {
    int id = book.getId();
    if (books.find(id) != books.end()) return false;
    books.insert(std::make_pair(id, book));
    return true;
}

bool Library::removeBook(int bookId) {
    std::map<int, Book>::iterator it = books.find(bookId);
    if (it == books.end()) return false;
    if (it->second.isBorrowed()) return false;
    books.erase(it);
    return true;
}

std::vector<Book> Library::searchByTitle(const std::string &title) const {
    std::vector<Book> out;
    for (std::map<int, Book>::const_iterator it = books.begin(); it != books.end(); ++it) {
        const Book &b = it->second;
        if (b.getTitle().find(title) != std::string::npos) out.push_back(b);
    }
    return out;
}

std::vector<Book> Library::searchByAuthor(const std::string &author) const {
    std::vector<Book> out;
    for (std::map<int, Book>::const_iterator it = books.begin(); it != books.end(); ++it) {
        const Book &b = it->second;
        if (b.getAuthor().find(author) != std::string::npos) out.push_back(b);
    }
    return out;
}

Book* Library::findBook(int bookId) {
    std::map<int, Book>::iterator it = books.find(bookId);
    if (it == books.end()) return NULL;
    return &it->second;
}

bool Library::addUser(const User &user) {
    int id = user.getId();
    if (users.find(id) != users.end()) return false;
    users.insert(std::make_pair(id, user));
    return true;
}

bool Library::removeUser(int userId) {
    std::map<int, User>::iterator it = users.find(userId);
    if (it == users.end()) return false;
    if (!it->second.getBorrowed().empty()) return false;
    users.erase(it);
    return true;
}

User* Library::findUser(int userId) {
    std::map<int, User>::iterator it = users.find(userId);
    if (it == users.end()) return NULL;
    return &it->second;
}

bool Library::borrowBook(int userId, int bookId, std::string &err) {
    User* u = findUser(userId);
    if (!u) { err = "User not found"; return false; }
    Book* b = findBook(bookId);
    if (!b) { err = "Book not found"; return false; }
    if (b->isBorrowed()) { err = "Book already borrowed"; return false; }
    // perform borrow
    b->setBorrowed(true);
    u->borrowBook(bookId);
    return true;
}

bool Library::returnBook(int userId, int bookId, std::string &err) {
    User* u = findUser(userId);
    if (!u) { err = "User not found"; return false; }
    Book* b = findBook(bookId);
    if (!b) { err = "Book not found"; return false; }
    if (!b->isBorrowed()) { err = "Book is not borrowed"; return false; }
    if (!u->hasBorrowed(bookId)) { err = "This user did not borrow this book"; return false; }
    b->setBorrowed(false);
    u->returnBook(bookId);
    return true;
}

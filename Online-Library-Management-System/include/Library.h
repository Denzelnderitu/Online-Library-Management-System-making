#pragma once
#include "Book.h"
#include "User.h"
#include <map>
#include <vector>
#include <string>

class Library {
private:
    std::map<int, Book> books;
    std::map<int, User> users;
public:
    Library();

    bool addBook(const Book &book);
    bool removeBook(int bookId);
    std::vector<Book> searchByTitle(const std::string &title) const;
    std::vector<Book> searchByAuthor(const std::string &author) const;
    Book* findBook(int bookId);

    bool addUser(const User &user);
    bool removeUser(int userId);
    User* findUser(int userId);

    bool borrowBook(int userId, int bookId, std::string &err);
    bool returnBook(int userId, int bookId, std::string &err);
};

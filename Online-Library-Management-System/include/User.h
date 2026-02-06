#pragma once
#include <string>
#include <set>

class User {
private:
    int id;
    std::string name;
    std::set<int> borrowedBooks;
public:
    User();
    User(int id, const std::string &name);

    int getId() const;
    const std::string &getName() const;

    bool borrowBook(int bookId);
    bool returnBook(int bookId);
    bool hasBorrowed(int bookId) const;
    const std::set<int> &getBorrowed() const;
};

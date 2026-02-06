#pragma once
#include <string>

class Book {
private:
    int id;
    std::string title;
    std::string author;
    int year;
    bool borrowed;
public:
    Book();
    Book(int id, const std::string &title, const std::string &author, int year);

    int getId() const;
    const std::string &getTitle() const;
    const std::string &getAuthor() const;
    int getYear() const;
    bool isBorrowed() const;

    void setBorrowed(bool b);
};

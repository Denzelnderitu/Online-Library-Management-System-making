#include <iostream>
#include <cassert>
#include "../include/Library.h"

void runAll() {
    Library lib;

    // add books
    assert(lib.addBook(Book(1, "A", "Author1", 2000)) == true);
    assert(lib.addBook(Book(2, "B", "Author2", 2001)) == true);
    // duplicate add
    assert(lib.addBook(Book(1, "A", "Author1", 2000)) == false);

    // add users
    assert(lib.addUser(User(10, "User1")) == true);
    assert(lib.addUser(User(11, "User2")) == true);
    // duplicate user
    assert(lib.addUser(User(10, "User1")) == false);

    std::string err;
    // borrow success
    assert(lib.borrowBook(10, 1, err) == true);
    // borrow already borrowed
    assert(lib.borrowBook(11, 1, err) == false);
    // borrow non-existent book
    assert(lib.borrowBook(10, 999, err) == false);
    // borrow non-existent user
    assert(lib.borrowBook(999, 2, err) == false);

    // return success
    assert(lib.returnBook(10, 1, err) == true);
    // return not borrowed
    assert(lib.returnBook(10, 1, err) == false);
    // remove book that's not borrowed
    assert(lib.removeBook(2) == true);
    // remove non-existent
    assert(lib.removeBook(999) == false);

    // search
    std::vector<Book> res = lib.searchByAuthor("Author1");
    assert(res.size() == 1);

    std::cout << "All tests passed.\n";
}

int main() {
    try {
        runAll();
    } catch (const std::exception &e) {
        std::cerr << "Test failed with exception: " << e.what() << '\n';
        return 1;
    }
    return 0;
}

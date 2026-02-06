#include <iostream>
#include "../include/Library.h"

int main() {
    Library lib;
    lib.addBook(Book(1, "The C++ Programming Language", "Bjarne Stroustrup", 2013));
    lib.addBook(Book(2, "Clean Code", "Robert C. Martin", 2008));
    lib.addUser(User(1, "Alice"));

    std::string err;
    if (lib.borrowBook(1, 2, err)) std::cout << "Alice borrowed 'Clean Code'\n";
    else std::cout << "Borrow failed: " << err << '\n';

    if (lib.returnBook(1, 2, err)) std::cout << "Alice returned 'Clean Code'\n";
    else std::cout << "Return failed: " << err << '\n';

    return 0;
}

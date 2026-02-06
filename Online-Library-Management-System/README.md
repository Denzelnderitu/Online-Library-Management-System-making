# Online Library Management System (C++)

Overview
- Simple OOP-based library management system implemented in C++.

Structure
- include/: headers (`Book.h`, `User.h`, `Library.h`)
- src/: implementations and `main.cpp`
- tests/: unit tests `tests.cpp`

Build & Run (CLI)
1. Create build directory and run CMake
```bash
mkdir build && cd build
cmake ..
cmake --build .
```
2. Run demo
```bash
./demo    # or demo.exe on Windows
```
3. Run tests
```bash
./tests   # or tests.exe on Windows
```

Design notes
- `Book` encapsulates book data and borrowed state.
- `User` maintains borrowed book ids.
- `Library` stores collections and provides operations for add/remove/search/borrow/return.

GitHub
- To publish: create a repo and push this folder. Example:
```bash
cd Online-Library-Management-System
git init
git add .
git commit -m "Initial commit: Online Library Management System (C++)"
git remote add origin <your-repo-url>
git push -u origin main
```
# Online-Library-Management-System
C++ OOP project for managing books, users, borrowing and returning.

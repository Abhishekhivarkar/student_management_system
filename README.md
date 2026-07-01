# Student Management System (C)

A simple console-based Student Management System developed in C. The project stores student records in a text file and provides basic CRUD (Create, Read, Search, Delete) operations using file handling.

## Features

- Add Student
- Search Student by ID
- Delete Student
- Display All Students
- Persistent storage using text files
- Duplicate Student ID validation

## Project Structure

```
student_management_system/
│
├── data/
│   └── students.txt
│
├── include/
│   ├── common.h
│   ├── database.h
│   ├── student.h
│   └── ui.h
│
├── src/
│   ├── database/
│   │   └── database.c
│   ├── ui/
│   │   └── ui.c
│   ├── student/
│   │   └── student.c
│   └── main.c
│
└── Makefile
```

## Concepts Used

- Structures (`struct`)
- Header Files
- Functions
- File Handling (`fopen`, `fprintf`, `fscanf`, `fclose`)
- Pointers
- Dynamic program flow using menu
- Search Algorithms
- Delete operation using temporary file
- Modular Programming
- Boolean Enumeration (`bool_t`)

## File Handling

Student records are stored in:

```
data/students.txt
```

Example:

```
101,Abhishek,21,90.50
102,Rahul,20,82.00
```

## Operations

### Add Student

- Takes student details from the user.
- Checks whether the Student ID already exists.
- Stores the record in `students.txt`.

### Search Student

- Searches using Student ID.
- Displays complete student information if found.

### Delete Student

- Reads every record from the database.
- Skips the matching Student ID.
- Copies remaining records into a temporary file.
- Replaces the old database with the updated file.

### Display All Students

- Reads every record from the file.
- Displays all stored student information.

## What I Learned

During this project I learned:

- Organizing a C project using multiple source and header files.
- Creating reusable functions.
- Passing structures using pointers.
- Using `->` and `.` operators correctly.
- Reading and writing structured data using `fprintf()` and `fscanf()`.
- Implementing CRUD operations using file handling.
- Searching records efficiently.
- Deleting records using a temporary file.
- Working with pointers and memory addresses.
- Separating User Interface and Database logic.
- Building a menu-driven console application.
- Basic debugging and error handling using return values.

## Technologies

- C
- GCC (MinGW)
- Make
- VS Code

## Build

```
make
```

or

```
gcc src/main.c src/database/database.c src/ui/ui.c -Iinclude -o student_management_system
```

## Run

Windows

```
student_management_system.exe
```

Linux

```
./student_management_system
```

## Future Improvements

- Update Student
- Sort Students
- Binary File Storage
- Data Validation
- Login System
- Search by Name
- Pagination
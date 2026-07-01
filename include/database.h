#ifndef DATABASE_H
#define DATABASE_H

#include "student.h"

#define DATABASE_FILE "/data/students.txt"

void init_database(void);

bool_t create_student(const Student *student);

bool_t delete_student(int id);

boot_t search_student(int id, Student *student);

void display_all_student(void);


#endif
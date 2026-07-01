#ifndef DATABASE_H
#define DATABASE_H

#include "student.h"

#define DATABASE_FILE "data/students.txt"

void init_database(void);

bool_t create_student(Student *student);

bool_t delete_student(int id);

bool_t search_student(int id, Student *student);

bool_t display_all_students(void);


#endif
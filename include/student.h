#ifndef STUDENT_H
#define STUDENT_H

#include "common.h"

typedef struct {
 int id;
 char name[MAX_NANE_LEN];
 int age;
 float marks;
} Student;

#endif
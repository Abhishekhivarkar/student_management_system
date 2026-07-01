#include "../../include/common.h"
#include "../../include/database.h"
#include <stdio.h>
#include <stdlib.h>
void display_menu(void)
{
  printf("\n========================================\n");
  printf("       STUDENT MANAGEMENT SYSTEM\n");
  printf("========================================\n");
  printf("1. Add Student\n");
  printf("2. Search Student\n");
  printf("3. Delete Student\n");
  printf("4. Display All Students\n");
  printf("0. Exit\n");
  printf("----------------------------------------\n");
  printf("Enter your choice: ");
}

void input_student(void)
{
  Student student;
  printf("\n========= Add Student ==========\n");
  printf("Enter Id : ");
  scanf("%d", &student.id);

  printf("Enter Name : ");
  scanf(" %49[^\n]", student.name);

  printf("Enter Age : ");
  scanf("%d", &student.age);

  printf("Enter Marks : ");
  scanf("%f", &student.marks);

  if (create_student(&student))
  {
    printf("Student created successfully");
  }
  else
  {
   
    printf("id %d\n",student.id);
     printf("name %s\n",student.name);
      printf("age %d\n",student.age);
       printf("marks %.2f\n",student.marks);
    printf("Failed to create student");
  }
}

void search_student_ui(void)
{
  Student student;
  int id;
  printf("=========== Search Student ==========\n");

  printf("Enter Id : ");
  scanf("%d", &id);

  if (search_student(id, &student))
  {
    printf("Student found\n");
    printf("Student id : %d\n", student.id);
    printf("Student id : %s\n", student.name);
    printf("Student id : %d\n", student.age);
    printf("Student id : %.2f\n", student.marks);
  }
  else
  {
    printf("Student not found");
  }
}

void delete_student_ui(void)
{
  int id;
  printf("=========== Delete Student ==========\n");

  printf("Enter Id : ");
  scanf("%d", &id);

  if (delete_student(id))
  {
    printf("Student deleted successfully");
  }
  else
  {
    printf("Student not found");
  }
}

void start_ui(void)
{
  int option;
  do
  {
    display_menu();
    scanf("%d", &option);
    switch (option)
    {
    case 1:
    {
      input_student();
      break;
    }
    case 2:
    {
      search_student_ui();
      break;
    }
    case 3:
    {
      delete_student_ui();
      break;
    }
    case 4:
    {
      display_all_students();
      break;
    }
    case 0:
      printf("Exiting...");
      break;

    default:
      printf("Invalid option"); break;
    }
  } while (option != 0);
}
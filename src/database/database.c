#include "../../include/database.h"
#include <stdio.h>

void init_database(void)
{
  FILE *file = fopen(DATABASE_FILE, "a");

  if (file != NULL)
  {
    fclose(file);
  }
}

bool_t create_student(Student *student)
{
  Student temp;
  printf("searching...\n");
  if (search_student(student->id, &temp))
  {
    return FALSE;
  }

  printf("opining file...\n");
  FILE *file = fopen(DATABASE_FILE, "a");

  if (file == NULL)
  {
    printf("file open failed");
    return FALSE;
  }

  printf("writing into file");
  fprintf(file,
          "%d,%s,%d,%.2f\n",
          student->id,
          student->name,
          student->age,
          student->marks);

  fclose(file);

  return TRUE;
}

bool_t search_student(int id, Student *student)
{
  FILE *file = fopen(DATABASE_FILE, "r");

  if (file == NULL)
  {
    return FALSE;
  }

  while (fscanf(file,
                "%d,%49[^,],%d,%f",
                &student->id,
                student->name,
                &student->age,
                &student->marks) == 4)
  {
    if (student->id == id)
    {
      fclose(file);
      return TRUE;
    }
  }
  fclose(file);
  return FALSE;
}

bool_t delete_student(int id)
{
  FILE *file = fopen(DATABASE_FILE, "r");
  FILE *temp_file = fopen("data/temp.txt", "w");

  Student student;
  bool_t found = FALSE;

  if (file == NULL || temp_file == NULL)
  {
    return FALSE;
  }

  while (fscanf(file,
                "%d,%49[^,],%d,%f",
                &student.id,
                student.name,
                &student.age,
                &student.marks) == 4)
  {
    if (student.id == id)
    {
      found = TRUE;
      continue;
    }

    fprintf(temp_file,
            "%d,%s,%d,%.2f\n",
            student.id,
            student.name,
            student.age,
            student.marks);
  }

  fclose(file);
  fclose(temp_file);

  remove(DATABASE_FILE);
  rename("data/temp.txt", DATABASE_FILE);

  return found;
}

bool_t display_all_students(void)
{
  FILE *file = fopen(DATABASE_FILE, "r");
  Student student;
  if (file == NULL)
  {
    printf("Students not found");
    return FALSE;
  }

  printf("\n=============================================\n");
  printf("ID\tName\t\tAge\tMarks\n");
  printf("=============================================\n");

  while (fscanf(file,
                "%d,%49[^,],%d,%f",
                &student.id,
                student.name,
                &student.age,
                &student.marks) == 4)
  {
    printf("%d\t%s\t%d\t%f\n",
           student.id,
           student.name,
           student.age,
           student.marks);
  }

  fclose(file);
  return TRUE;
}
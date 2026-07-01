#include "../../include/ui.h"
#include "../../include/database.h"


void display_menu(void) {
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

Student input_student(void) {
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

 return student;
}


Student search_student(void) {
 Student student;
 printf("=========== Search Student ==========\n");

 printf("Enter Id : ");
 scanf("%d", &student.id);
}

Student delete_student(void){
  int id;
  printf("=========== Delete Student ==========\n");

 printf("Enter Id : ");
 scanf("%d",&id);
}
void start_ui(void) {
 int option;
 do {
  display_menu();
  scanf("%d", &option);
  switch(option) {
   case 1:
   {
    Student student = input_student();
    if(create_student(&student)) {
     printf("Student created successfully!");
    }else {
     printf("Student id already exists");
    }
    break;
   }
   case 2: {
    Student student = search_student();
    if(search_student(&student)) {
     printf("Student found", student -> id);
    }else {
     printf("Student not found");
    }
    break;
   }
   case 3:{
    int id = delete_student();
    if(delete_student(&id)){
     printf("Student deleted successfully");
     
    }else{
     printf("Student not found");
    }
    break;
   }
   
   case 0:
   printf("Exiting...");
   break;

   default:
   printf("Invalid option")
   break;
  }
 }while(option != 0);
}
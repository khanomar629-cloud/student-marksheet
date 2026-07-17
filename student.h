#define SUBJECTS 5
#define MAX_MARKS 100
#include <stdbool.h>


struct Student
{
    int rollno;
    char name[50];
    int marks[5];
    int total;
    float percentage;
    char grade[3];
    bool status;
};

void addStudent();
void viewStudents();
void searchStudent();
void updateStudent();
void deleteStudent();
void resultcard();
void classtotal();


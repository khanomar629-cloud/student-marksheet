#include <stdio.h>
#include "student.h"

int main()
{
    int choice;

    while (1)
    {
        printf("Student Marksheet Management System :\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Result Card\n");
        printf("7. Class Total\n");
        printf("8. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:  addStudent(); break;

        case 2: viewStudents(); break;

        case 3: searchStudent();break;

        case 4: updateStudent();break;

        case 5:deleteStudent(); break;

        case 6:  resultcard(); break;

        case 7: classtotal(); break;

        case 8: printf("Exit\n");
         return 0;

        default:
            printf("Invalid Choice\n");
        }
    }

    return 0;
}
#include <stdio.h>
#include <string.h>
#include "student.h"

#include <stdio.h>
#include <string.h>
#include "student.h"


void addStudent()
{
    struct Student st;

    FILE *fp = fopen("students.txt", "a");


    printf("Enter Roll Number: ");
    scanf("%d", &st.rollno);

    printf("Enter Name: ");
    scanf("%s", st.name);

    st.total = 0;

    printf("Enter Marks of 5 Subjects:\n");

    for (int i = 0; i < 5; i++)
    {
        printf("Subject %d: ", i + 1);
        scanf("%d", &st.marks[i]);

        st.total = st.total + st.marks[i];
    }


    st.percentage = st.total / 5;


    if (st.percentage >= 80)
        strcpy(st.grade, "A+");
    else if (st.percentage >= 70)
        strcpy(st.grade, "A");
    else if (st.percentage >= 60)
        strcpy(st.grade, "B");
    else if (st.percentage >= 50)
        strcpy(st.grade, "C");
    else if (st.percentage >= 40)
        strcpy(st.grade, "D");
    else
        strcpy(st.grade, "F");


    if (st.percentage >= 40)
        strcpy(st.status, "Pass");
    else
        strcpy(st.status, "Fail");


    fprintf(fp, "%d %s %d %d %d %d %d %d %.2f %s %s\n",
            st.rollno,
            st.name,
            st.marks[0],
            st.marks[1],
            st.marks[2],
            st.marks[3],
            st.marks[4],
            st.total,
            st.percentage,
            st.grade,
            st.status);


    fclose(fp);

    printf("\nStudent Added\n");
}




void viewStudents()
{
    struct Student st;

    FILE *fp = fopen("students.txt", "r");

    printf("\nStudent Records :\n");


    while (fscanf(fp, "%d %s %d %d %d %d %d %d %f %s %s",
                  &st.rollno,
                  st.name,
                  &st.marks[0],
                  &st.marks[1],
                  &st.marks[2],
                  &st.marks[3],
                  &st.marks[4],
                  &st.total,
                  &st.percentage,
                  st.grade,
                  st.status) != EOF)
    {

        printf("\nRoll No : %d\n", st.rollno);
        printf("Name : %s\n", st.name);

        printf("Marks : %d %d %d %d %d\n",
               st.marks[0],
               st.marks[1],
               st.marks[2],
               st.marks[3],
               st.marks[4]);

        printf("Total : %d\n", st.total);
        printf("Percentage : %.2f\n", st.percentage);
        printf("Grade : %s\n", st.grade);
        printf("Status : %s\n", st.status);
    }


    fclose(fp);
}





void searchStudent()
{
    struct Student st;

    int roll;
    int found = 0;


    FILE *fp = fopen("students.txt", "r");

    printf("Enter Roll Number: ");
    scanf("%d", &roll);



    while (fscanf(fp, "%d %s %d %d %d %d %d %d %f %s %s",
                  &st.rollno,
                  st.name,
                  &st.marks[0],
                  &st.marks[1],
                  &st.marks[2],
                  &st.marks[3],
                  &st.marks[4],
                  &st.total,
                  &st.percentage,
                  st.grade,
                  st.status) != EOF)
    {

        if (st.rollno == roll)
        {
            found = 1;


            printf("\nStudent Found\n");

            printf("Roll No : %d\n", st.rollno);
            printf("Name : %s\n", st.name);
            printf("Percentage : %.2f\n", st.percentage);
            printf("Grade : %s\n", st.grade);
            printf("Status : %s\n", st.status);

            break;
        }
    }


    if (found == 0)
        printf("Student Not Found\n");


    fclose(fp);
}





void updateStudent()
{
    struct Student st;

    int roll;
    int found = 0;


    FILE *fp = fopen("students.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    printf("Enter Roll Number to Update: ");
    scanf("%d", &roll);



    while (fscanf(fp, "%d %s %d %d %d %d %d %d %f %s %s",
                  &st.rollno,
                  st.name,
                  &st.marks[0],
                  &st.marks[1],
                  &st.marks[2],
                  &st.marks[3],
                  &st.marks[4],
                  &st.total,
                  &st.percentage,
                  st.grade,
                  st.status) != EOF)
    {


        if (st.rollno == roll)
        {
            found = 1;


            printf("Enter New Marks:\n");

            st.total = 0;


            for (int i = 0; i < 5; i++)
            {
                printf("Subject %d: ", i + 1);

                scanf("%d", &st.marks[i]);

                st.total += st.marks[i];
            }


            st.percentage = st.total / 5;


            if (st.percentage >= 80)
                strcpy(st.grade, "A+");
            else if (st.percentage >= 70)
                strcpy(st.grade, "A");
            else if (st.percentage >= 60)
                strcpy(st.grade, "B");
            else if (st.percentage >= 50)
                strcpy(st.grade, "C");
            else if (st.percentage >= 40)
                strcpy(st.grade, "D");
            else
                strcpy(st.grade, "F");


            if (st.percentage >= 40)
                strcpy(st.status, "Pass");
            else
                strcpy(st.status, "Fail");
        }



        fprintf(temp, "%d %s %d %d %d %d %d %d %.2f %s %s\n",
                st.rollno,
                st.name,
                st.marks[0],
                st.marks[1],
                st.marks[2],
                st.marks[3],
                st.marks[4],
                st.total,
                st.percentage,
                st.grade,
                st.status);
    }


    fclose(fp);
    fclose(temp);


    remove("students.txt");
    rename("temp.txt", "students.txt");


    if (found)
        printf("Student Updated Successfully\n");
    else
        printf("Student Not Found\n");
}





void deleteStudent()
{
    struct Student st;

    int roll;
    int found = 0;


    FILE *fp = fopen("students.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    printf("Enter Roll Number to Delete: ");
    scanf("%d", &roll);



    while (fscanf(fp, "%d %s %d %d %d %d %d %d %f %s %s",
                  &st.rollno,
                  st.name,
                  &st.marks[0],
                  &st.marks[1],
                  &st.marks[2],
                  &st.marks[3],
                  &st.marks[4],
                  &st.total,
                  &st.percentage,
                  st.grade,
                  st.status) != EOF)
    {


        if (st.rollno == roll)
        {
            found = 1;
            continue;
        }


        fprintf(temp, "%d %s %d %d %d %d %d %d %.2f %s %s\n",
                st.rollno,
                st.name,
                st.marks[0],
                st.marks[1],
                st.marks[2],
                st.marks[3],
                st.marks[4],
                st.total,
                st.percentage,
                st.grade,
                st.status);
    }


    fclose(fp);
    fclose(temp);


    remove("students.txt");
    rename("temp.txt", "students.txt");


    if(found)
        printf("Student Deleted Successfully\n");
    else
        printf("Student Not Found\n");
}





void resultcard()
{
    struct Student st;

    int roll;
    int found = 0;


    FILE *fp = fopen("students.txt", "r");

    printf("Enter Roll Number: ");
    scanf("%d", &roll);



    while(fscanf(fp, "%d %s %d %d %d %d %d %d %f %s %s",
                 &st.rollno,
                 st.name,
                 &st.marks[0],
                 &st.marks[1],
                 &st.marks[2],
                 &st.marks[3],
                 &st.marks[4],
                 &st.total,
                 &st.percentage,
                 st.grade,
                 st.status) != EOF)
    {


        if(st.rollno == roll)
        {
            found = 1;


            printf("\n Result Card :\n");

            printf("Roll No : %d\n", st.rollno);
            printf("Name : %s\n", st.name);

            printf("\nMarks:\n");

            for(int i = 0; i < 5; i++)
            {
                printf("Subject %d : %d\n", i + 1,st.marks[i]);
            }


            printf("\nTotal : %d\n", st.total);
            printf("Percentage : %.2f\n", st.percentage);
            printf("Grade : %s\n", st.grade);
            printf("Status : %s\n", st.status);


            break;
        }
    }



    


    if(found == 0)
        printf("Student Not Found\n");

        


    fclose(fp);

    
}
void classtotal()
{
    struct Student st;

    FILE *fp = fopen("students.txt", "r");

    int count = 0;
    int pass = 0, fail = 0;
    float totalPercentage = 0;

    int highestTotal = -1;
    char topper[50];

    int highestMarks[5] = {0, 0, 0, 0, 0};

    while (fscanf(fp, "%d %s %d %d %d %d %d %d %f %s %s",
                  &st.rollno,
                  st.name,
                  &st.marks[0],
                  &st.marks[1],
                  &st.marks[2],
                  &st.marks[3],
                  &st.marks[4],
                  &st.total,
                  &st.percentage,
                  st.grade,
                  st.status) != EOF)
    {
        count++;
        totalPercentage += st.percentage;

        if (strcmp(st.status, "Pass") == 0)
            pass++;
        else
            fail++;

        if (st.total > highestTotal)
        {
            highestTotal = st.total;
            strcpy(topper, st.name);
        }

        for (int i = 0; i < 5; i++)
        {
            if (st.marks[i] > highestMarks[i])
                highestMarks[i] = st.marks[i];
        }
    }

    fclose(fp);

    if (count == 0)
    {
        printf("No Student Records\n");
        return;
    }

    printf("\nClass Total :\n");
    printf("Class Topper : %s (%d Marks)\n", topper, highestTotal);

    printf("\nSubject-wise Highest Marks\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Subject %d : %d\n", i + 1, highestMarks[i]);
    }

    printf("\nClass Average : %.2f%%\n", totalPercentage / count);
    printf("Passed Students : %d\n", pass);
    printf("Failed Students : %d\n", fail);
}
void addStudent()
{
    struct Student st;

    FILE *fp = fopen("students.txt", "a");


    printf("Enter Roll Number: ");
    scanf("%d", &st.rollno);

    printf("Enter Name: ");
    scanf("%s", st.name);

    st.total = 0;

    printf("Enter Marks of 5 Subjects:\n");

    for (int i = 0; i < 5; i++)
    {
        printf("Subject %d: ", i + 1);
        scanf("%d", &st.marks[i]);

        st.total = st.total + st.marks[i];
    }


    st.percentage = st.total / 5;


    if (st.percentage >= 80)
        strcpy(st.grade, "A+");
    else if (st.percentage >= 70)
        strcpy(st.grade, "A");
    else if (st.percentage >= 60)
        strcpy(st.grade, "B");
    else if (st.percentage >= 50)
        strcpy(st.grade, "C");
    else if (st.percentage >= 40)
        strcpy(st.grade, "D");
    else
        strcpy(st.grade, "F");


    if (st.percentage >= 40)
        strcpy(st.status, "Pass");
    else
        strcpy(st.status, "Fail");


    fprintf(fp, "%d %s %d %d %d %d %d %d %.2f %s %s\n",
            st.rollno,
            st.name,
            st.marks[0],
            st.marks[1],
            st.marks[2],
            st.marks[3],
            st.marks[4],
            st.total,
            st.percentage,
            st.grade,
            st.status);


    fclose(fp);

    printf("\nStudent Added\n");
}




void viewStudents()
{
    struct Student st;

    FILE *fp = fopen("students.txt", "r");

    printf("\nStudent Records :\n");


    while (fscanf(fp, "%d %s %d %d %d %d %d %d %f %s %s",
                  &st.rollno,
                  st.name,
                  &st.marks[0],
                  &st.marks[1],
                  &st.marks[2],
                  &st.marks[3],
                  &st.marks[4],
                  &st.total,
                  &st.percentage,
                  st.grade,
                  st.status) != EOF)
    {

        printf("\nRoll No : %d\n", st.rollno);
        printf("Name : %s\n", st.name);

        printf("Marks : %d %d %d %d %d\n",
               st.marks[0],
               st.marks[1],
               st.marks[2],
               st.marks[3],
               st.marks[4]);

        printf("Total : %d\n", st.total);
        printf("Percentage : %.2f\n", st.percentage);
        printf("Grade : %s\n", st.grade);
        printf("Status : %s\n", st.status);
    }


    fclose(fp);
}





void searchStudent()
{
    struct Student st;

    int roll;
    int found = 0;


    FILE *fp = fopen("students.txt", "r");

    printf("Enter Roll Number: ");
    scanf("%d", &roll);



    while (fscanf(fp, "%d %s %d %d %d %d %d %d %f %s %s",
                  &st.rollno,
                  st.name,
                  &st.marks[0],
                  &st.marks[1],
                  &st.marks[2],
                  &st.marks[3],
                  &st.marks[4],
                  &st.total,
                  &st.percentage,
                  st.grade,
                  st.status) != EOF)
    {

        if (st.rollno == roll)
        {
            found = 1;


            printf("\nStudent Found\n");

            printf("Roll No : %d\n", st.rollno);
            printf("Name : %s\n", st.name);
            printf("Percentage : %.2f\n", st.percentage);
            printf("Grade : %s\n", st.grade);
            printf("Status : %s\n", st.status);

            break;
        }
    }


    if (found == 0)
        printf("Student Not Found\n");


    fclose(fp);
}





void updateStudent()
{
    struct Student st;

    int roll;
    int found = 0;


    FILE *fp = fopen("students.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    printf("Enter Roll Number to Update: ");
    scanf("%d", &roll);



    while (fscanf(fp, "%d %s %d %d %d %d %d %d %f %s %s",
                  &st.rollno,
                  st.name,
                  &st.marks[0],
                  &st.marks[1],
                  &st.marks[2],
                  &st.marks[3],
                  &st.marks[4],
                  &st.total,
                  &st.percentage,
                  st.grade,
                  st.status) != EOF)
    {


        if (st.rollno == roll)
        {
            found = 1;


            printf("Enter New Marks:\n");

            st.total = 0;


            for (int i = 0; i < 5; i++)
            {
                printf("Subject %d: ", i + 1);

                scanf("%d", &st.marks[i]);

                st.total += st.marks[i];
            }


            st.percentage = st.total / 5;


            if (st.percentage >= 80)
                strcpy(st.grade, "A+");
            else if (st.percentage >= 70)
                strcpy(st.grade, "A");
            else if (st.percentage >= 60)
                strcpy(st.grade, "B");
            else if (st.percentage >= 50)
                strcpy(st.grade, "C");
            else if (st.percentage >= 40)
                strcpy(st.grade, "D");
            else
                strcpy(st.grade, "F");


            if (st.percentage >= 40)
                strcpy(st.status, "Pass");
            else
                strcpy(st.status, "Fail");
        }



        fprintf(temp, "%d %s %d %d %d %d %d %d %.2f %s %s\n",
                st.rollno,
                st.name,
                st.marks[0],
                st.marks[1],
                st.marks[2],
                st.marks[3],
                st.marks[4],
                st.total,
                st.percentage,
                st.grade,
                st.status);
    }


    fclose(fp);
    fclose(temp);


    remove("students.txt");
    rename("temp.txt", "students.txt");


    if (found)
        printf("Student Updated Successfully\n");
    else
        printf("Student Not Found\n");
}





void deleteStudent()
{
    struct Student st;

    int roll;
    int found = 0;


    FILE *fp = fopen("students.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    printf("Enter Roll Number to Delete: ");
    scanf("%d", &roll);



    while (fscanf(fp, "%d %s %d %d %d %d %d %d %f %s %s",
                  &st.rollno,
                  st.name,
                  &st.marks[0],
                  &st.marks[1],
                  &st.marks[2],
                  &st.marks[3],
                  &st.marks[4],
                  &st.total,
                  &st.percentage,
                  st.grade,
                  st.status) != EOF)
    {


        if (st.rollno == roll)
        {
            found = 1;
            continue;
        }


        fprintf(temp, "%d %s %d %d %d %d %d %d %.2f %s %s\n",
                st.rollno,
                st.name,
                st.marks[0],
                st.marks[1],
                st.marks[2],
                st.marks[3],
                st.marks[4],
                st.total,
                st.percentage,
                st.grade,
                st.status);
    }


    fclose(fp);
    fclose(temp);


    remove("students.txt");
    rename("temp.txt", "students.txt");


    if(found)
        printf("Student Deleted Successfully\n");
    else
        printf("Student Not Found\n");
}





void resultcard()
{
    struct Student st;

    int roll;
    int found = 0;


    FILE *fp = fopen("students.txt", "r");

    printf("Enter Roll Number: ");
    scanf("%d", &roll);



    while(fscanf(fp, "%d %s %d %d %d %d %d %d %f %s %s",
                 &st.rollno,
                 st.name,
                 &st.marks[0],
                 &st.marks[1],
                 &st.marks[2],
                 &st.marks[3],
                 &st.marks[4],
                 &st.total,
                 &st.percentage,
                 st.grade,
                 st.status) != EOF)
    {


        if(st.rollno == roll)
        {
            found = 1;


            printf("\n Result Card :\n");

            printf("Roll No : %d\n", st.rollno);
            printf("Name : %s\n", st.name);

            printf("\nMarks:\n");

            for(int i = 0; i < 5; i++)
            {
                printf("Subject %d : %d\n", i + 1,st.marks[i]);
            }


            printf("\nTotal : %d\n", st.total);
            printf("Percentage : %.2f\n", st.percentage);
            printf("Grade : %s\n", st.grade);
            printf("Status : %s\n", st.status);


            break;
        }
    }



    


    if(found == 0)
        printf("Student Not Found\n");

        


    fclose(fp);

    
}
void classtotal()
{
    struct Student st;

    FILE *fp = fopen("students.txt", "r");

    int count = 0;
    int pass = 0, fail = 0;
    float totalPercentage = 0;

    int highestTotal = -1;
    char topper[50];

    int highestMarks[5] = {0, 0, 0, 0, 0};

    while (fscanf(fp, "%d %s %d %d %d %d %d %d %f %s %s",
                  &st.rollno,
                  st.name,
                  &st.marks[0],
                  &st.marks[1],
                  &st.marks[2],
                  &st.marks[3],
                  &st.marks[4],
                  &st.total,
                  &st.percentage,
                  st.grade,
                  st.status) != EOF)
    {
        count++;
        totalPercentage += st.percentage;

        if (strcmp(st.status, "Pass") == 0)
            pass++;
        else
            fail++;

        if (st.total > highestTotal)
        {
            highestTotal = st.total;
            strcpy(topper, st.name);
        }

        for (int i = 0; i < 5; i++)
        {
            if (st.marks[i] > highestMarks[i])
                highestMarks[i] = st.marks[i];
        }
    }

    fclose(fp);

    if (count == 0)
    {
        printf("No Student Records\n");
        return;
    }

    printf("\nClass Total :\n");
    printf("Class Topper : %s (%d Marks)\n", topper, highestTotal);

    printf("\nSubject-wise Highest Marks\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Subject %d : %d\n", i + 1, highestMarks[i]);
    }

    printf("\nClass Average : %.2f%%\n", totalPercentage / count);
    printf("Passed Students : %d\n", pass);
    printf("Failed Students : %d\n", fail);
}
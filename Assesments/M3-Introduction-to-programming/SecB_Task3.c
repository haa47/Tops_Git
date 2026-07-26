#include <stdio.h>

struct Student
{
    char name[50];
    int rollno;
    float marks;
    char grade;
};

void assignGrade(struct Student *s)
{
    if(s->marks >= 90)
        s->grade = 'A';
    else if(s->marks >= 75)
        s->grade = 'B';
    else if(s->marks >= 60)
        s->grade = 'C';
    else if(s->marks >= 45)
        s->grade = 'D';
    else
        s->grade = 'F';
}

void printTopper(struct Student s[], int n)
{
    int i;
    int topper = 0;

    for(i = 1; i < n; i++)
    {
        if(s[i].marks > s[topper].marks)
            topper = i;
    }

    printf("\nTop Performer\n");
    printf("--------------\n");
    printf("Name : %s\n", s[topper].name);
    printf("Marks: %.2f\n", s[topper].marks);
}

int main()
{
    struct Student s[3];
    int i;

    for(i = 0; i < 3; i++)
    {
        printf("\nStudent %d\n", i + 1);

        printf("Enter Name: ");
        scanf(" %[^\n]", s[i].name);

        printf("Enter Roll Number: ");
        scanf("%d", &s[i].rollno);

        printf("Enter Marks: ");
        scanf("%f", &s[i].marks);

        assignGrade(&s[i]);
    }

    printf("\n----------------------------------------------------------\n");
    printf("%-20s %-10s %-10s %-10s\n","Name","Roll","Marks","Grade");
    printf("----------------------------------------------------------\n");

    for(i = 0; i < 3; i++)
    {
        printf("%-20s %-10d %-10.2f %-10c\n",
               s[i].name,
               s[i].rollno,
               s[i].marks,
               s[i].grade);
    }

    printTopper(s,3);

    return 0;
}
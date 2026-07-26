#include <stdio.h>

#define SUBJECTS 3
#define DAYS 7

struct StudyLog
{
    char subject[40];
    float hours[DAYS];
};

void initializeSubjects(struct StudyLog logs[])
{
    int i;

    char names[SUBJECTS][40] = {
        "Programming",
        "Mathematics",
        "Database"
    };

    for(i = 0; i < SUBJECTS; i++)
    {
        int j;

        sprintf(logs[i].subject, "%s", names[i]);

        for(j = 0; j < DAYS; j++)
        {
            logs[i].hours[j] = 0;
        }
    }
}

void logStudyHours(struct StudyLog logs[])
{
    int day;
    int i;

    printf("\nEnter Day Number (1-7): ");
    scanf("%d", &day);

    if(day < 1 || day > 7)
    {
        printf("Invalid day.\n");
        return;
    }

    for(i = 0; i < SUBJECTS; i++)
    {
        float hrs;

        do
        {
            printf("Enter study hours for %s: ", logs[i].subject);
            scanf("%f", &hrs);

            if(hrs < 0 || hrs > 24)
                printf("Invalid input. Enter between 0 and 24.\n");

        } while(hrs < 0 || hrs > 24);

        logs[i].hours[day - 1] = hrs;
    }

    printf("Study hours recorded successfully.\n");
}

void displayWeeklyReport(struct StudyLog logs[])
{
    int i, j;

    printf("\n========== WEEKLY REPORT ==========\n");

    for(i = 0; i < SUBJECTS; i++)
    {
        float total = 0;
        float average;

        for(j = 0; j < DAYS; j++)
            total += logs[i].hours[j];

        average = total / DAYS;

        printf("\nSubject : %s\n", logs[i].subject);
        printf("Weekly Total : %.2f hours\n", total);
        printf("Daily Average: %.2f hours\n", average);

        printf("Progress Chart\n");

        for(j = 0; j < DAYS; j++)
        {
            int k;

            printf("Day %d: ", j + 1);

            for(k = 0; k < (int)logs[i].hours[j]; k++)
                printf("*");

            printf("\n");
        }
    }
}

void saveToFile(struct StudyLog logs[])
{
    FILE *fp;
    int i, j;

    fp = fopen("productivity_log.txt", "w");

    if(fp == NULL)
    {
        printf("Unable to create file.\n");
        return;
    }

    for(i = 0; i < SUBJECTS; i++)
    {
        fprintf(fp, "%s", logs[i].subject);

        for(j = 0; j < DAYS; j++)
        {
            fprintf(fp, ",%.2f", logs[i].hours[j]);
        }

        fprintf(fp, "\n");
    }

    fclose(fp);

    printf("Data saved successfully to productivity_log.txt\n");
}

int main()
{
    struct StudyLog logs[SUBJECTS];
    int choice;

    initializeSubjects(logs);

    do
    {
        printf("\n===== STUDENT PRODUCTIVITY TRACKER =====\n");
        printf("1. Log Today's Study Hours\n");
        printf("2. View Weekly Report\n");
        printf("3. Save & Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                logStudyHours(logs);
                break;

            case 2:
                displayWeeklyReport(logs);
                break;

            case 3:
                saveToFile(logs);
                printf("Thank you!\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while(choice != 3);

    return 0;
}
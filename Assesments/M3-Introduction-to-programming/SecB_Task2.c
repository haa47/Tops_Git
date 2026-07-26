#include <stdio.h>

int main()
{
    float hours[7];
    float total = 0, average;
    float highest;
    int highestDay = 1;
    int i, j;

    for(i = 0; i < 7; i++)
    {
        do
        {
            printf("Enter study hours for Day %d (0-24): ", i + 1);
            scanf("%f", &hours[i]);

            if(hours[i] < 0 || hours[i] > 24)
                printf("Invalid input! Please enter a value between 0 and 24.\n");

        } while(hours[i] < 0 || hours[i] > 24);

        total += hours[i];
    }

    highest = hours[0];

    for(i = 1; i < 7; i++)
    {
        if(hours[i] > highest)
        {
            highest = hours[i];
            highestDay = i + 1;
        }
    }

    average = total / 7;

    printf("\nWeekly Total: %.2f hours\n", total);
    printf("Daily Average: %.2f hours\n", average);
    printf("Highest Study Hours: Day %d (%.2f hours)\n\n", highestDay, highest);

    printf("Study Hour Bar Chart:\n");

    for(i = 0; i < 7; i++)
    {
        printf("Day %d: ", i + 1);

        for(j = 0; j < (int)hours[i]; j++)
            printf("*");

        printf("\n");
    }

    return 0;
}
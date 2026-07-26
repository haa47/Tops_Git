#include <stdio.h>

struct Expense
{
    char category[30];
    float amount;
};

int main()
{
    struct Expense expense[10];
    int count = 0;
    int choice;
    int i;
    float total;
    FILE *fp;

    do
    {
        printf("\n===== Personal Expense Logger =====\n");
        printf("1. Add Expense\n");
        printf("2. View All Expenses\n");
        printf("3. Save & Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:

                if(count >= 10)
                {
                    printf("Expense list is full.\n");
                    break;
                }

                printf("Enter Category: ");
                scanf(" %[^\n]", expense[count].category);

                printf("Enter Amount: ");
                scanf("%f", &expense[count].amount);

                count++;
                printf("Expense Added Successfully.\n");
                break;

            case 2:

                if(count == 0)
                {
                    printf("No expenses recorded.\n");
                    break;
                }

                total = 0;

                printf("\n-----------------------------------------\n");
                printf("%-20s %-10s\n","Category","Amount");
                printf("-----------------------------------------\n");

                for(i = 0; i < count; i++)
                {
                    printf("%-20s %.2f\n",
                           expense[i].category,
                           expense[i].amount);

                    total += expense[i].amount;
                }

                printf("-----------------------------------------\n");
                printf("Running Total = %.2f\n", total);
                break;

            case 3:

                fp = fopen("expenses.txt","w");

                if(fp == NULL)
                {
                    printf("Unable to create file.\n");
                    return 1;
                }

                for(i = 0; i < count; i++)
                {
                    fprintf(fp,"%s,%.2f\n",
                            expense[i].category,
                            expense[i].amount);
                }

                fclose(fp);

                printf("Expenses saved to expenses.txt\n");
                printf("Thank You!\n");
                break;

            default:
                printf("Invalid Choice.\n");
        }

    }while(choice != 3);

    return 0;
}
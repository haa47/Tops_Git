#include <stdio.h>

int main()
{
    int arr[10];
    int i, j;
    int min, max;
    int sum = 0;
    float mean;

    printf("Enter 10 integers:\n");

    for(i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }

    min = arr[0];
    max = arr[0];

    for(i = 0; i < 10; i++)
    {
        if(arr[i] < min)
            min = arr[i];

        if(arr[i] > max)
            max = arr[i];

        sum += arr[i];
    }

    mean = sum / 10.0;

    for(i = 0; i < 9; i++)
    {
        for(j = i + 1; j < 10; j++)
        {
            if(arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("\nMinimum = %d\n", min);
    printf("Maximum = %d\n", max);
    printf("Mean = %.2f\n", mean);

    printf("\nSorted Array:\n");

    for(i = 0; i < 10; i++)
        printf("%d ", arr[i]);

    printf("\n");

    if((mean - min) < (max - mean))
        printf("Mean is closer to Minimum.\n");
    else if((mean - min) > (max - mean))
        printf("Mean is closer to Maximum.\n");
    else
        printf("Mean is exactly midway.\n");

    return 0;
}
#include <stdio.h>
#include <stdlib.h> // for generator random numbers
#define MaxLength 100 // maximum length of array

void getRandomArray(int* array , int length)
{
    for(int i = 0; i < length; i++)
        array[i] = rand()%100; // generate from 0...99 use RAND_MAX
    printf("Array filled.\n");
}

void printArray(int* array , int length)
{
    for(int i = 0; i < length; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int getAmountArray(int* array , int length)
{
    int amount = 0;
    for(int i = 0; i < length; i++)
        amount += array[i];
    return amount;
}

float getAverageArray(int* array , int length)
{
    int amount = getAmountArray(array, length);
    return (float) amount / length;
}

int getMostDifferentFromAverage(int* array , int length)
{
    float diff=0;
    float average = getAverageArray(array, length);
    int n=0;
    for(int i = 0; i < length; i++)
        if (diff < abs(array[i] - average))
        {
            diff = abs(array[i] - average);
            n = i;
        }
    return n;
}

int main()
{
    int a[MaxLength];
    int choice=-1;
    while (choice != 0)
    {
        printf("1. Fill array randomly\n");
        printf("2. Print array\n");
        printf("3. Get amount of array elements\n");
        printf("4. Get average\n");
        printf("5. Get the number of element which the most different from the average\n");
        printf("0. Exit\n: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: getRandomArray(a, MaxLength);
                break;
            case 2: printArray(a, MaxLength);
                break;
            case 3: printf("The amount is %d.\n", getAmountArray(a, MaxLength));
                break;
            case 4: printf("The average is %.2f.\n", getAverageArray(a, MaxLength));
                break;
            case 5: printf("The element a[ %d ] = %d is the most differen from average.\n",
                           getMostDifferentFromAverage(a, MaxLength),
                           a[getMostDifferentFromAverage(a, MaxLength)]);
                break;
            case 0: printf("The end.\n");
                break;
            default: printf("Wrong number, try again\n");
        }
    }
    return 0;
}

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

int getMaxFromArray(int* array , int length)
{
    int max = array[0];
    for(int i = 1; i < length; i++)
        if (max < array[i]) max = array[i];
    return max;
}

int main()
{
    int a[MaxLength];
    int choice=-1;
    while (choice != 0)
    {
        printf("1. Fill array randomly\n");
        printf("2. Print array\n");
        printf("3. Find maximum element\n");
        printf("0. Exit\n: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: getRandomArray(a, MaxLength);
                break;
            case 2: printArray(a, MaxLength);
                break;
            case 3: printf("The max is %d.\n", getMaxFromArray(a, MaxLength));
                break;
            case 0: printf("The end.\n");
                break;
            default: printf("Wrong number, try again\n");
        }
    }
    return 0;
}

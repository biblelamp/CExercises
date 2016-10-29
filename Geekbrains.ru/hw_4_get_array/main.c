#include <stdio.h>
#include <stdlib.h> // for generator random numbers
#define MaxLength 100 // maximum length of array
#define FileName "hw_4_1.txt" // file

void printArray(int* array , int length)
{
    for(int i = 0; i < length; i++)
        printf("%d ", array[i]);
    printf("\n");
}

void getArrayFromKeyboard(int* array , int length)
{
    for(int i = 0; i < length; i++)
    {
        printf("a[ %d ] = ", i);
        scanf("%d", &array[i]);
    }
}

void getRandomArray(int* array , int length)
{
    for(int i = 0; i < length; i++)
        array[i] = rand()%100; // generate from 0...99 use RAND_MAX
}

void saveArrayToFile(int* array , int length)
{
    FILE *file;
    file = fopen(FileName, "w");
    if (file == NULL)
    {
        puts("Can't write file\n");
    }
    else
    {
        fprintf(file, "%d ", MaxLength);
        for(int i = 0; i < length; i++)
            fprintf(file, "%d ", array[i]);
        printf("File saved.\n");
        fclose(file);
    }
}

void getArrayFromFile(int* array)
{
    FILE *file;
    int length;
    file = fopen(FileName, "r");
    if (file == NULL)
    {
        puts("Can't read file\n");
    }
    else
    {
        fscanf(file, "%d ", &length);
        for(int i = 0; i < length; i++)
            fscanf(file, "%d ", &array[i]);
        fclose(file);
    }
}

int main()
{
    int a[MaxLength];
    int choice=-1;
    while (choice != 0)
    {
        printf("1. Get array from keyboard\n");
        printf("2. Fill array randomly\n");
        printf("3. Save array to file\n");
        printf("4. Get array from file\n");
        printf("0. Exit\n: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                getArrayFromKeyboard(a, MaxLength);
                printArray(a, MaxLength);
                break;
            case 2:
                getRandomArray(a, MaxLength);
                printArray(a, MaxLength);
                break;
            case 3:
               saveArrayToFile(a, MaxLength);
                break;
            case 4: getArrayFromFile(a);
                printArray(a, MaxLength);
                break;
            case 0: printf("The end.\n");
                break;
            default: printf("Wrong number, try again\n");
        }
    }
    return 0;
}

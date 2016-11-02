#include <stdio.h>
#include <stdlib.h> // for generator random numbers
#define MaxN 100 // maximum length of array

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void printArray(int N, int *a)
{
    for(int i = 0; i < N; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void getRandomArray(int N, int *a)
{
    for(int i = 0; i < N; i++)
        a[i] = rand()%200 - 100; // generate from -99...99 use RAND_MAX
    printf("Array filled.\n");
}

int bubbleSortArray(int N, int *a)
{
    int count = 0;
    for(int i = 0; i < N; i++) {
        int swapped = 0; // swap check flag
        for(int j = 0; j < N-i-1; j++)
        {
            count++;
            if (a[j] > a[j+1])
            {
                swap(&a[j], &a[j+1]);
                swapped = 1;
            }
        }
        if (!swapped) break; // if swap was not then sorting is completed
    }
    return count;
}

int selectionSortArray(int N, int *a)
{
    int count = 0;
    int jmin;
    for(int i = 0; i < N - 1; i++)
    {
        jmin = i;
        for(int j = i + 1; j < N; j++) {
            count++;
            if (a[j] < a[jmin])
            {
                jmin = j;
            }
            swap(&a[i], &a[jmin]);
        }
    }
    return count;
}

int main()
{
    int a[MaxN];
    int count;
    getRandomArray(MaxN, a);
    puts("Array before sort:");
    printArray(MaxN, a);
    count = selectionSortArray(MaxN, a);
    puts("Array after sort:");
    printArray(MaxN, a);
    printf("Number of comparisons is %d", count);
    return 0;
}

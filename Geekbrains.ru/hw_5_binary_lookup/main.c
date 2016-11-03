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
}

void bubbleSortArray(int N, int *a)
{
    for(int i = 0; i < N; i++) {
        int swapped = 0; // swap check flag
        for(int j = 0; j < N-i-1; j++)
            if (a[j] > a[j+1])
            {
                swap(&a[j], &a[j+1]);
                swapped = 1;
            }
        if (!swapped) break; // if swap was not then sorting is completed
    }
}

int binaryLookup(int X, int N, int *a)
{
    int begin = 0;
    int end = N;
    int mid;
    int i = -1;
    while (begin < end)
    {
        mid = (begin + end) / 2;
        if (X == a[mid])
        {
            i = mid;
            break;
        }
        else
        {
            if (X < a[mid]) end = mid;
            else begin = mid + 1;
        }
    }
    return i;
}

int main()
{
    int a[MaxN];
    int n,i;
    getRandomArray(MaxN, a);
    bubbleSortArray(MaxN, a);
    puts("Array after sort:");
    printArray(MaxN, a);
    do
    {
        printf("Enter number in range [-99..99]: ");
        scanf("%d", &n);
        i = binaryLookup(n, MaxN, a);
        if (abs(n) < 100)
        {
            if (i > -1) printf("a[ %d ] = %d\n", i, a[i]);
            else printf("The number isn't found.\n");
        }
    } while (abs(n) < 100);
    printf("The end.");
}

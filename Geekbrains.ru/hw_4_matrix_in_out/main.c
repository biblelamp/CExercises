#include <stdio.h>
#include <stdlib.h> // for generator random numbers
#define MaxX 3 // dimension of the array for X
#define MaxY 3 // dimension of the array for Y
#define FileName "hw_4_4.txt" // file

void get2DArrayFromConsole(int n, int m, int a[n][m])
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            printf("[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
}

void get2DRandomArray(int n, int m, int a[n][m])
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            a[i][j] = rand()%200 - 99; // generate from -99...99 use RAND_MAX
    printf("Array filled.\n");
}

void save2DArrayToFile(int n, int m, int a[n][m])
{
    FILE *file;
    file = fopen(FileName, "w");
    if (file == NULL)
    {
        puts("Can't write file.\n");
    }
    else
    {
        fprintf(file, "%d ", n);
        fprintf(file, "%d ", m);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                fprintf(file, "%d ", a[i][j]);
        fclose(file);
        printf("File saved to file.\n");
    }
}

void get2DArrayFromFile(int n, int m, int a[n][m])
{
    FILE *file;
    file = fopen(FileName, "r");
    if (file == NULL)
    {
        puts("Can't read file.\n");
    }
    else
    {
        fscanf(file, "%d ", &n);
        fscanf(file, "%d ", &m);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                fscanf(file, "%d ", &a[i][j]);
        fclose(file);
        printf("Array read from file.\n");
    }
}

void print2DArray(int n, int m, int a[n][m])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            printf("%d\t", a[i][j]);
        printf("\n");
    }
}

int main()
{
    int a[MaxX][MaxY];
    int choice=-1;
    while (choice != 0)
    {
        printf("1. Get array from console\n");
        printf("2. Fill array randomly\n");
        printf("3. Save array to file\n");
        printf("4. Get array from file\n");
        printf("5. Print array\n");
        printf("0. Exit\n: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: get2DArrayFromConsole(MaxX, MaxY, a);
                break;
            case 2: get2DRandomArray(MaxX, MaxY, a);
                break;
            case 3: save2DArrayToFile(MaxX, MaxY, a);
                break;
            case 4: get2DArrayFromFile(MaxX, MaxY, a);
                break;
            case 5: print2DArray(MaxX, MaxY, a);
                break;
            case 0: printf("The end.\n");
                break;
            default: printf("Wrong number, try again\n");
        }
    }
    return 0;
}

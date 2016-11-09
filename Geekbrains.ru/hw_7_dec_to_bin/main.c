#include <stdio.h>

long decToBin(int d)
{
    if (d == 0) return 0;
    else return decToBin(d / 2)*10 + d % 2;
}

int main()
{
    int d;
    puts("Enter a number:");
    scanf("%d", &d);
    printf("%ld", decToBin(d));
    return 0;
}

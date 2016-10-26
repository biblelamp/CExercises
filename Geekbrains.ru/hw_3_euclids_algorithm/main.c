#include <stdio.h>

int euclid(int a, int b)
{
    while (a != b)
    {
        if (a > b) a -= b;
        else b -=a;
    }
    return a;
}

int main()
{
    int a, b;
    printf("Enter the values for A and B:\n");
    scanf("%d %d", &a, &b);
    printf("Greatest common divisor is %d", euclid(a, b));
    return 0;
}

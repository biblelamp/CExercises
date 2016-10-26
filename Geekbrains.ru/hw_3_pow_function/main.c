#include <stdio.h>

int powi(int x, int n)
{
    int result=1;
    for (int i = 0; i < n; i++)
    {
        result *= x;
    }
    return result;
}

int main()
{
    int x,n;
    printf("Enter the values for X and N:\n");
    scanf("%d %d", &x, &n);
    printf("%d^%d is %d", x, n, powi(x, n));
    return 0;
}

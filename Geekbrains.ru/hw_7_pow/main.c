#include <stdio.h>

int pow(int x, int n) // pow classical form
{
    int result=1;
    for (int i = 0; i < n; i++) result *= x;
    return result;
}

int powRecursive(int x, int n) // pow with recursion
{
    if (n == 0) return 1;
    else return powRecursive(x, n - 1) * x;
}

int main()
{
    int x,n;
    printf("Enter the values for X and N:\n");
    scanf("%d %d", &x, &n);
    printf("%d^%d = %d (classical)\n", x, n, pow(x, n));
    printf("%d^%d = %d (recursion)\n", x, n, powRecursive(x, n));
    return 0;
}

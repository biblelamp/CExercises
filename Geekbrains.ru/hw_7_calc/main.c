#include <stdio.h>

/*
 * Calculator only has two action: adding 1 and multiplying 2.
 * How many programs to convert the number 3 in the number 20
 * Answer: 42
 */

int howManyPrograms(int a, int n)
{
    if (n == a) return 1;
    if ((n % 2 == 0) && (n > 1)) return howManyPrograms(a, n - 1)+howManyPrograms(a, n / 2);
    if (n > 1) return howManyPrograms(a, n - 1);
}

int main()
{
    int a,n;
    printf("Enter the values for A and N:\n");
    scanf("%d %d", &a, &n);
    printf("There are %d program(s) to convert %d to %d\n.", howManyPrograms(a, n), a, n);
    return 0;
}

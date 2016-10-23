#include <stdio.h>

int main()
{
    int n,k,i;
    printf("Enter N and K:\n");
    scanf("%d %d", &n, &k);

    i = 0;
    while (n>k) {
        n -= k;
        i++;
    }
    printf("Result of the division is %d and the residue is %d", i, n);
    return 0;
}

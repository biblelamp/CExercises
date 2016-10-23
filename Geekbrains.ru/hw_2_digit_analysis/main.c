#include <stdio.h>

int main()
{
    int n,d,f;
    printf("Enter N:\n");
    scanf("%d", &n);

    f = 0;
    do {
        d = n % 10;
        n /= 10;
        if (d % 2 > 0) f++;
    } while (n>0);
    printf("%s", (f == 0)? "False" : "True");
    return 0;
}

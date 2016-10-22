#include <stdio.h>

int main()
{
    int a,b;
    printf("Enter a and b:\n");
    scanf("%d %d", &a, &b);
    for (int i=a; i<=b; i++) printf("%d - %d - %d\n", i, i*i, i*i*i);
    return 0;
}

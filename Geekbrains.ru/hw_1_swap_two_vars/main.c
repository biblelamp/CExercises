#include <stdio.h>

int main()
{
    int a,b,c;
    printf("Enter a b:\n");
    scanf("%d %d", &a, &b);

    // classic way
    c = a;
    a = b;
    b = c;
    printf("%d %d\n", a, b);

    // racy way
    a = a + b;
    b = a - b;
    a = a - b;
    printf("%d %d\n", a, b);

    return 0;
}

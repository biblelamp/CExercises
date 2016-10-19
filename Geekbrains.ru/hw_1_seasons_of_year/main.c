#include <stdio.h>

int main()
{
    int m;
    printf("Enter number of month (1..12):\n");
    scanf("%d", &m);

    if (m == 12 || m < 3)
    {
        printf("It is Winter\n");
    }
    else if (m > 2 && m < 6)
    {
        printf("It is Spring\n");
    }
    else if (m > 5 && m < 9)
    {
        printf("It is Summer\n");
    }
    else
    {
        printf("It is Autumn (Fall)\n");
    }

    return 0;
}

#include <stdio.h>

int main()
{
    int x1,y1,x2,y2;
    printf("Enter coordinates x1 y1 x2 y2 (1..8):\n");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    if ((x1 + y1) % 2 == (x2 + y2) % 2)
    {
        printf("The cells have equal color");
    }
    else
    {
        printf("The cells have non equal color");
    }

    return 0;
}

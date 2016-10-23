#include <stdio.h>

int main()
{
    float s=0;
    int n,c=0;
    do {
        printf("Enter number: ");
        scanf("%d", &n);
        if (n > 0 && (n % 10 == 8)) { // n % 2 == 0 is excess check
            s +=  n;
            c++;
        }
    } while (n != 0);
    if (c > 0) printf("The average is %f", s/c);
    return 0;
}

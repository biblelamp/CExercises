#include <stdio.h>

int bin_to_dec(long b)
{
    int result=0,t=1;
    while(b > 0)
    {
        int d = b % 10;
        //printf("%d %d\n", d, t);
        result += d*t;
        b /= 10;
        t *= 2;
    }
    return result;
}

int main()
{
    long b;
    printf("Enter the binary use only 1 or 0:\n");
    scanf("%ld", &b);
    printf("It's %d in the decimal system", bin_to_dec(b));
    return 0;
}

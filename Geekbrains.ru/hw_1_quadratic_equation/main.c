#include <stdio.h>

int main()
{
    float a,b,c,x;
    printf("Enter a b c:\n");
    scanf("%f %f %f", &a, &b, &c);

    if((b*b - 4*a*c) >= 0)
    {
        x = (-1*b + sqrt(b*b - 4*a*c)) / (2 * a);
        printf("First root is %f!\n", x);
        x = (-1*b - sqrt(b*b - 4*a*c)) / (2 * a);
        printf("Second root is %f!\n", x);
    }
    else
    {
        printf("The discriminant is less 0, the roots are immaterial\n");
    }
    return 0;
}

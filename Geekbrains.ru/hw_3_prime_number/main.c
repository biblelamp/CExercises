#include <stdio.h>
#include <math.h>

int is_prime(int a)
{
    for(int i = 2; i<= sqrt(a); i++)
    {
        if(a % i == 0) return 0;
    }
    return 1;
}

int main()
{
    int a;
    printf("Enter the number: ");
    scanf("%d", &a);
    if(is_prime(a)) printf("It's a prime number");
    else printf("It's NOT a prime number");
    return 0;
}

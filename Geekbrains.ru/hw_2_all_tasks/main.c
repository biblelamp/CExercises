#include <stdio.h>
#include <time.h>

/* Geekbrains.ru
 * Course name: Algorithms and Data Structures
 * Homework 2, performed by Sergey Iryupin, October 24, 2016
 */

void Menu();
void Task1();
void Task2();
void Task3();
void Task4();
float max_out_three(float a, float b, float c);
void Task5();
int random(int range, int x);
void Task6();

int main()
{
    int i=0;
    do
    {
        Menu();
        scanf("%d", &i);
        switch(i)
        {
            case 1: Task1();
                break;
            case 2: Task2();
                break;
            case 3: Task3();
                break;
            case 4: Task4();
                break;
            case 5: Task5();
                break;
            case 6: Task6();
                break;
            case 0: printf("The end.\n");
                break;
            default: printf("Wrong number, try again\n");
        }
    }
    while(i != 0);
    return 0;
}

void Menu()
{
    printf("1. Squares and cubes\n");
    printf("2. Result of division, and residue\n");
    printf("3. Analysis of the number of digits\n");
    printf("4. Average with a complex condition\n");
    printf("5. Maximum out three numbers\n");
    printf("6. Random number generator\n");
    printf("0. Exit\n: ");
}

void Task1() // squares and cubes
{
    int a,b;
    printf("Enter values for A and B:\n");
    scanf("%d %d", &a, &b);
    for (int i=a; i<=b; i++) printf("%d - %d - %d\n", i, i*i, i*i*i);
}

void Task2() // result of division, and residue
{
    int n,k,i;
    printf("Enter values for N and K:\n");
    scanf("%d %d", &n, &k);
    i = 0;
    while (n>k) {
        n -= k;
        i++;
    }
    printf("Result of the division is %d and the residue is %d.\n", i, n);
}

void Task3() // analysis of the number of digits
{
    int n,d,f;
    printf("Enter value for N: ");
    scanf("%d", &n);
    f = 0;
    do {
        d = n % 10;
        n /= 10;
        if (d % 2 > 0) f++;
    } while (n>0);
    printf("%s\n", (f == 0)? "False" : "True");
}

void Task4() // average with a complex condition
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
    if (c > 0) printf("The average is %f\n", s/c);
}

float max_out_three(float a, float b, float c) // to find maximum of three numbers
{
    if (a > b && a > c) return a;
    if (b > a && b > c) return b;
    return c;
}

void Task5()  // maximum out three numbers
{
    float a,b,c;
    printf("Enter value for A B and C:\n");
    scanf("%f %f %f", &a, &b, &c);
    printf("%f", max_out_three(a, b, c));
}

int random(int range, int x) // simple random function
{
    int a=438, b=153;
    return (a*x + b) % range;
}

void Task6() { // random number generator
    unsigned long t=time(NULL);
    int x=t % 1000;
    int range=100,n;
    printf("Enter the number of random numbers: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        x = random(range, x);
        printf("%d ", x);
    }
    printf("\n");
}

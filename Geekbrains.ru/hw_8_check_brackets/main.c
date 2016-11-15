#include <stdio.h>

int len(char * str) // like function strlen
{
    int i = 0;
    while(str[i] != '\0') i++;
    return i;
}

int main()
{
    char string[80];
    int count=0;
    puts("Enter the expression with () brackets:");
    gets(string);
    for (int i = 0; i < len(string); i++)
    {
        if (string[i] == '(') count++;
        if (string[i] == ')')
        {
            count--;
            if (count < 0) break;
        }
    }
    if (count == 0)
        puts("No error in the expression.");
    else
        puts("The expression has error(s).");
    return 0;
}

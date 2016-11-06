#include <stdio.h>

int len(char * str) // like function strlen
{
    int i = 0;
    while(str[i] != '\0') i++;
    return i;
}

int getCharPosition(char * str, char ch)
{
    for(int i = 0; i < len(str); i++)
        if (str[i] == ch) return i;
    return -1;
}

int isStringPermutationAnother(char * str1, char * str2)
{
    int p;
    if (len(str1) != len(str2)) return 0;
    for(int i = 0; i < len(str1); i++)
    {
        //p = getCharPosition(str2, str1[i]);
        if ((p = getCharPosition(str2, str1[i])) == -1) return 0;
        str2[p] = '\n';
    }
    return 1;
}

int main(int argc, char *argv[])
{
    char buf1[128];
    char buf2[128];
    char * str1;
    char * str2;

    if (argc > 2)
    {
        str1 = argv[1];
        str2 = argv[2];
        printf("First string is '%s'\nSecond string is '%s'\n", str1, str2);
    }
    else
    {
        str1 = buf1;
        str2 = buf2;
        puts("Input string 1:");
        gets(str1);
        puts("Input string 2:");
        gets(str2);
    }
    if (isStringPermutationAnother(str1, str2))
        puts("We can get one string from the other by a permutation of symbols.");
    else
        puts("We can't get one string from the other by a permutation of symbols.");
    return 0;
}

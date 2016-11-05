#include <stdio.h>
#include <string.h>

int len(char * str) // like function strlen
{
    int i = 0;
    while(str[i] != '\0') i++;
    return i;
}

int countChr(char * str, char ch) // how many times has this character in string
{
    int counter=0;
    for(int i = 0; i < len(str); i++)
        if (str[i] == ch) counter++;
    return counter;
}

int isVowel(char ch) // this is a vowel letter?
{
    char * vovel = "aeiouAEIOU";
    if (countChr(vovel, ch) > 0) return 1;
    else return 0;
}

int isVovelInStr(char * str) // if the vowels in a string?
{
    for(int i = 0; i < len(str); i++)
        if (isVowel(str[i])) return 1;
    return 0;
}

char mostFrequentVowel(char * str)
{
    char result='\0';
    int count=0;
    for(int i = 0; i < len(str); i++)
        if (isVowel(str[i]))
        {
                int often = countChr(str, str[i]);
                if (often > count)
                {
                    result = str[i];
                    count = often;
                }
        }
    return result;
}

int main(int argc, char *argv[])
{
    char ch;
    char buffer[80];
    char *string;
    if (argc > 2)
    {
        string = argv[1];
        ch = (char) argv[2][0];
        printf("String '%s' symbol '%c'\n", string, ch);
    }
    else
    {
        string = buffer;
        puts("Input string:");
        gets(string);
        printf("Input char: ");
        scanf("%c", &ch);
    }
    printf("Symbol '%c' occurs %d time(s) in getting string.\n", ch, countChr(string, ch));
    if (isVovelInStr(string))
        printf("Getting string has vovel letter(s).\n");
    else
        printf("Getting string doesn't have vovel letter(s).\n");
    ch = mostFrequentVowel(string);
    if (ch =='\0')
        printf("The most frequent vowel is not.\n");
    else
        printf("The most frequent vowel in a string is '%c'.\n", ch);
    return 0;
}

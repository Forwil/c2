#include <stdio.h>
char *strc(char *str1, char *str2);
main()
{
    char s1[80] = "computer", s2[] = "language", *pt;
    pt = strc(s1, s2);
    printf("%s\n", pt);
}
char *strc(char *str1, char *str2)
{
    char *p;
    for (p = str1; *p != '\0'; p++);
    do {
        *p++ = *str2++;
    } while(*str2 != '\0');
    *p = '\0';
    return (str1);
}

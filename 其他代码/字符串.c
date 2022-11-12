#include <stdio.h>
#include <string.h>

int main()
{
    char str0[] = {'H', 'e', 'l', 'l', 'o'};
    printf("%s\n", str0);
    printf("%d\n", strlen(str0));
    printf("%d\n", sizeof(str0));

    char str[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    printf("%s\n", str);
    printf("%d\n", strlen(str));
    printf("%d\n", sizeof(str));

    char str1[] = "Hello";
    printf("%s\n", str1);
    printf("%d\n", strlen(str1));
    printf("%d\n", sizeof(str1));

    char *str2 = "Hello";
    printf("%c\n", *str2);

    char b = "abc"[0];
    printf("%c\n", b);

    char c = *("123" + 1);
    printf("%d\n", c);

    char t = *" ";
    printf("%c\n", t);

    return 0;
}
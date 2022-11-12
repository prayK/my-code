#include <stdio.h>
#include <malloc.h>
#include <string.h>

char *result(const char *src, int len, int offset)
{
    char *ret = (char *)malloc(sizeof(char) * len);

    for (int i = 0; i < len; i++)
    {
        ret[(i + offset) % 5] = src[i];
        //printf("%c\n", ret[i]);
    }

    return ret;
}

void Free(char *result)
{
    free(result);
}

int main()
{
    char *str = "Hello";

    for (int i = 0; i < strlen(str); i++)
        printf("%c ", str[i]);

    printf("\n");
    char *res = result(str, strlen(str), 3);

    for (int i = 0; i < strlen(str); i++)
        printf("%c ", res[i]);

    Free(res);

    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isValid(char *s)
{
    char stack[10000] = {0};
    int Len = strlen(s);

    for(int i=0,j=0; i<Len; i++,j++)
    {
        if((s[i] == '(') || (s[i] == '[') || (s[i] == '{'))
        {
            stack[j] = s[i];
        }

        if(s[i] == ')')
        {
            if((j-1>=0) && (stack[j-1] == '('))
            {
                stack[j-1] = '0';
                j-=2;
            }else return false;
        }
        if(s[i] == ']')
        {
            if((j-1>=0) && (stack[j-1] == '['))
            {
                stack[j-1] = '0';
                j-=2;
            }else return false;
        }
        if(s[i] == '}')
        {
            if((j-1>=0) && (stack[j-1] == '{'))
            {
                stack[j-1] = '0';
                j-=2;
            }
            else return false;
        }
    }
    for(int i=0; i<10000; i++)
    {
        if((stack[i] == '(') || (stack[i] == '[') || (stack[i] == '{')
         ||(stack[i] == ')') || (stack[i] == ']') || (stack[i] == '}'))
        {
            return false;
        }
    }
    return true;
}

int main(void)
{
    char stack[100] = "]";

    bool b = isValid(stack);

    printf("%d", b);

    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(int x)
{
    if(x < 0)
    {
        return false;
    }
    if(x == 0)
    {
        return true;
    }

    int Stroage = x;//转存x的值
    long Result = 0;

    while(x > 0)
    {
        int Temp = x % 10;
        Result = Result * 10 + Temp;
        x = x / 10; //迭代
    }
    //printf("%d\n", Result);

    if(Result == Stroage)
    {
        return true;
    }
    else
    {
        return false;
    }

    return true;
}


int main(void)
{
    int Num = 121;

    bool b = isPalindrome(Num);

    printf("%d", b);

    return 0;
}

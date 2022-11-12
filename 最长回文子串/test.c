#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//从长度为 n 的字符串 s 的给定位置左右扩展寻找回文串。
//输入的 left 和 right 是扩展的左右起始位置。返回扩展经过的字符数 k
int Expand(char* s, int left, int right)
{
    int k = 0;

    while((left >= 0 ) && ( right < strlen(s)))
    {
        if(s[left] == s[right])
        {
            right++;
            left--;
            k++;
        }
        else
        {
            break;
        }
    }
    return k;
}


char * longestPalindrome(char * s)
{
    if(strlen(s) <= 0)
    {
        return NULL;
    }
    int MaxLen = 1;
    int MaxNum = 0;

    for(int i=0; i<strlen(s); i++)
    {
        int k1 = Expand(s, i - 1, i + 1);  //奇数状况
        int k2 = Expand(s, i, i + 1);      //偶数状况

        int length1 = k1 * 2 + 1;   //奇数状况下的长度
        int length2 = k2 * 2;       //偶数状况下的长度

        if(length1 > MaxLen)
        {
            MaxLen = length1;
            MaxNum = (i - (MaxLen - 1) / 2);
        }
        if(length2 > MaxLen)
        {
            MaxLen = length2;
            MaxNum = (1 + i - MaxLen / 2);
        }
    }
    //printf("%d\n", MaxLen);
    char* Result = (char*)malloc(sizeof(char) * MaxLen);

    for(int i=0; i<MaxLen; i++)
    {
        Result[i] = s[MaxNum + i];
    }
    Result[MaxLen]  = '\0';

    return Result;
}

int main()
{
    char* str = "efabcbagr";
    char* res = longestPalindrome(str);

    for(int i=0; i<strlen(res); i++)
    {
        printf("%c", res[i]);
    }

    return 0;
}

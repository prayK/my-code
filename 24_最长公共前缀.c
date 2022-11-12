#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *longestCommonPrefix(char **strs, int strsSize)
{
    if ((strsSize == 0) || (strlen(strs[0]) == 0))
        return "";
    if (strsSize == 1)
        return strs[0];

    int MaxLen = 0;
    char *Result = (char *)malloc(sizeof(char) * (201));

    for (int i = 0; i < strlen(strs[0]); i++)
    {
        int j = 1;
        for (; j < strsSize; j++)
        {
            if (strs[0][i] != strs[j][i])
            {
                break;
            }
        }
        if (j == strsSize)
        {
            Result[i] = strs[0][i];
            Result[i + 1] = '\0';
        }
        else
        {
            Result[i] = '\0';
            break;
        }
    }

    return Result;
}

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if(strs.size() == 0)
        {
            return "";
        }
        if(strs.size() == 1)
        {
            return strs[0];
        }
        stable_sort(strs.begin(), strs.end());
        string res;
        string s1 = strs.front();
        string s2 = strs.back();

        for(int i = 0; i < s1.size() && i < s2.size(); ++i)
        {
            if(s1[i] != s2[i])
            {
                break;
            }
            res += s1[i];
        }
        return res;
    }
};

int main()
{
    char *str[4] = {"flower","flower","flower","flower"};
    char **s = &str[0];
    char *Res = longestCommonPrefix(s, 4);

    for (int i = 0; i < strlen(str[0]); i++)
    {
        printf("%c", Res[i]);
    }

    return 0;
}

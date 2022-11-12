#include <stdio.h>
#include <String.h>

int lengthOfLongestSubstring(char *s)
{
    if(s == NULL)
    {
        return 0;
    }
    int Len = strlen(s);

    int count = 0;          /* 子串当前长度 */
    int max = 0;            /* 子串最大长度 */
    int start = 0;          /* 子串起始位置 */
    int index[128] = {0};   /* 记录每个字符先后出现位置 */
    int end = 0;            /* 子串结束位置 */

    for(; end<Len; end++)
    {
        //若为真,例如"abc",对应hash为: a:0,b:1,c:2,如果start小于index，说明字符s[i]在之前重复出现过(位置被改变了)。
        if(index[s[end]] > start)
        {
            count = end - start;            //记录此时子串的长度
            max = count > max ? count : max;//若当前子串大于先前记录的最大字串长度，则更新max
            start = index[s[end]];          //更新新子串的起始位置
        }
        index[s[end]] = end + 1;            //记录字符s[i]在整个字符串中出现的位置
    }
    count = end - start;                    //计算最后一个子串的长度

    return count > max ? count : max;
}

int main(void)
{
    char str[100] = "abcabcbb";
    int Maxlen = lengthOfLongestSubstring(str);

    printf("%d\n", Maxlen);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
         if((s.size() == 0) || (s.size() == 1))
            return s.size();

        int hashmap[128];
        int left = 0;
        int maxlen = 0;

        for(int right = 0; right < s.size(); ++right)
        {
            hashmap[s[right]]++;
            while(hashmap[s[right]] > 1)
            {
                hashmap[s[left]]--;
                left++;
            }
            maxlen = ((right - left + 1) > maxlen) ? (right - left + 1) : maxlen;
        }
        return maxlen;
    }
};
int main(void)
{
    string str = "bbbbb";
    Solution MySolution;
    int Maxlen = MySolution.lengthOfLongestSubstring(str);

    cout << Maxlen << endl;

    return 0;
}


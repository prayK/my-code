#include <bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    int countSubstrings(string s) 
    {
        int result = 0;
        for(int i = 0; i < s.size(); i++) 
        {
            result += extend(s, i, i);      // 以i为中心
            result += extend(s, i, i + 1);  // 以i和i+1为中心
        }
        return result;
    }
    int extend(const string& s, int left, int right) 
    {
        int res = 0;
        while (left >= 0 && right < s.size() && s[left] == s[right]) 
        {
            left--;
            right++;
            res++;
        }
        return res;
    }
};

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.empty() == 1)
        {
            return "";
        }
        int length = s.size();
        if (length == 1)
        {
            return s;
        }
        vector<vector<int>> dp(length, vector<int>(length));
        string Result;

        for (int i = 0; i < length; i++)
        {
            dp[i][i] = 1;
            for (int j = i; j < length; j++)
            {
                dp[i][j] = 0;
            }
        }

        for (int strlen = 0; strlen < length; strlen++) //区间长度遍历
        {
            for (int i = 0; i + strlen < length; i++) //回文串区间左端点遍历
            {
                int j = i + strlen; //回文串区间右端点为左端点加上区间长度

                if (strlen == 0) //最长回文子串长度为1时，肯定是回文串
                {
                    dp[i][j] = 1;
                }
                else if (strlen == 1) //最长回文子串长度为1时,判断一下即可
                {
                    dp[i][j] = (s[i] == s[j]);
                }
                else
                {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]); //状态转移方程
                }

                //对结果的更新
                if (dp[i][j] && strlen + 1 > Result.size())
                {
                    Result = s.substr(i, strlen + 1);
                }
            }
        }
        return Result;
    }
};

int main()
{
    Solution s;
    string res = s.longestPalindrome("babad");

    cout << res << endl;

    return 0;
}
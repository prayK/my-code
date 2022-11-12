#include <bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    long long ConVertDec2Bin(int a)//十进制转二进制
    {
        long long bin = 0;  //返回值变量
        int n = a;          //参数  
        int re = 0;         //余数
        int i = 1;          //余数
        while (n != 0)
        {
            re = n % 2;     //n取余
            n >>= 1;        //取整
            bin += re * i;
            i *= 10;
        }
        return bin;
    }
    long long ConVerBin2Dec(string input)
    {
        int j = 0;
        int res = 0;
        for(int i = input.size() - 1; i >= 0; --i)
        {
            if(input[i] != '0' && input[i] != '1')
            {
                return 0;
            }
            else
            {
                res += (input[i] - '0') * (2 << j);
            }
            ++j;
        }
        res >>= 1;
        return res;
    }
};

int main()
{
    Solution MySolution;
    cout << MySolution.ConVerBin2Dec("1110") << endl;
    return 0;
}
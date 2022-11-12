#include <bits/stdc++.h>

using namespace std;

class Solution 
{
public:
    int romanToInt(string s) 
    {
        int sum = 0;

        for(int i = 0; i < s.size(); ++i)
        {
            if((s[i] == 'I') && (i + 1 < s.size()) && (s[i+1] == 'V'))//4
            {
                sum += 4;
                i++; 
                continue;
            }
            if((s[i] == 'I') && (i + 1 < s.size()) && (s[i+1] == 'X'))//9
            {
                sum += 9;
                i++; 
                continue;
            }
            if((s[i] == 'X') && (i + 1 < s.size()) && (s[i+1] == 'L'))//40
            {
                sum += 40;
                i++; 
                continue;
            }
            if((s[i] == 'X') && (i + 1 < s.size()) && (s[i+1] == 'C'))//90
            {
                sum += 90;
                i++; 
                continue;
            }
            if((s[i] == 'C') && (i + 1 < s.size()) && (s[i+1] == 'D'))//400
            {
                sum += 400;
                i++;
                continue;
            }
            if((s[i] == 'C') && (i + 1 < s.size()) && (s[i+1] == 'M'))//900
            {
                sum += 900;
                i++;
                continue;
            }
            else
            {
                switch(s[i])
                {
                    case 'I': sum += 1; break;
                    case 'V': sum += 5; break;
                    case 'X': sum += 10; break;
                    case 'L': sum += 50; break;
                    case 'C': sum += 100; break;
                    case 'D': sum += 500; break;
                    case 'M': sum += 1000; break;
                    default: break;
                }
            }
        }
        return sum;
    }
};

int main(void)
{
    string stack = "MCMXCIV";
    Solution MySolution;

    int b = MySolution.romanToInt(stack);
    cout << b << endl;

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s1 = "we;tonight;you";
    stack<char> s2;
    string res;
    for(unsigned int i = 0; i < s1.size(); ++i)
    {
        if(s1[i] != ';')
        {
            s2.push(s1[i]);
        }
        else
        {
            while(s2.empty() == false)
            {
                res.push_back(s2.top());
                s2.pop();
            }
            res.push_back(';');
        }
    }
    while(s2.empty() == false)
    {
        res.push_back(s2.top());
        s2.pop();
    }
    res.push_back(';');

    cout << res << endl;

    return 0;
}
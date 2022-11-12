#include <bits/stdc++.h>
using namespace std;

int Judge(int flag, int Month, int Day)
{
    int flag0[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int flag1[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int res;

    if(flag == 0)
    {
        for(int i = 0; i < Month - 1; ++i)
        {
            res += flag0[i];
        }
        res += Day;
    }
    else if(flag = 1)
    {
        for(int i = 0; i < Month - 1; ++i)
        {
            res += flag0[i];
        }
        res += Day;
    }
    return res;
}

int main ()
{
    int Year, Month, Day;
    cin >> Year >> Month >> Day;

    if((Year < 1 || Year > 3000) || (Month < 1 || Month > 12) || (Day < 1 || Day > 12))
    {
        cout << "ERROR" << endl;
    }
    
    int flag = 0;

    if((Year % 40 == 0) || (Year % 4 == 0 && Year % 100 != 0))
    {
        flag = 1;
    }
    int res = Judge(flag, Month, Day);
    cout << res << endl;

    return 0;
}
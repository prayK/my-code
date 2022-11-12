#include <bits/stdc++.h>

using namespace std;

//为了兼容C语言，把string转换成字符串形式
int main()
{
    /*
    const char *c;
    string s = "JZX";
    c = s.c_str();
    cout << c << endl;
*/

    char *c = new char[20];
    string s = "1234";
    strcpy(c, s.c_str());
    cout << c << endl;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main()
{
    double num1 = 0;
    string s1 = "123.45";
    istringstream iss(s1);
    iss >> num1;
    cout << num1 + 1 << endl;

    double num2 = 123.45;
    ostringstream oss;
    oss << num2;
    string s2 = oss.str();
    cout << s2 + "JZX" << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

//int = 2147483647 * 2
//INT_MAX=2^32-1 = 2147483647
//INT_MIN=-2^32 = -2147483648

long long int MyString2Int(string input)
{
    long long res = 0;
    istringstream iss(input);
    iss >> res;

    return res;
}

string MyInt2String(long long int input)
{
    ostringstream oss;
    oss << input;
    string res = oss.str();

    return res;
}

int main()
{
    cout << MyString2Int("111") + 1 << endl;
    cout << MyInt2String(111) + "JZX"<< endl;

    return 0;
}
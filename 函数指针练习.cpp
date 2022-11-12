#include <bits/stdc++.h>
using namespace std;

typedef int (*pFunc)(int, int);

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}


int main ()
{
    int a, b;
    cin >> a >> b;

    char c;
    cin >> c;

    pFunc p = nullptr;

    switch (c)
    {
        case '+': p = add; break;
        case '-': p = sub; break;
        default: break;
    }

    cout << p(a, b) << endl;

    return 0;
}
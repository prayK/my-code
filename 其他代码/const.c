#include <bits/stdc++.h>

using namespace std;

//CPP中的const
int main()
{
    Test t1(1, 2);
    Test t2(t1);

    cout << t2.a << endl;
    cout << *t2.b << endl;

    //    int c = 1;
    //   const int a = c;
    const int a = 1;
    int *b = const_cast<int *>(&a);
    *b = 2;
    cout << a << endl;
    cout << *b << endl;

    return 0;
}

/*
#include <stdio.h>

class Value
{
private:
    int mi;

public:
    Value(int i)
    {
        printf("i = %d\n", i);
        mi = i;
    }
    int getI()
    {
        return mi;
    }
};

class Test
{
private:
    const int ci;
    Value m2;
    Value m3;
    Value m1;

public:
    Test() : m1(1), m2(2), m3(3), ci(100)
    {
        printf("Test::Test()\n");
    }
    int getCI()
    {
        return ci;
    }
    int setCI(int v)
    {
        int *p = const_cast<int *>(&ci);

        *p = v;
    }
};

//类中的const 成员为只读变量，只能在初始化列表中初始化
int main()
{
    Test t;

    printf("t.ci = %d\n", t.getCI());

    t.setCI(10);

    printf("t.ci = %d\n", t.getCI());

    return 0;
}
*/

/*
#include <bits/stdc++.h>

using namespace std;

//int c = 1;
//const int a = c;

const int a = 1;

int main()
{
    int *b = const_cast<int*>(&a);
    *b = 2;
    cout << a << endl;
    cout << *b << endl;

    return 0;
}
*/
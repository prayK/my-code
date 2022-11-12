#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cstdlib>
#include <cstring>

using namespace std;

void ImagInit(void)
{
    cout << "void ImagInit(void)" << endl;
}

void ImagStart(void)
{
    cout << "void ImagStart(void)" << endl;
}

void ImagCollect(void)
{
    cout << "void ImagCollect(void)" << endl;
}

void ImagFinish(void)
{
    cout << "void ImagFinish(void)" << endl;
}

typedef void (*ImagFunc)(void);
ImagFunc ImagFuncArray[4] = {ImagInit, ImagStart, ImagCollect, ImagFinish};

int main()
{
    ImagFuncArray[0]();
    return 0;
}
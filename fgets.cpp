#include <bits/stdc++.h>
using namespace std;

int main()
{
    char buf[10] = {'\0'};
    //char *buf = (char*)malloc(sizeof(char) * 10);
    //char *buf = new char[10];

    fgets(buf, 10, stdin);//使用fgets而不要用gets，gets有越界风险，且接收的数据长度有限
    if(buf[strlen(buf) - 1] == '\n')
    {
        buf[strlen(buf) - 1] = '\0';//buf中最多能存9个，因为'\0'会占位一个，如果输入大于等于9，那么没有'\n'，如果小于9，那么就会有'\n'
    }
    cout << buf << endl;

    //free(buf);
    //delete [] buf;

    //buf = NULL;

    return 0;
}
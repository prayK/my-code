#include <bits/stdc++.h>
using namespace std;

#define Seconds(year) {((((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0) ? 1 : 0) + 365) * 24 * 60 * 60UL}


int main()
{
    char buf[10] = {'\0'};			//方式一
    //char *buf = (char*)malloc(sizeof(char) * 10);	//方式二
    //char *buf = new char[10];			//方式三

    scanf("%s", buf);//空格就表示输入结束
    cout << buf << endl;

    //free(buf);
    //delete [] buf;

    //buf = NULL;				//最后置空

    return 0;
}
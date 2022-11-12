/**********************递归求字符串长度*****************************/
#include <stdio.h>
int mylen(const char *str, int len)
{
    if (*str == '\n')
    {
        return len;
    }
    else
    {
        ++len;
        mylen(++str, len);
    }
}
int main(int argc, char *argv[])
{
    char *str = "JinZhaoXiang";
    int length = 0;
    printf("%d\n", mylen(str, length));

    return 0;
}
/**********************递归求字符串长度*****************************/

/**********************递归求和*****************************/
#include <stdio.h>
int SUM(const int num, int length)
{
    if (num == 0)
    {
        return length;
    }
    else
    {
        length += num;
        mylen(--num, length);
    }
}
int main(int argc, char *argv[])
{
    int length = 0;
    printf("%d\n", SUM(100, length));

    return 0;
}
/**********************递归求和*****************************/

/**********************斐波那契数列*****************************/
//1,1,2,3,5,8,13,21
#include <stdio.h>

int fac(int n)
{
    if ((n == 1) || (n == 2))
    {
        return 1;
    }
    else
    {
        return fac(n - 1) + fac(n - 2);
    }
}

int main()
{
    printf("%d\n", fac(1));
    printf("%d\n", fac(2));
    printf("%d\n", fac(9));

    return 0;
}
/**********************斐波那契数列*****************************/

/**********************汉诺塔*****************************/
#include <stdio.h>

void han_move(int n, char a, char b, char c)
{
    if (n == 1)
    {
        printf("%c --> %c\n", a, c);
    }
    else
    {
        han_move(n - 1, a, c, b);
        han_move(1, a, b, c);
        han_move(n - 1, b, a, c);
    }
}

int main()
{
    han_move(3, 'A', 'B', 'C');

    return 0;
}
/**********************汉诺塔*****************************/